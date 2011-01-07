#include <iostream>
#include <set>

void construct_chain(unsigned int original, unsigned int current, std::set<unsigned int>& chain)
{
        static const unsigned int factorial[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

	chain.insert(current);

	unsigned int sum = 0;

	while (current != 0) {
	        sum += factorial[current % 10];
		current /= 10;
	}

	if (chain.find(sum) != chain.end())
	        return;

	construct_chain(original, sum, chain);
}

inline unsigned int chain_length(unsigned int n)
{
        std::set<unsigned int> chain; construct_chain(n, n, chain);
	return chain.size();
}

unsigned int problem74()
{
        unsigned int bound = 1000000;
	unsigned int i = 100;
	unsigned int count = 0;

	while (i != bound)
	        if (chain_length(i++) == 60)
		        ++count;

	return count;
}

int main(int argc, char* argv[])
{
        std::cout<<problem74()<<std::endl;
}
