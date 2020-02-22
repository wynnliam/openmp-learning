// Liam Wynn, 2/21/2020, OpenMP Learning

/*
 * To compile: g++ -fopenmp atomicity_demo.cpp
 *
 * Imagine a scenario where multiple threads want to read and write
 * the same value. Without somehow controlling the threads, you can
 * get data-races: a value is being written to by one thread while another
 * one reads.
 *
 * We solve this by introducing the notion of atomicity. That is, we specify that
 * a block of code is either completely ran, or not ran at all.
 *
 * In OpenMP, atomicity, like everything else, has a keyword: "atomic". There
 * are additional keywords for specifically reading and writing to values.
 * This demo only introduces basic atomicity.
 *
 * Note that modern hardware typically has special instructions for atomic operations.
 * So for simple reads and writes (add, subtract, etc) we can ask the compiler to
 * use those with the "atomic" keyword. For general atomicity (like say multiple
 * instructions), we use the "critical" keyword.
 */

#include <iostream>

using namespace std;

int main() {
	int counter = 0;

	#pragma omp parallel for
	for(int i = 0; i < 100; i++) {
		#pragma omp atomic
		counter += i;
	}

	cout << counter << endl;

	return 0;
}
