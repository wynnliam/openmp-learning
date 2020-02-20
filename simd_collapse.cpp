// Liam Wynn, 2/20/2020, OpenMP Learning

/*
 * To compile: g++ -fopenmp simd_collapse.cpp
 *
 * The collapse clause can be used with SIMD to handle nested loops.
 * In this demo, we show how to use it for a quick matrix transpose
 * operation.
 */

#include <iostream>

using namespace std;

int main() {
	int a[16], b[16];

	for(int n = 0; n < 16; ++n) {
		a[n] = 0;
		b[n] = n;
	}

	#pragma omp simd collapse(2)
	for(int i = 0; i < 4; ++i) {
		for(int j = 0; j < 4; ++j) {
			a[j * 4 + i] = b[i * 4 + j];
		}
	}

	for(int n = 0; n < 16; ++n) {
		cout << a[n] << " ";
	}

	cout << endl;

	return 0;
}
