#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

unsigned int divide_and_count(unsigned int& number, unsigned int divisor)
{
        unsigned int divisions = 0;

	while (number % divisor == 0) {
	        number /= divisor;
		divisions++;
	}

	return divisions;
}

void LCM_helper(std::vector<unsigned int>& factors, unsigned int divisor, unsigned int& count)
{
        std::vector<unsigned int>::iterator i = factors.begin();
	std::vector<unsigned int>::iterator e = factors.end();

	while (i != e) {
	        count = std::max(count, *i % divisor == 0 ? divide_and_count(*i, divisor) : 0);
		++i;
	}
}

unsigned long long LCM(std::vector<unsigned int>& factors, const std::vector<unsigned int>& lprimes)
{
        std::vector<unsigned int> division_counts(lprimes.size(), 0);

	std::vector<unsigned int>::const_iterator i = lprimes.begin();
	std::vector<unsigned int>::const_iterator e = lprimes.end();

	std::vector<unsigned int>::iterator c = division_counts.begin();

	while (i != e)
	        LCM_helper(factors, *i++, *c++);

	i = lprimes.begin();
	c = division_counts.begin();

	unsigned long long lcm = 1;

	while (i != e)
	        lcm *= pow(*i++, *c++);

	return lcm;
}

unsigned int problem5()
{
        unsigned int factors_list[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	unsigned int lprimes_list[] = { 2, 3, 5, 7, 11, 13, 17, 19 };

	std::vector<unsigned int> factors(
                factors_list
	      , factors_list + sizeof factors_list / sizeof (unsigned int)
        );
	std::vector<unsigned int> lprimes(
                lprimes_list
	      , lprimes_list + sizeof lprimes_list / sizeof (unsigned int)
	);

	return LCM(factors, lprimes);
}

int main(int argc, char* argv[])
{
        std::cout<<problem5()<<std::endl;
}
