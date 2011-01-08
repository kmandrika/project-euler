#include <iostream>
#include <limits>
#include <map>

typedef std::map<unsigned int, unsigned int> cache_t;

unsigned int sum_of_factorial_of_digits(unsigned int number, cache_t& cache)
{
        static const unsigned int factorial_table[] = {
	        1
	      , 1
	      , 2
	      , 3 * 2
	      , 4 * 3 * 2
	      , 5 * 4 * 3 * 2
	      , 6 * 5 * 4 * 3 * 2
	      , 7 * 6 * 5 * 4 * 3 * 2
	      , 8 * 7 * 6 * 5 * 4 * 3 * 2
	      , 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2
	};

        unsigned int sum = 0;
	unsigned int upper_bound = number;

	cache_t::const_iterator i;

        while (number != 0) {
	        if ((i = cache.find(number)) != cache.end())
		        return cache[upper_bound] = sum + i->second;

	        sum += factorial_table[number % 10];
		number /= 10;
	}

	return cache[upper_bound] = sum;
}

//! this can be done significantly faster via a factorial table
//  and std::next_permutation on a variable number of digits,
//  but this is good enough.
unsigned int problem34(unsigned int upper_bound = 100000)
{
        unsigned int sum = 0;
        unsigned int i = 3;

	cache_t cache;

	while (i != upper_bound) {
	        if (sum_of_factorial_of_digits(i, cache) == i)
		        sum += i;
		++i;
	}

	return sum;
}

int main(int argc, char* argv[])
{
        std::cout<<problem34()<<std::endl;
}
