#include <iostream>
#include <algorithm>

inline unsigned int cat(unsigned int a, unsigned int b, unsigned int c)
{
        return a * 100 + b * 10 + c;
}

bool DIV(unsigned int (N)[10])
{
        return
                cat(N[1], N[2], N[3]) % 2  == 0 &&
                cat(N[2], N[3], N[4]) % 3  == 0 &&
                cat(N[3], N[4], N[5]) % 5  == 0 &&
                cat(N[4], N[5], N[6]) % 7  == 0 &&
                cat(N[5], N[6], N[7]) % 11 == 0 &&
                cat(N[6], N[7], N[8]) % 13 == 0 &&
                cat(N[7], N[8], N[9]) % 17 == 0;
}

unsigned long long integral(unsigned int (N)[10])
{
        return
            N[0] * 1000000000 +
            N[1] * 100000000 +
            N[2] * 10000000 +
            N[3] * 1000000 +
            N[4] * 100000 +
            N[5] * 10000 +
            N[6] * 1000 +
            N[7] * 100 +
            N[8] * 10 +
            N[9];
}

unsigned long long problem43()
{
        unsigned int pandigital[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        unsigned long long sum = 0;

        while (std::next_permutation(pandigital, pandigital + sizeof pandigital / sizeof (unsigned int)))
                if (DIV(pandigital))
                        sum += integral(pandigital);

        return sum;
}

int main(int argc, char* argv[])
{
        std::cout<<problem43()<<std::endl;
}
