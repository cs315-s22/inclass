#include <stdint.h>

#define NUM_REGS 16

struct arm_state {
    uint32_t regs[NUM_REGS];
    uint32_t *func;
};
