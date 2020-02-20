// Liam Wynn, 2/20/2020, OpenMP Learning

/*
 * To compile: g++ -fopenmp simd.cpp
 * Some operations are what we can call SIMD - 
 * Single Instruction Multiple Data. That is, we
 * perform some operation on multiple values at once
 * by the processor. This is sometimes called "vector parallelism"
 *
 * OpenMP 4.0+ adds an explicit keyword to handle such
 * cases: "simd". This demo shows a simple vector addition
 * that can be done using this command.
 */

#include <iostream>

using namespace std;

/*
 * The "__restrict__" keyword says that the pointers are the
 * only things with direct access to the objects they point to.
 * This enables the compiler to make certain optimizations. I think
 * in our case it allows us to do vector addition in a parallelized
 * form safely.
 *
 * The "declare" keyword here tells the compiler we specifically designed
 * this function to be SIMD-friendly. I think the "aligned" keyword tells
 * the system that a and b are 16-byte aligned.
 */
#pragma omp declare simd aligned(a,b:16)
void vect_add(float* __restrict__ a, float* __restrict__ b) {
	#pragma omp simd aligned(a,b:16)
	for(int n = 0; n < 20; ++n)
		a[n] += b[n];
}

int main() {
	float a[20], b[20];

	for(int i = 0; i < 20; ++i) {
		a[i] = (float)i;
		b[i] = (float)(-i);
	}

	// I don't think we need the "parallel" clause here
	// since we're simply asking the processor to use SIMD
	// instructions.
	#pragma omp simd
	for(int n = 0; n < 20; ++n)
		a[n] += b[n];

	for(int n = 0; n < 20; ++n)
		cout << a[n] << " ";
	cout << endl;

	// Reset everything for using vect_add
	for(int i = 0; i < 20; ++i) {
		a[i] = (float)i;
		b[i] = (float)(-i);
	}

	vect_add(a, b);

	for(int n = 0; n < 20; ++n)
		cout << a[n] << " ";
	cout << endl;

	return 0;
}
