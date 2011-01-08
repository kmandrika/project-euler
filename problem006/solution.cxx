#include <iostream>
#include <cmath>

unsigned long long problem6()
{
        unsigned long long sum_of_numbers = 0;
	unsigned long long sum_of_squares = 0;

	for (unsigned int i = 1; i <= 100; ++i) {
	        sum_of_numbers += i;
		sum_of_squares += pow(i, 2);
	}

	//! should probably use abs()
	unsigned long long difference = pow(sum_of_numbers, 2) - sum_of_squares;

	return difference;
}

int main(int argc, char* argv[])
{
        std::cout<<problem6()<<std::endl;
}
