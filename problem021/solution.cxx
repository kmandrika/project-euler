#include <iostream>
#include <set>
#include <numeric>
#include <cmath>

unsigned int sum_of_divisors(unsigned int number)
{
        unsigned int upper_bound = sqrt(number);
	unsigned int divisor = 2;
	unsigned int sum = 0;

	while (divisor <= upper_bound) {
	        if (number % divisor == 0)
		        sum += divisor + number / divisor;
		++divisor;
	}

	return sum + 1;
}

void append_if_amicable(unsigned int number, std::set<unsigned int>& amicable_pairs)
{
        unsigned int sum_of_divisors_of_number = sum_of_divisors(number);

        if (number != sum_of_divisors_of_number && sum_of_divisors(sum_of_divisors_of_number) == number) {
	        amicable_pairs.insert(number);
		amicable_pairs.insert(sum_of_divisors_of_number);
	}
}

unsigned int sum_of_amicable_pairs_under(unsigned int upper_bound)
{
        std::set<unsigned int> amicable_pairs;

	unsigned int number = 1;

	while (number != upper_bound) {
	        if (amicable_pairs.find(number) == amicable_pairs.end())
		        append_if_amicable(number, amicable_pairs);

		++number;
	}

	return std::accumulate(amicable_pairs.begin(), amicable_pairs.end(), 0);
}

unsigned int problem21()
{
        return sum_of_amicable_pairs_under(10000);
}

int main(int argc, char* argv[])
{
        std::cout<<problem21()<<std::endl;
}
