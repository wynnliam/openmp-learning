// Liam Wynn, 2/13/2020, OpenMP Learning

/*
 * This is a small demo of the if(parallelism_enabled) command.
 * If your system can support parallelism, it will run the operation
 * in parallel. Otherwise, it will carry on as normal.
 *
 * To compile:
 * g++ -fopenmp if_parallelism.cpp
 */

#include <iostream>

using namespace std;

int main() {
	extern int parallelism_enabled;
	#pragma omp parallel for if(parallelism_enabled)
	for(int i = 0; i < 10; i++)
		cout << i << endl;
}
