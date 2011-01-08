#include <iostream>
#include <set>

bool distinct_primes(unsigned int n, const std::set<unsigned int>& primes)
{
        std::set<unsigned int>::const_iterator i = primes.begin();
	std::set<unsigned int>::const_iterator e = primes.end();

	unsigned int prime_factors = 0;
	unsigned int previous = 0;
	unsigned int half = n / 2;

	while (i != e && *i < half) {
	        while (n % *i == 0) {
		        if (*i != previous)
			        ++prime_factors;

			n /= *i;
			previous = *i;
		}

		++i;
	}

	return prime_factors == 4 && n == 1;
}

unsigned int find(const std::set<unsigned int>& primes)
{
        unsigned int upper = 200000;
	unsigned int n = 1000;

	while (n <= upper) {
	        if (distinct_primes(n + 0, primes) &&
		    distinct_primes(n + 1, primes) &&
		    distinct_primes(n + 2, primes) &&
		    distinct_primes(n + 3, primes))
		        return n;
		++n;
	}

	return 0;
}

unsigned int problem47()
{
        unsigned int primes_list[] = { 2, 3, 5, 7, 11, 13, 17, 19 };
	unsigned int n = 23;

	std::set<unsigned int> primes(
                primes_list
	      , primes_list + sizeof primes_list / sizeof (unsigned int)
        );

	while (*primes.rbegin() < 10000) {
	        std::set<unsigned int>::const_iterator i = primes.begin();
		std::set<unsigned int>::const_iterator e = primes.end();

		while (i != e)
		        if (n % *i++ == 0)
			        //! this use of goto is justified
			        goto next_number;

		primes.insert(n);

	next_number:
		n += 2;
	}

	return find(primes);
}

int main(int argc, char* argv[])
{
        std::cout<<problem47()<<std::endl;
}
