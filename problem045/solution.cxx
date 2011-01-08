#include <iostream>
#include <cmath>
#include <cfloat>
#include <limits>
#include <boost/static_assert.hpp>

bool is_triangle_number(unsigned long long n)
{
        double root = (-1 + sqrt(1.0 + 8.0 * n)) / 2.0;
	return root - floor(root) < 4 * DBL_EPSILON;
}

bool is_pentagonal_number(unsigned long long n)
{
        double root = (1 + sqrt(1.0 + 24 * n)) / 6.0;
	return root - floor(root) < 4 * DBL_EPSILON;
}

unsigned long long get_hexagonal_term(unsigned int i)
{
        return i * (2 * i - 1);
}

unsigned long long find_hex_pent_tri(unsigned int n)
{
        unsigned long long hex = 0;

        while ((hex = get_hexagonal_term(n)) < std::numeric_limits<unsigned long long>::max()) {
	        if (is_triangle_number(hex) && is_pentagonal_number(hex))
		        return hex;
		++n;
	}

	return 0;
}

int main(int argc, char* argv[])
{
        BOOST_STATIC_ASSERT(sizeof (unsigned long long) == 8);

        std::cout<<find_hex_pent_tri(143 + 1)<<std::endl;
}
