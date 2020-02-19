// Liam Wynn, 2/19/2020, OpenMP Learning

/*
 * To compile: g++ -fopenmp reduce.cpp
 *
 * In this demo, I show how to accumulate values into
 * a sum with OpenMP.
 *
 * While this is a trivial example, it's important to use
 * reduce because if we don't, we can introduce data races
 * since we are dealing with shared variables.
 */

#include <iostream>

using namespace std;

int main() {
	int sum = 0;
	#pragma omp parallel for reduction(+:sum)
	for(int i = 0; i < 1000; ++i) sum += i;

	cout << sum << endl;

	return 0;
}
