#include <iostream>
#include <cmath>

//! calculates the ith term of the fibonacci sequence using
//  Binet's formula.
unsigned int fibonacci_term(unsigned int i) {
    static double square_root_of_5 = sqrt(5);
    static double golden_ratio = (1 + square_root_of_5) / 2;

    return (pow(golden_ratio, i) - pow(1 - golden_ratio, i)) / square_root_of_5;
}

unsigned int accumulate_evens_not_exceeding(unsigned int bound) {
    unsigned int f = 0; // value of ith element of the sequence
    unsigned int i = 0;

    unsigned int sum = 0;

    while ((f = fibonacci_term(i)) < bound) {
	if (f % 2 == 0)
	    sum += f;
	++i;
    }

    return sum;
}

int main(int argc, char* argv[])
{
    std::cout<<accumulate_evens_not_exceeding(4000000)<<std::endl;
}
