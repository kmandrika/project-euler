#include <iostream>
#include <set>
#include <cmath>

bool is_pandigital(unsigned int n)
{
        unsigned int digits[10] = { 0 };
	unsigned int digit_count = 0;

	while (n != 0) {
	        ++digits[n % 10];
		++digit_count;
		n /= 10;
	}

	while (digit_count != 0)
	        if (digits[digit_count--] != 1)
		        return false;
	return true;
}

unsigned int problem41()
{
        unsigned int primes_list[] = { 2, 3, 5, 7, 11, 13, 17, 19 };
	unsigned int n = 23;

	unsigned int largest_pandigital = 2143;

	std::set<unsigned int> primes(
                primes_list
	      , primes_list + sizeof primes_list / sizeof (unsigned int)
        );

	while (*primes.rbegin() <= 7654321) {
	        unsigned int divisor_limit = sqrt(n);

		std::set<unsigned int>::const_iterator i = primes.begin();
		std::set<unsigned int>::const_iterator e = primes.end();

		while (i != e && *i <= divisor_limit)
		        if (n % *i++ == 0)
			        //! this use of goto is justified
			        goto next_number;

		primes.insert(n);

		if (is_pandigital(n) && n > largest_pandigital)
		        largest_pandigital = n;

	next_number:
		n += 2;
	}

	return largest_pandigital;
}

int main(int argc, char* argv[])
{
        std::cout<<problem41()<<std::endl;
}
