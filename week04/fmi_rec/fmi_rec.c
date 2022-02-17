#include <stdio.h>
#include <stdlib.h>

int fmi_rec_c(int*, int, int, int);
int fmi_rec_s(int*, int, int, int);

int main(int argc, char **argv) {
    int arr[4] = {10, 2, 3, 40};
    int len = 4;
    
    int c_result = fmi_rec_c(arr, len, 1, 0);
    printf("C: %d\n", c_result);

    int s_result = fmi_rec_s(arr, len, 1, 0);
    printf("Asm: %d\n", s_result);
    
    return 0;
}
