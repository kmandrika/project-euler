#include <iostream>
#include <vector>
#include <cmath>

unsigned long long sum_of_primes_below(unsigned int value)
{
        unsigned int primes_list[] = { 2, 3, 5, 7, 11, 13, 17, 19 };
	unsigned int n = 23;

	unsigned long long sum = 77; // sum of primes_list

	std::vector<unsigned int> primes(
                primes_list
	      , primes_list + sizeof primes_list / sizeof (unsigned int)
        );

	//! guess how many primes there are below 'value'
	primes.reserve(value / log(value));

	while (primes.back() < value) {
	        unsigned int upper_bound = sqrt(n);

		std::vector<unsigned int>::const_iterator i = primes.begin();
		std::vector<unsigned int>::const_iterator e = primes.end();

		while (i != e && *i <= upper_bound)
		        if (n % *i++ == 0)
			        //! justified use of goto.
			        goto next_number;

		primes.push_back(n);
		sum += n;

	next_number:
		n += 2;
	}

	return sum - primes.back();
}

int main(int argc, char* argv[])
{
        std::cout<<sum_of_primes_below(2000000)<<std::endl;
}
