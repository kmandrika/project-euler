#include <iostream>
#include <cassert>
#include <algorithm>

unsigned int reverse(unsigned int number) {
    unsigned int reversed = 0;

    while (number > 0) {
	reversed = reversed * 10 + number % 10;
	number /= 10;
    }

    return reversed;
}

inline bool is_palindrome(unsigned int number) {
    return number == reverse(number);
}

unsigned int find_palindrome(unsigned int upper_bound, unsigned int lower_bound, unsigned int highest) {
    unsigned int product = 0;
    unsigned int i = upper_bound;

    while (i > lower_bound)
	if (is_palindrome(product = i-- * upper_bound))
	    highest = std::max(product, highest);

    return highest;
}

unsigned int find_palindrome(unsigned int upper_bound, unsigned int lower_bound) {
    unsigned int highest = 0;
    unsigned int i = upper_bound;

    while (i > lower_bound)
	highest = find_palindrome(i--, lower_bound, highest);

    return highest;
}

int main(int argc, char* argv[])
{
    std::cout<<find_palindrome(999, 99)<<std::endl;
}
