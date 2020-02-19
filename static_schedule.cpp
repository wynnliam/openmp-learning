// Liam Wynn, 2/19/2020, OpenMP Learning 

/*
 * To compile: g++ -fopenmp static_schedule.cpp
 *
 * In this demo, I show how to specify a static schedule for the threads
 * when executing a for loop.
 *
 * A static schedule means that each thread is assigned a chunk of the
 * process to be executed. Static is great if each iteration in the
 * process is uniform in its time to complete.
 *
 * Static scheduling is the default behavior of OpenMP.
 */

#include <iostream>

using namespace std;

int main() {
	#pragma omp parallel for schedule(static)
	for(int i = 0; i < 10; ++i)
		cout << i << " ";
	cout << endl;
}
