#include <iostream>
#include <set>
#include <cmath>

void distinct_primes(unsigned int n, const std::set<unsigned int>& primes, std::set<unsigned int>& distinct)
{
        std::set<unsigned int>::const_iterator i = primes.begin();
	std::set<unsigned int>::const_iterator e = primes.end();

	distinct.clear();

	unsigned int previous = 0;
	unsigned int upper = n;

	while (i != e && *i <= upper) {
	        while (n % *i == 0) {
		        if (*i != previous)
			        distinct.insert(*i);

			n /= *i;
			previous = *i;
		}

		++i;
	}
}

unsigned int PHI(unsigned int n, const std::set<unsigned int>& primes)
{
        std::set<unsigned int> distinct; distinct_primes(n, primes, distinct);

	std::set<unsigned int>::const_iterator i = distinct.begin();
	std::set<unsigned int>::const_iterator e = distinct.end();

	double interim_product = 1;

	while (i != e)
	        interim_product *= 1.0 - 1.0 / *i++;

	return static_cast<double>(n) * interim_product;
}

unsigned int find_max(const std::set<unsigned int>& primes)
{
        unsigned int upper = 1000000;
        unsigned int n = 10;
	unsigned int n_max = 0;

	double inverse_phi = 0;
	double inverse_phi_max = 0;

	while (n <= upper) {
		inverse_phi = static_cast<double>(n) / PHI(n, primes);

		if (inverse_phi > inverse_phi_max) {
		        inverse_phi_max = inverse_phi;
			n_max = n;
		}

		++n;
	}

	return n_max;
}

unsigned int problem69()
{
        unsigned int primes_list[] = { 2, 3, 5, 7, 11, 13, 17, 19 };
	unsigned int n = 23;

	std::set<unsigned int> primes(
                primes_list
	      , primes_list + sizeof primes_list / sizeof (unsigned int)
        );

	unsigned int upper = sqrt(1000000);

	while (*primes.rbegin() < upper) {
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

	return find_max(primes);
}

int main(int argc, char* argv[])
{
        std::cout<<problem69()<<std::endl;
}
