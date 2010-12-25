#include <iostream>
#include <bitset>

unsigned int reverse(unsigned int number)
{
        unsigned int reversed = 0;

	while (number > 0) {
	        reversed = reversed * 10 + number % 10;
		number /= 10;
	}

	return reversed;
}

unsigned int MSB(unsigned int number)
{
        static const int table[] = {
	        0, 9, 1, 10, 13, 21, 2, 29, 11, 14, 16, 18, 22, 25, 3, 30,
		8, 12, 20, 28, 15, 17, 24, 7, 19, 27, 23, 6, 26, 5, 4, 31
	};

	number |= number >> 1;
	number |= number >> 2;
	number |= number >> 4;
	number |= number >> 8;
	number |= number >> 16;

	return table[(unsigned int)(number * 0x07C4ACDDU) >> 27];
}

inline bool is_palindrome_base10(unsigned int number)
{
        return number == reverse(number);
}

inline bool is_palindrome_base2(unsigned int number)
{
        unsigned int msb = MSB(number);
	unsigned int i = 0;

	std::bitset<sizeof (unsigned int) * 8> bits(number);

	while (i <= msb / 2) {
	        if (bits.test(i) != bits.test(msb - i))
		        return false;
		++i;
	}

	return true;
}

unsigned int find_sum_of_palindromes(unsigned int upper_bound)
{
        unsigned int sum = 0;
	unsigned int i = 1;

	while (i != upper_bound) {
	        if (is_palindrome_base10(i) && is_palindrome_base2(i))
		        sum += i;
		++i;
	}

	return sum;
}

int main(int argc, char* argv[])
{
        std::cout<<find_sum_of_palindromes(1000000)<<std::endl;
}
