#include <iostream>
#include <limits>
#include <boost/static_assert.hpp>

long double factorial(long double n)
{
        return n == 1 ? 1 : n * factorial(n - 1);
}

long double count_paths(size_t m, size_t n)
{
        return factorial(m + n) / (factorial(m) * factorial(n));
}

int main(int argc, char* argv[])
{
        BOOST_STATIC_ASSERT(sizeof (long double) == 16);

	std::cout.precision(std::numeric_limits<long double>::digits10);
        std::cout<<count_paths(20, 20)<<std::endl;
}
