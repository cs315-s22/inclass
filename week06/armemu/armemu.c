#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "armemu.h"

int add2_s(int, int);

void arm_state_init(struct arm_state *pas, uint32_t *func,
    uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) {
    for (int i = 0; i < NUM_REGS; i++) {
        pas->regs[i] = 0;
    }
    pas->func = func;
    pas->regs[PC] = (uint32_t) func;

    pas->regs[0] = r0;
    pas->regs[1] = r1;
    pas->regs[2] = r2;
    pas->regs[3] = r3;
}

bool is_bx(uint32_t iw) {
    if (((iw >> 4) & 0x00FFFFFF) == 0x12FFF1)
        return true;
    return false;
}

void handle_bx(struct arm_state *pas, uint32_t iw) {
    uint32_t rn = iw & 0xF;
    pas->regs[PC] = pas->regs[rn];
    if (pas->regs[PC] != 0)
        pas->regs[PC] += 4;
}

bool is_dp(uint32_t iw) {
    uint32_t dp_bits = (iw >> 26) & 0b11;
    return dp_bits == 0b00;    
}

void handle_dp(struct arm_state *pas, uint32_t iw) {
    uint32_t rd = (iw >> 12) & 0b1111;
    uint32_t rn = (iw >> 16) & 0b1111;
    uint32_t rm = iw & 0b1111;
    uint32_t opcode = (iw >> 21) & 0b1111;

    if (opcode == 0b0100) {
        // add (assumes register form, i_bit == 0)
        pas->regs[rd] = pas->regs[rn] + pas->regs[rm];
    }
    pas->regs[PC] += 4;
}

void armemu_run(struct arm_state *pas) {
    while (pas->regs[PC] != 0) {
        uint32_t iw = *(uint32_t*) pas->regs[PC];
        
        if (is_bx(iw)) {
            handle_bx(pas, iw);
        } else if (is_dp(iw)) {
            handle_dp(pas, iw);
        }
    }
}

int main(int argc, char **argv) {
    struct arm_state as;

    arm_state_init(&as, (uint32_t*) add2_s, 3, 7, 0, 0);
    armemu_run(&as);
    printf("Emu: %d\n", as.regs[0]);
}
