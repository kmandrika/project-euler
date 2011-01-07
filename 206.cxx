#include <iostream>
#include <cmath>
#include <cassert>

bool is_pattern(unsigned long long n)
{	
	unsigned int pattern_digit = 9;

	while (pattern_digit != 0) {
	        if (n % 10 != pattern_digit--)
		        return false;

		n /= 100;
	}
    
	return true;
}

unsigned long long problem206()
{
        unsigned long long upper = 19293949596979899;
	unsigned long long lower = 10203040506070809;

	unsigned long long sqrt_upper = ceil(sqrt(upper));
	unsigned long long sqrt_lower = floor(sqrt(lower));

	assert(sqrt_upper / 2 != 0);

	while (sqrt_upper != sqrt_lower) {
	        if (sqrt_upper % 10 == 3 || sqrt_upper % 10 == 7) {
			if (is_pattern(sqrt_upper * sqrt_upper))
			        return sqrt_upper * 10;

		}

		sqrt_upper -= 2;
	}

	return 0;
}

int main(int argc, char* argv[])
{
        std::cout<<problem206()<<std::endl;
}
