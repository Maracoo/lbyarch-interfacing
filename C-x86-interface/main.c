#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	// Vector Size
	const int n = pow(2, 2);
	// Max range
	const int max = 5;
	// Memory allocation for vectors A, B
	double* a = (double*)malloc(n * sizeof(double));
	double* b = (double*)malloc(n * sizeof(double));
	// For the return sdot
	double sdot_c, s_dot_x86;

	// Setting up A and B values
	for (int i = 0; i < n; i++) {
		a[i] = max * (double)rand()/RAND_MAX;
		b[i] = max * (double)rand()/RAND_MAX;
	}

	free(a);
	free(b);
}