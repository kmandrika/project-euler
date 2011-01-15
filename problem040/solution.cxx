#include <iostream>
#include <cmath>
#include <vector>

unsigned int digit_of(unsigned int n, unsigned int digit)
{
        unsigned int last = floor(log10(n));

	while (digit++ != last)
	        n /= 10;

	return n % 10;
}

unsigned int d(unsigned int digit)
{
        unsigned int i = 1;
	unsigned int digits = floor(log10(i)) + 1;

	while (digits < digit) {
	        digit -= digits;
		++i;

		digits = floor(log10(i)) + 1;
	}

	return digit_of(i, digit - 1);
}

unsigned int problem40()
{
        return d(1) * d(10) * d(100) * d(1000) * d(10000) * d(100000) * d(1000000);
}

int main(int argc, char* argv[])
{
        std::cout<<problem40()<<std::endl;
}
