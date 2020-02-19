// Liam Wynn, 2/19/2020, OpenMP Learning

/*
 * To compile: g++ -fopenmp ordered_clause.cpp
 *
 * The ordered clause can be added to parts of a loop
 * to make those parts execute in orderly fashion. The
 * following demo hopefully shows how this works.
 *
 * This simulates a file compressing + sending program.
 * Assuming the programs vary in thier size, the time it
 * takes to compress them will also vary. However, we want
 * to send the files in an orderly fashion.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int compress(const int& i) {
	int time = rand();

	for(int j = 0; j < time; ++j);

	return i;
}

void send(const int& i) {
	cout << i << " ";
}

int main() {
	srand(time(NULL));

	#pragma omp parallel for ordered schedule(dynamic)
	for(int i = 0; i < 100; ++i) {
		compress(i);

		#pragma omp ordered
		send(i);
	}

	cout << endl;

	return 0;
}
