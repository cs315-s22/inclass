#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    uint32_t base = 10;
    for (int i = 0; i < argc; i++) {
        if (!strncmp(argv[i], "-o", 2)) {
            printf("base: %d\n", atoi(argv[i + 1]));
            i++;
        }
        printf("%s\n", argv[i]);
    }
    return 0;
}
