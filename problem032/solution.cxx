#include <iostream>
#include <set>
#include <numeric>
#include <cmath>

bool is_pandigital(unsigned int n, unsigned int m, unsigned int p)
{
        unsigned int digits[10] = { 0 };
	unsigned int digit_count = 1;

	while (n != 0) {
	        ++digits[n % 10];
		n /= 10;
	}

	while (m != 0) {
	        ++digits[m % 10];
		m /= 10;
	}

	while (p != 0) {
	        ++digits[p % 10];
		p /= 10;
	}

	while (digit_count != 10)
	        if (digits[digit_count++] != 1)
		        return false;

	return true;
}

unsigned int problem32()
{
        unsigned int multiplicand = 1;
	unsigned int multiplicand_bound = 9999;

	std::set<unsigned int> products;

	while (multiplicand != multiplicand_bound) {
	        unsigned int multiplier = 1;
		unsigned int multiplier_bound = 9999;

	        while (multiplier != multiplier_bound) {
		        unsigned int product = multiplicand * multiplier;

			unsigned int digits =
			        floor(log10(multiplier)) + 1
			      + floor(log10(multiplicand)) + 1
			      + floor(log10(product)) + 1;

			if (digits > 9)
			        break;

			if (digits == 9 && is_pandigital(multiplicand, multiplier, product))
			        products.insert(product);

			++multiplier;
		}

		++multiplicand;
	}

	return std::accumulate(products.begin(), products.end(), 0);
}

int main(int argc, char* argv[])
{
        std::cout<<problem32()<<std::endl;
}
