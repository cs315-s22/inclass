#include <stdint.h>

#define NUM_REGS 16

#define LR 14
#define PC 15

struct arm_state {
    uint32_t regs[NUM_REGS];
    uint32_t *func;
};
