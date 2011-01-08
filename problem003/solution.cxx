#include <iostream>
#include <boost/static_assert.hpp>

void factor(unsigned long long i, unsigned long long& number)
{
        while (number % i == 0)
	        number /= i;
}

unsigned long long problem3(unsigned long long number)
{
        unsigned long long i = 2;

	while (i != number / 2)
	        factor(i++, number);

	return number;
}

int main(int argc, char* argv[])
{
        BOOST_STATIC_ASSERT(sizeof (long long) == 8);

	std::cout<<problem3(600851475143)<<std::endl;
}
