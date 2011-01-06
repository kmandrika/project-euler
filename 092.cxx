#include <iostream>
#include <cmath>

bool arrives_at_89(unsigned int i)
{
        unsigned int squares_sum = 0;

	while (i != 0) {
	        squares_sum += pow(i % 10, 2);
		i /= 10;
	}

	if (squares_sum == 1)
	        return false;

	if (squares_sum == 89)
	        return true;

	return arrives_at_89(squares_sum);
}

unsigned int problem92()
{
        unsigned int count = 0;
	unsigned int i = 1;

	while (i < 10000000)
	        if (arrives_at_89(i++))
		        ++count;
	return count;
}

int main(int argc, char* argv[])
{
        std::cout<<problem92()<<std::endl;
}
