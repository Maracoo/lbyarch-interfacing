#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

extern double find_sdot_x86(double* a, double* b, int n);

/**
	This function computes for the dot product of A and B in C
*/
double find_sdot_c(double* a, double* b, int n) {
	double sdot = 0.0;
	for (int i = 0; i < n; i++) {
		sdot += a[i] * b[i];
	}
	return sdot;
}

void calculate_sdot(int n, int max, int trials) {
	// Memory allocation for vectors A, B
	double* a = (double*)malloc(n * sizeof(double));
	double* b = (double*)malloc(n * sizeof(double));
	// Memory allocation for execution time
	double* exe_time_list_c = (double*)malloc(trials * sizeof(double));
	double* exe_time_list_x86 = (double*)malloc(trials * sizeof(double));
	// For the return sdot
	double sdot_c, sdot_x86;
	// Stores the runtime
	clock_t start, end;
	double exe_time_c = 0.0, exe_time_x86 = 0.0;

	// Setting up A and B values
	for (int i = 0; i < n; i++) {
		a[i] = max * ((double)rand() / RAND_MAX);
		b[i] = max * ((double)rand() / RAND_MAX);
	}

	for (int i = 0; i < trials; i++) {
		// Call for the C function
		start = clock();
		sdot_c = find_sdot_c(a, b, n);
		end = clock();
		exe_time_list_c[i] = (double)(end - start) / CLOCKS_PER_SEC;
		exe_time_c += exe_time_list_c[i];
	}

	for (int i = 0; i < trials; i++) {
		// Call for the x86 function
		start = clock();
		sdot_x86 = find_sdot_x86(a, b, n);
		end = clock();
		exe_time_list_x86[i] = (double)(end - start) / CLOCKS_PER_SEC;
		exe_time_x86 += exe_time_list_x86[i];
	}

	// Average time
	exe_time_c /= trials;
	exe_time_x86 /= trials;

	// Output
	printf("Vector size: 2^%d\n", (int)log2(n));

	// Print Vectors A and B (First 5 elements)
	printf("\nVectors A and B (First 10 elements):\n");
	printf("Vector A: ");
	for (int i = 0; i < 10; i++) {
		printf("%.2lf", a[i]);
		if (i < 9) {
			printf(", ");
		}
	}
	printf("\nVector B: ");
	for (int i = 0; i < 10; i++) {
		printf("%.2lf", b[i]);
		if (i < 9) {
			printf(", ");
		}
	}

	// Sanity check
	printf("\n\nComputed Sdot:\n");
	printf("C: %.2lf | x86: %.2lf\n", sdot_c, sdot_x86);

	// Do they match?
	printf("Accuracy: %.2f%%\n", sdot_c * 100 / sdot_x86);

	// Execution Time
	printf("\nExecution Time (First 10 trials):\n");
	printf("C: ");
	for (int i = 0; i < 10; i++) {
		printf("%.6lf", exe_time_list_c[i]);
		if (i < 9) {
			printf(", ");
		}
	}
	printf("\nx86: ");
	for (int i = 0; i < 10; i++) {
		printf("%.6lf", exe_time_list_x86[i]);
		if (i < 9) {
			printf(", ");
		}
	}
	// Average Execution Time
	printf("\n\nAverage Execution Time:\n");
	printf("C: %.6lf seconds | x86: %.6lf seconds\n", exe_time_c, exe_time_x86);

	// Difference in time
	printf("Time difference (C - x86): %.6lf seconds\n\n", exe_time_c - exe_time_x86);

	// Divider
	printf("--------------------------------------------------\n");

	free(a);
	free(b);

	return 0;
}

int main() {
	// Set random seed
	srand(time(NULL));
	// Vector Size, max range, and # of trials
	const int n_values[] = { pow(2, 20), pow(2, 24), pow(2, 28) };
	const int max = rand();
	const int trials = 30;
	
	for(int i = 0; i < 3; i++) {
		calculate_sdot(n_values[i], max, trials);
	}

	return 0;
}