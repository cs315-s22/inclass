#include <stdio.h>
#include <stdlib.h>

int add2_c(int, int);
int add2_s(int, int);

int main(int argc, char **argv) {

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    int c_result = add2_c(a, b);
    int s_result = add2_s(a, b);

    printf("C: %d, Asm: %d\n", c_result, s_result);
    
    return 0;
}
