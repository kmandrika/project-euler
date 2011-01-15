#include <iostream>
#include <cmath>
#include <set>

unsigned int cycle_length(unsigned int d)
{
        std::set<unsigned int> cycle;

	unsigned int div = 10;
	unsigned int rem = div % d;

	while (cycle.find(rem) == cycle.end()) {
	        cycle.insert(rem);

		div = rem * 10;
		rem = div % d;
	}

	return cycle.size();
}

unsigned int problem26()
{
        unsigned int longest = 1;
	unsigned int longest_d = 1;

	unsigned int d = 1;

	while (d < 1000) {
	        unsigned int length = cycle_length(d);

		if (length > longest) {
		        longest = length;
			longest_d = d;
		}

		++d;
	}

	return longest_d;
}

int main(int argc, char* argv[])
{
        std::cout<<problem26()<<std::endl;
}
