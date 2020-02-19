// Liam Wynn, 2/19/2020, OpenMP Learning

/*
 * To compile: g++ -fopenmp sections.cpp
 *
 * Suppose you had sections of code that could run
 * in parallel. You only execute these portions once
 * (that is: not in a loop). The "sections" and "section"
 * keywords handle this scenario.
 */

#include <iostream>

using namespace std;

void procedure_1() {
	cout << "We are in procedure 1!" << endl;
}

void procedure_2() {
	cout << "We are in procedure 2!" << endl;
}

void procedure_3() {
	cout << "We are in procedure 3!" << endl;
}

void procedure_4() {
	cout << " We are in procedure 4!" << endl;
}

int main() {
	/* Specifies we are doing procedures in parallel.
	Note the "parallel" keyword. Without it, we would
	only have one thread to run these processes. While
	the result is still correct, it's no different than
	a linear program */

	/* A holistic overview of this program:
	 * We open a team of threads and specify that there are
	 * several sections that can be ran in parallel. There
	 * are three sections that can be ran in parallel. The middle
	 * section has procedure_2 followed by procedure_3. This section
	 * requires the procedures be done in sequential order. */
	#pragma omp parallel sections
	{
		#pragma omp section
		{ procedure_1(); }

		#pragma omp section
		{
			procedure_2();
			procedure_3();
		}

		#pragma omp section
		{
			procedure_4();
		}
	}

	return 0;
}
