// Liam Wynn, 2/20/2020, OpenMP Learning

// To compile: g++ table_init.cpp -fopenmp

/*
	How to initialize a table in parallel with multiple threads.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	const int size = 256;
	double sinTable[size];

	#pragma omp parallel for
	for(int n = 0; n < size; ++n)
		sinTable[n] = std::sin(2 * M_PI * n / size);

	for(int n = 0; n < size; ++n)
		cout << n << " " << sinTable[n] << endl;
}
