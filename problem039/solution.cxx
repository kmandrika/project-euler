#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

struct triplet_t {
        unsigned int a;
        unsigned int b;
        unsigned int c;

        bool operator ==(const triplet_t& rhs) const {
	        return
		        (a == rhs.a || a == rhs.b || a == rhs.c) &&
		        (b == rhs.a || b == rhs.b || b == rhs.c) &&
		        (c == rhs.a || c == rhs.b || c == rhs.c);
	}
};

void k_of(
        unsigned int m
      , unsigned int m_squared
      , unsigned int n
      , unsigned int n_squared
      , unsigned int k_sample_limit
      , unsigned int* p)
{
        if (n_squared >= m_squared)
	        return;

	//! Can't use a set since it isn't easy to compare two triplets
	//  for anything but equality. This is fast enough though.
	static std::vector<triplet_t> triplets;

        unsigned int k = 1;
	unsigned int square_difference = m_squared - n_squared;
	unsigned int square_sum = m_squared + n_squared;
	unsigned int mnproduct = 2 * m * n;

	while (k != k_sample_limit) {
	        unsigned int a = k * square_difference;
		unsigned int b = k * mnproduct;
		unsigned int c = k * square_sum;

		triplet_t triplet = { a, b, c };

		if (std::find(triplets.begin(), triplets.end(), triplet) == triplets.end()) {
		        triplets.push_back(triplet);

			if (a + b + c <= 1000)
			        ++p[a + b + c];
		}
		++k;
	}
}

void n_of(unsigned int m, unsigned int m_squared, unsigned int* p)
{
        unsigned int n_sample_limit = 50;
	unsigned int n = 1;

	while (n != n_sample_limit) {
	        k_of(m, m_squared, n, pow(n, 2), 50, p);
		++n;
	}
}

void m_of(unsigned int* p)
{
        unsigned int m_sample_limit = 50;
	unsigned int m = 1;

	while (m != m_sample_limit) {
	        n_of(m, pow(m, 2), p);
		++m;
	}
}

//! This is the lazy way of solving this problem. Most of this
//  code was stolen from problem 9's solution.
unsigned int problem39()
{
        unsigned int p[1000 + 1] = { 0 };
	unsigned int i = 3 + 4 + 5;
	unsigned int max_value = 0;
	unsigned int max_p = 0;

	m_of(p);

	while (i <= 1000) {
	        if (p[i] > max_value) {
		        max_value = p[i];
			max_p = i;
		}

		++i;
	}

	return max_p;
}

int main(int argc, char* argv[])
{
        std::cout<<problem39()<<std::endl;
}
