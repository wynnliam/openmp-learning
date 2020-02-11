// Liam Wynn, 2/10/2020, OpenMP Learning

// To compile: g++ table_init_simd.cpp -fopenmp

// Initializes a sin table on a single thread with multiple
// data streams (vectorization)

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	const int size = 256;
	double sinTable[size];

	#pragma omp simd
	for(int n = 0; n < size; ++n)
		sinTable[n] = std::sin(2 * M_PI * n / size);

	for(int n = 0; n < size; ++n)
		cout << n << " " << sinTable[n] << endl;
	
}
