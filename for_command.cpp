// Liam Wynn, 2/13/2020, OpenMP Learning

/*
 * Demonstrates the 'for' command in openmp. Essentially
 * this will take a loop and split it into parts that each
 * thread handles. That is, each thread gets a different
 * part of the loop.
 *
 * Important note: when you first boot up program, your current
 * team of threads has only one thread in it - the master thread.
 * So if you have '#pragma omp for' without a prior '#pragma omp parallel'
 * then only one thread will handle the loop. That is, it's not parallelized!
 *
 * When you include the 'parallel' command, it will open up N threads before doing
 * the loop. However, note that the order the commands process is dependent on
 * which threads finish first!
 *
 * To compile:
 * g++ -fopenmp for_command.cpp
 */

#include <cstdio>

using namespace std;

int main() {
	printf("TEST 1: Basic for loop print\n");
	#pragma omp for
	for(int i = 0; i < 10; ++i) {
		printf(" %d", i);
	}
	printf(".\n");

	printf("TEST 2: Adding the parallel command\n");
	#pragma omp parallel
	{
		#pragma omp for
		for(int i = 0; i < 10; ++i) {
			printf(" %d", i);
		}
	}
	printf(".\n");

	printf("TEST 3: Short-hand way of doing what TEST 2 did\n");
	#pragma omp parallel for
	for(int i = 0; i < 10; ++i) printf(" %d", i);
	printf(".\n");
}
