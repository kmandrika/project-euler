#include <iostream>
#include <cmath>
#include <cfloat>

inline unsigned long long get_pentagonal_term(unsigned int n)
{
        return n * (3 * n - 1) / 2;
}

bool is_pentagonal(unsigned long long n)
{
        double root = (1 + sqrt(1.0 + 24 * n)) / 6.0;
	return root - floor(root) < 4 * DBL_EPSILON;
}

unsigned int problem44()
{
        unsigned int j = 2;
        unsigned int bound = 10000;

        while (j != bound) {
                unsigned long long pentagonal_j = get_pentagonal_term(j);
                unsigned int k = j + 1;

                while (k != bound) {
                        unsigned long long pentagonal_k = get_pentagonal_term(k);

                        if (is_pentagonal(pentagonal_k - pentagonal_j) &&
                            is_pentagonal(pentagonal_k + pentagonal_j))
                                return pentagonal_k - pentagonal_j;

                        ++k;
                }

                ++j;
        }

        return 0;
}

int main(int argc, char* argv[])
{
        std::cout<<problem44()<<std::endl;
}
