#include <iostream>
#include <set>

unsigned int divisor_sum(unsigned int n)
{
        unsigned int divisor = 1;
	unsigned int divisor_sum = 0;
	unsigned int upper_bound = n / 2;

	while (divisor <= upper_bound) {
	        if (n % divisor == 0)
		        divisor_sum += divisor;
		++divisor;
	}

	return divisor_sum;
}

void generate_abundant(std::set<unsigned int>& abundant, unsigned int upper_bound)
{
        unsigned int n = 12;

	while (n != upper_bound) {
		if (divisor_sum(n) > n)
		        abundant.insert(n);
		++n;
	}
}

bool is_sum_of_abundant(unsigned int n, const std::set<unsigned int>& abundant)
{
        std::set<unsigned int>::const_iterator i = abundant.begin();
	std::set<unsigned int>::const_iterator e = abundant.end();

	while (i != e) {
	        if (abundant.find(n - *i) != e)
		        return true;
		++i;
	}

	return false;
}

unsigned int problem23(unsigned int upper_bound)
{
        std::set<unsigned int> abundant;

	generate_abundant(abundant, upper_bound);

        unsigned int sum = 0;

        while (upper_bound != 0) {
	        if (!is_sum_of_abundant(upper_bound, abundant))
		        sum += upper_bound;
		--upper_bound;
	}

	return sum;
}

int main(int argc, char* argv[])
{
        std::cout<<problem23(28123)<<std::endl;
}
