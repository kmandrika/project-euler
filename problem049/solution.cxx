#include <iostream>
#include <algorithm>
#include <set>

inline bool is_prime(unsigned int n, const std::set<unsigned int>& primes)
{
        return primes.find(n) != primes.end();
}

inline unsigned int integral(unsigned int (N)[4])
{
        return N[0] * 1000 + N[1] * 100 + N[2] * 10 + N[3];
}

//! a, b, and c are 4 digit numbers
inline unsigned long long CAT(unsigned long long a, unsigned long long b, unsigned long long c)
{
        return a * 100000000 + b * 10000 + c;
}

unsigned long long problem49()
{
        unsigned int primes_list[] = { 2, 3, 5, 7, 11, 13, 17, 19 };
	unsigned int n = 23;

        unsigned int bound = 10000;

	std::set<unsigned int> primes(
                primes_list
	      , primes_list + sizeof primes_list / sizeof (unsigned int)
        );

	while (*primes.rbegin() < bound) {
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

        n = 1000;

        while (n != bound) {
                if (n != 1487 && is_prime(n, primes)) {
                        unsigned int prime = n;
                        unsigned int N[4] = { 0 };

                        N[3] = prime % 10; prime /= 10;
                        N[2] = prime % 10; prime /= 10;
                        N[1] = prime % 10; prime /= 10;
                        N[0] = prime;

                        std::set<unsigned int> sequence;

                        sequence.insert(n);

                        while (std::next_permutation(N, N + sizeof N / sizeof (N[0]))) {
                                if (is_prime(integral(N), primes))
                                        sequence.insert(integral(N));
                        }

                        std::set<unsigned int>::const_iterator i = sequence.begin();
                        std::set<unsigned int>::const_iterator e = sequence.end();

                        unsigned int first = *i++;

                        while (i != e) {
                                unsigned int difference = *i - first;

                                std::set<unsigned int>::const_iterator j = i;
                                std::set<unsigned int>::const_iterator k = sequence.end();

                                unsigned int striding = *j;

                                while (j != k) {
                                        if (*j - striding == difference)
                                                return CAT(first, striding, *j);
                                        ++j;
                                }

                                ++i;
                        }
                }

                ++n;
        }

        return 0;
}

int main(int argc, char* argv[])
{
        std::cout<<problem49()<<std::endl;
}
