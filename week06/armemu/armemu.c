#include "armemu.h"

int add2_s(int, int);

void arm_state_init(struct arm_state *pas, uint32_t *func) {
    for (int i = 0; i < NUM_REGS; i++) {
        pas->regs[i] = 0;
    }
    pas->func = func;
}

int main(int argc, char **argv) {
    struct arm_state as;

    arm_state_init(&as, (uint32_t*) add2_s);

}
