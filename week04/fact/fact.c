#include <stdio.h>
#include <stdlib.h>

int fact_c(int);
int fact_s(int);

int main(int argc, char **argv) {
	int n = atoi(argv[1]);

	int c_result = fact_c(n);
	printf("C: %d\n", c_result);

	int s_result = fact_s(n);
	printf("Asm: %d\n", s_result);

	return 0;
}
