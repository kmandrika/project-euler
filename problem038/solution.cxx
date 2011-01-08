#include <iostream>
#include <cmath>

bool is_pandigital(unsigned long long n)
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

unsigned long long concatenate(unsigned int integer, unsigned int n_bound)
{
        unsigned int n = 1;
	unsigned long long result = 0;

	while (n <= n_bound) {
	        unsigned long long product = integer * n;
	        result = result * pow(10, floor(log10(product)) + 1) + product;
		++n;
	}

	return result;
}

unsigned int problem38()
{
        unsigned int integer = 1;
	unsigned int integer_upper_bound = 1000000;
	unsigned int max = 0;

	while (integer != integer_upper_bound) {
	        unsigned int n = 2;
		unsigned long long concatenated = 0;

	        while ((concatenated = concatenate(integer, n++)) < 1000000000) {
		        if (concatenated > 99999999 && is_pandigital(concatenated) && concatenated > max)
			        max = concatenated;
		}

		++integer;
	}

	return max;
}

int main(int argc, char* argv[])
{
        std::cout<<problem38()<<std::endl;
}
