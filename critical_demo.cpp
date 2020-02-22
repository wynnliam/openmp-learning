// Liam Wynn, 2/21/2020, OpenMP Learning

/*
 * To compile: g++ -fopenmp critical_demo.cpp
 *
 * Demos basic critical operation in OpenMP. A critical opertation
 * is still atomic, but is for general blocks of code.
 */

#include <iostream>

using namespace std;

void do_print(const int& i) {
	for(int j = 0; j < 5; ++j)
		cout << " " << i;
	cout << endl;
}

int main() {
	#pragma omp parallel for
	for(int i = 0; i < 10; ++i) {
		#pragma omp critical
		do_print(i);
	}
	return 0;
}
