#include <iostream>
#include <vector>
#include <cmath>

unsigned int get_prime(unsigned int ith)
{
        unsigned int primes_list[] = { 2, 3, 5, 7, 11, 13 }; // initial list
	unsigned int number = 17;

	std::vector<unsigned int> primes(
                primes_list
	      , primes_list + sizeof primes_list / sizeof (unsigned int)
        );

	primes.reserve(ith);

	while (primes.size() != ith) {
	        unsigned int upper_bound = sqrt(number);

		std::vector<unsigned int>::const_iterator i = primes.begin();
		std::vector<unsigned int>::const_iterator e = primes.end();

		while (i != e && *i <= upper_bound)
			if (number % *i++ == 0)
			        //! this goto is justified
			        goto next_number;

		primes.push_back(number);

	next_number:
		number += 2;
	}

	return primes.back();
}

int main(int argc, char* argv[])
{
        std::cout<<get_prime(10001)<<std::endl;
}
