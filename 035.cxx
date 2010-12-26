#include <iostream>
#include <set>
#include <cmath>

unsigned int rotate(unsigned int n)
{
        return (n % 10) * pow(10, floor(log(n) / log(10))) + n / 10;
}

bool is_circular(unsigned int prime, const std::set<unsigned int>& primes)
{
        unsigned int rotated = prime;

        while ((rotated = rotate(rotated)) != prime)
	        if (primes.find(rotated) == primes.end())
		        return false;

	return true;
}

unsigned int count_circular_primes_below(unsigned int upper_bound)
{
        unsigned int primes_list[] = { 2, 3, 5, 7 };
	unsigned int number = 11;
	unsigned int count = 0;

	std::set<unsigned int> primes(
                primes_list
	      , primes_list + sizeof primes_list / sizeof (primes_list[0])
        );

	//! guess how many primes numbers there are below
	//  'upper_bound'
	//primes.reserve(upper_bound / log(upper_bound));

	//! first generate all the primes.
	while (*primes.rbegin() <= upper_bound) {
	        unsigned int divisor_limit = sqrt(number);

		std::set<unsigned int>::const_iterator i = primes.begin();
		std::set<unsigned int>::const_iterator e = primes.end();

		while (i != e && *i <= divisor_limit)
		        if (number % *i++ == 0)
			        //! this use of goto is justified
			        goto next_number;

		primes.insert(number);

	next_number:
		number += 2;
	}

	std::set<unsigned int>::const_iterator i = primes.begin();
	std::set<unsigned int>::const_iterator e = primes.end();

	while (i != e)
	        if (is_circular(*i++, primes))
		        ++count;

	return count;
}

int main(int argc, char* argv[])
{
        std::cout<<count_circular_primes_below(1000000)<<std::endl;
}
