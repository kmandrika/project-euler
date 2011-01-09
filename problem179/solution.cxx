#include <iostream>
#include <cmath>
#include <vector>

//! brute force is fast enough
unsigned int count_divisors(unsigned int number)
{
        unsigned int divisors = 2;
	unsigned int bound = sqrt(number);

	for (unsigned int i = 2; i <= bound; ++i)
	        if (number % i == 0)
		        divisors += 2;

	return bound * bound == number ? divisors + 1 : divisors;
}

//! for a larger bound, we can eliminate all prime number > 3 to speed
//  up the search.
unsigned int problem179()
{
        unsigned int i = 2;
	unsigned int bound = 10000000;
	unsigned int count = 0;

	unsigned int curr_count = count_divisors(i);
	unsigned int next_count = 0;

	while (i < bound) {
	        next_count = count_divisors(i + 1);

	        if (curr_count == next_count)
		        ++count;

		curr_count = next_count;
		++i;
	}

	return count;
}

int main(int argc, char* argv[])
{
        std::cout<<problem179()<<std::endl;
}
