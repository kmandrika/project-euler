#include <iostream>
#include <set>
#include <cmath>

unsigned int is_prime(int n, const std::set<unsigned int>& primes)
{
        return primes.find(n) != primes.end();
}

unsigned int test_primes(int a, int b, const std::set<unsigned int>& primes)
{
        unsigned int count = 0;
	unsigned int n = 0;

	while (is_prime(n * n + a * n + b, primes)) {
	        ++count;
		++n;
	}

	return count;
}

int problem27()
{
        //! Generate a list of primes.
        unsigned int primes_list[] = { 2, 3, 5, 7, 11, 13, 17, 19 };
	unsigned int n = 23;

	std::set<unsigned int> primes(
                primes_list
	      , primes_list + sizeof primes_list / sizeof (unsigned int)
        );

	while (primes.size() <= 100000) {
	        unsigned int divisor_limit = sqrt(n);

		std::set<unsigned int>::const_iterator i = primes.begin();
		std::set<unsigned int>::const_iterator e = primes.end();

		while (i != e && *i <= divisor_limit)
		        if (n % *i++ == 0)
			        //! this use of goto is justified
			        goto next_number;

		primes.insert(n);

	next_number:
		n += 2;

	}

	//! Test each a and b.
        unsigned int max_primes = 0;

	int max_a = 0;
	int max_b = 0;

        for (int a = -1000 + 1; a < 1000; ++a) {
	        for (int b = -1000 + 1; b < 1000; ++b) {
		        unsigned int prime_count = test_primes(a, b, primes);

			if (prime_count > max_primes) {
			        max_primes = prime_count;
				max_a = a;
				max_b = b;
			}
		}
	}

	return max_a * max_b;
}

int main(int argc, char* argv[])
{
        std::cout<<problem27()<<std::endl;
}
