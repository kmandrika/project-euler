#include <iostream>
#include <utility>

unsigned int next_term(unsigned int previous_term, bool odd)
{
        return odd ? 3 * previous_term + 1 : previous_term / 2;
}

unsigned int problem14(unsigned int upper_bound)
{
        std::pair<unsigned int, unsigned int> highest = std::make_pair(
                0     // chain length
	      , 0     // the number that produced this length
        );

        while (upper_bound != 1) {
	        unsigned int chain_length = 0;
		unsigned int term = upper_bound;

		while ((term = next_term(term, term % 2 != 0)) != 1)
		        ++chain_length;

		if (chain_length > highest.first) {
		        highest.first = chain_length;
			highest.second = upper_bound;
		}

		--upper_bound;
	}

	return highest.second;
}

int main(int argc, char* argv[])
{
        std::cout<<problem14(1000000 - 1)<<std::endl;
}
