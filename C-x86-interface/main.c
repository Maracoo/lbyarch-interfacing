#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

extern double find_sdot_x86(double* a, double* b, int n);

/**
	This function computes for the dot product of A and B in C
*/
double find_sdot_c(double *a, double *b, int n) {
	double sdot = 0.0;
	for (int i = 0; i < n; i++) {
		sdot += a[i] * b[i];
	}
	return sdot;
}

int main() {
	// Vector Size, max range, and # of trials
	const int n = pow(2, 20);
	const int max = RAND_MAX;
	const int trials = 30;
	// Memory allocation for vectors A, B
	double* a = (double*)malloc(n * sizeof(double));
	double* b = (double*)malloc(n * sizeof(double));
	// For the return sdot
	double sdot_c, sdot_x86;
	// Stores the runtime
	clock_t start, end;
	double exe_time_c = 0.0, exe_time_x86 = 0.0;

	// Setting up A and B values
	for (int i = 0; i < n; i++) {
		a[i] = max * (double)rand()/RAND_MAX;
		b[i] = max * (double)rand()/RAND_MAX;
	}

	for (int i = 0; i < trials; i++) {
		// Call for the C function
		start = clock();
		sdot_c = find_sdot_c(a, b, n);
		end = clock();
		exe_time_c += (double)(end - start)/CLOCKS_PER_SEC;
		// Call for the x86 function
		start = clock();
		sdot_x86 = find_sdot_x86(a, b, n);
		end = clock();
		exe_time_x86 += (double)(end - start)/CLOCKS_PER_SEC;
	}

	// Average time
	exe_time_c /= trials;
	exe_time_x86 /= trials;

	// Sanity check
	printf("Computed Sdot:\n");
	printf("C: %lf x86: %lf\n", sdot_c, sdot_x86);
	// Do they match?
	printf("Accuracy: %.2f%%\n", sdot_c*100 / sdot_x86);
	// Average time
	printf("Average time:\n");
	printf("C: %lf x86: %lf\n", exe_time_c, exe_time_x86);
	// Difference in time
	printf("Time difference (C-x86): %lf\n", exe_time_c-exe_time_x86);

	free(a);
	free(b);
}