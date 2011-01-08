#include <iostream>
#include <algorithm>
#include <iterator>

template<typename BidirectionalIterator>
void nth_lexi_permutation(BidirectionalIterator first, BidirectionalIterator last, unsigned int iteration)
{
        while (iteration-- && std::next_permutation(first, last)) {
	}
}

int main(int argc, char* argv[])
{
        unsigned int digits[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	size_t size = sizeof digits / sizeof (digits[0]);

	nth_lexi_permutation(digits, digits + size, 1000000 - 1);

	std::copy(
                digits
	      , digits + size
	      , std::ostream_iterator<unsigned int>(std::cout)
        );

	std::cout<<std::endl;
}
