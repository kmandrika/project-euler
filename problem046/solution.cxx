#include <iostream>
#include <set>
#include <cmath>

inline bool is_prime(unsigned int n, const std::set<unsigned int>& primes)
{
        return primes.find(n) != primes.end();
}

bool CG(unsigned int n, const std::set<unsigned int>& primes)
{
        unsigned int bound = (n - 2) / 2;
	unsigned int square = 1;

	while (square != bound)
	        if (is_prime(n - 2 * pow(square++, 2), primes))
		        return true;

	return false;
}

unsigned int problem46()
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

        unsigned int i = 9;
	unsigned int bound = 1000;

	while (i != bound) {
	        if (!is_prime(i, primes) && !CG(i, primes))
		        return i;

		i += 2;
	}

	return 0;
}

int main(int argc, char* argv[])
{
        std::cout<<problem46()<<std::endl;
}
