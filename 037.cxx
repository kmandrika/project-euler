#include <iostream>
#include <set>
#include <cmath>

inline unsigned int truncate_L(unsigned int& prime)
{
        return prime /= 10;
}

bool truncatable_L(unsigned int prime, const std::set<unsigned int>& primes)
{
        while (truncate_L(prime))
	        if (primes.find(prime) == primes.end())
		        return false;
	return true;
}

inline unsigned int truncate_R(unsigned int& prime)
{
        return prime %= static_cast<unsigned int>(
                pow(10, static_cast<unsigned int>(log10(prime)))
        );
}

bool truncatable_R(unsigned int prime, const std::set<unsigned int>& primes)
{
        while (truncate_R(prime))
	        if (primes.find(prime) == primes.end())
		        return false;
	return true;
}

unsigned int problem37()
{
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

	std::set<unsigned int>::const_iterator i = primes.begin();
	std::set<unsigned int>::const_iterator e = primes.end();

	unsigned int sum = 0;

	while (i != e) {
	        if (truncatable_L(*i, primes) && truncatable_R(*i, primes))
		        sum += *i;
		++i;
	}

	return sum - 2 - 3 - 5 - 7;
}

int main(int argc, char* argv[])
{
        std::cout<<problem37()<<std::endl;
}
