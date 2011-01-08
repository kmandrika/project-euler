#include <iostream>
#include <limits>
#include <cmath>

unsigned long long get_triangle_term(unsigned long long i)
{
        return i == std::numeric_limits<unsigned long long>::max() ? 0 : i * (i + 1) / 2;
}

//! brute force is fast enough
unsigned int count_divisors(unsigned long long number)
{
        unsigned int divisors = 0;
	unsigned long long bound = sqrt(number);

	for (unsigned int i = 1; i <= bound; ++i)
	        if (number % i == 0)
		        //! divisors come in pairs
		        divisors += 2;

	return divisors;
	    
}

unsigned int problem12(unsigned int divisor_count)
{
	unsigned long long candidate = 0;
	unsigned long long i = 1;

	while ((candidate = get_triangle_term(i))) {
	        if (count_divisors(candidate) > divisor_count)
		        return candidate;
		++i;
	}

	return 0;
}

int main(int argc, char* argv[])
{
        std::cout<<problem12(500)<<std::endl;
}
