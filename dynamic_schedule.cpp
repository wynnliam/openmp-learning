// Liam Wynn, 2/19/2020, OpenMP Learning

/*
 * To compile: g++ -fopenmp dynamic_schedule.cpp
 *
 * In this demo, I show how to specify a dynamic schedule for
 * threads.
 *
 * Now the dynamic schedule means that each thread just keeps
 * grabbing the next available chunk indepedntly until all chunks
 * are finished. This is ideal for situations where the process
 * to complete can vary in its completion time.
 *
 * In this demo, each iteration of the loop takes a random time
 * to complete. 
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int process(const int& i) {
	int time = rand();
	for(int j = 0; j < time; ++j);

	return i;
}

int main() {
	srand(time(NULL));

	#pragma omp parallel for schedule(dynamic)
	for(int i = 0; i < 10; ++i) {
		process(i);
		cout << i << " ";
	}

	cout << endl;

	// You can also specify the size of chunks.
	// In this example, each thread will do three iterations
	// of the loop before finishing chunk. The last
	// chunk may be less than three 
	#pragma omp parallel for schedule(dynamic, 3)
	for(int i = 0; i < 10; ++i) {
		process(i);
		cout << i << " ";
	}

	cout << endl;

	return 0;
}
