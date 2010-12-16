#include <iostream>
#include <cmath>

unsigned int k_of(
        unsigned int m
      , unsigned int m_squared
      , unsigned int n
      , unsigned int n_squared
      , unsigned int k_sample_limit
      , unsigned int sum)
{
        if (n_squared >= m_squared)
	        return 0;

        unsigned int k = 1;
	unsigned int square_difference = m_squared - n_squared;
	unsigned int square_sum = m_squared + n_squared;
	unsigned int mnproduct = 2 * m * n;

	while (k != k_sample_limit) {
	        unsigned int a = k * square_difference;
		unsigned int b = k * mnproduct;
		unsigned int c = k * square_sum;

		if (a + b + c == sum)
		        return a * b * c;
		++k;
	}

	return 0;
}

unsigned int n_of(unsigned int m, unsigned int m_squared, unsigned int sum)
{
        unsigned int n_sample_limit = sum;
	unsigned int n = 2;

	while (n != n_sample_limit) {
	        if (unsigned int product = k_of(m, m_squared, n, pow(n, 2), sum, sum))
		        return product;
		++n;
	}

	return 0;
}

unsigned int m_of(unsigned int sum)
{
        unsigned int m_sample_limit = sum;
	unsigned int m = 2;

	while (m != m_sample_limit) {
		if (unsigned int product = n_of(m, pow(m, 2), sum))
		        return product;
		++m;
	}

	return 0;
}

//! finds the product of a Pythagorean triple whose sum is 'sum' via
//  Euclid's formula with 'k'
inline unsigned int find_product(unsigned int sum)
{
        //! this could be rewritten as a sequence of 3
        //  nested loops.
        return m_of(sum);
}

int main(int argc, char* argv[])
{
        std::cout<<find_product(1000)<<std::endl;
}
