// Liam Wynn, 2/19/2020, OpenMP Learning

/*
 * To compile: g++ -fopenmp collapse.cpp
 *
 * Demonstrates how to use the "collapse" keyword. This is used
 * in cases where you have nested loops.
 */

#include <iostream>

using namespace std;

void tick(const int& x, const int& y) {
	cout << " (" << x << ", " << y << ")";
}

int main() {
	#pragma omp parallel for collapse(2)
	for(int y = 0; y < 15; ++y) {
		for(int x = 0; x < 10; x++) {
			tick(x, y);
		}
	}

	cout << endl;

	return 0;
}
