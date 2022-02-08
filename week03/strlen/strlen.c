#include <stdio.h>

int strlen_c(char*);
int strlen_s(char*);

int main(int argc, char **argv) {
    int c_len = strlen_c(argv[1]);
    int s_len = strlen_s(argv[1]);
    printf("C: %d\nAsm: %d\n", c_len, s_len);
}
