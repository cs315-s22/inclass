#include <stdlib.h>

void c_loop(int);
void s_loop(int);

int main(int argc, char **argv) {
    int iters = atoi(argv[1]);
    c_loop(iters);
    s_loop(iters);
    return 0;
}
