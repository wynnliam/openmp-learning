// Liam Wynn, 2/10/2020, OpenMP Learning

// Credit: https://bisqwit.iki.fi/story/howto/openmp/


#include <complex>
#include <cstdio>

typedef std::complex<double> complex;

int mandelbrotCalculate(const complex& c, const int& maxIter) {
	// Does z = z + c until |z| >= 2 or maxIter is reached.
	// Returns the number of iterations
	complex z = c;
	int n;

	for(n = 0; n < maxIter; ++n) {
		if(std::abs(z) >= 2.0)
			break;

		z = z * z + c;
	}

	return n;
}

int main() {
	const int width = 78;
	const int height = 44;
	const int numPixels = width * height;

	const complex center(-0.7, 0);
	const complex span(2.7, -(4/3.0) * 2.7 * height / width);
	const complex begin = center - span / 2.0;
	const int maxIter = 100000;

	#pragma omp parallel for ordered schedule(dynamic)
	for(int pix = 0; pix < numPixels; ++pix) {
		const int x = pix % width;
		const int y = pix / width;

		complex c = begin + complex(x * span.real() / (width + 1.0),
					    y * span.imag() / (height + 1.0));

		int n = mandelbrotCalculate(c, maxIter);

		#pragma omp ordered
		{
			char c = ' ';
			if(n > 0) {
				static const char charset[] = ".,c8m@jawrpogOQEPGJ";
				c = charset[n % (sizeof(charset) - 1)];
			}

			std::putchar(c);
			if(x + 1 == width)
				std::puts("|");
		}
	}
}
