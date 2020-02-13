// Liam Wynn, 2/13/2020, OpenMP Learning

/*
 * In the following program, we demonstrate the 'parallel' command
 * in OpenMP. The 'parallel' command will open up N threads to execute
 * a block of code. N is determined by the number of cores afforded
 * by your CPU.
 *
 * In this program, we print "Hello, World!" using this command.
 *
 * You will notice that it prints this multiple times. Why is this
 * the case? It is because each thread is running your code and printing!
 * On my computer, I've got eight cores. So I see "Hello, World" eight
 * times.
 *
 * To compile:
 * g++ -fopenmp parallel_command.cpp
 */

#include <iostream>

using namespace std;

int main() {
	#pragma omp parallel
	{
		/*
		 * Sometimes, the code will print all the endlines
		 * after the "Hello, World" part. I think this is
		 * because the endl is seperated from the rest
		 * of the string, so it's treated like two different
		 * operations. Due to how multithreading works,
		 * these operations from each thread can overlap.
		 */
		cout << "Hello, World!" << endl;
	}

	cout << "\nTEST TWO\n" << endl;

	#pragma omp parallel
	{
		/*
		 * By putting the \n in the string itself,
		 * we can get the atomicity of the print statements
		 * the first test lacks. Quite an edifying experiment!
		 */
		cout << "Hello, World!\n";
	}

	return 0;
}
