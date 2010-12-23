#include <iostream>
#include <cmath>

unsigned int sum_of_raised_digits(unsigned int n, unsigned int power)
{
        unsigned int sum = 0;

	while (n != 0) {
	        sum += pow(n % 10, power);
		n /= 10;
	}

	return sum;
}

unsigned int sum_of(unsigned int power)
{
        unsigned int upper_bound = pow(10, power + 1) - 1;
	unsigned int sum = 0;

        unsigned int i = 2;  // current number
	unsigned int s = 0;  // sum of digits raised to 'power'

	while (i != upper_bound) {
	        if ((s = sum_of_raised_digits(i, power)) == i)
		        sum += s;
		++i;
	}

	return sum;
}

int main(int argc, char* argv[])
{
        std::cout<<sum_of(5)<<std::endl;
}
