#include <iostream>
#include <vector>
#include <set>
#include <cmath>

void generate_primes(unsigned int upper, std::set<unsigned int>& primes)
{
        //! Sieve of Eratosthenes is too slow.

        std::vector<bool> is_prime(upper, false);

        unsigned int limit = sqrt(upper);
        unsigned int x = 1;

        while (x <= limit) {
                unsigned int x_sqr = x * x;
                unsigned int y = 1;

                while (y <= limit) {
                        unsigned int y_sqr = y * y;
                        unsigned int n = 4 * x_sqr + y_sqr;

                        if (n < upper && (n % 12 == 1 || n % 12 == 5))
                                is_prime[n] = !is_prime[n];

                        n = 3 * x_sqr + y_sqr;

                        if (n < upper && n % 12 == 7)
                                is_prime[n] = !is_prime[n];

                        n = 3 * x_sqr - y_sqr;

                        if (x > y && n < upper && n % 12 == 11)
                                is_prime[n] = !is_prime[n];

                        ++y;
                }

                ++x;
        }

        for (unsigned int n = 5; n <= limit; ++n)
                if (is_prime[n])
                        for (unsigned int k = n * n; k < upper; k += n * n)
                                is_prime[k] = false;

        primes.insert(2);
        primes.insert(3);

        for (unsigned int n = 5; n < upper; n += 2)
                if (is_prime[n])
                        primes.insert(n);
}

unsigned int problem87()
{
        unsigned int upper = sqrt(50000000);

        std::set<unsigned int> primes; generate_primes(upper, primes);
        std::set<unsigned int>::const_iterator S = primes.begin();
        std::set<unsigned int>::const_iterator E = primes.end();

        std::set<unsigned int> results;

        while (S != E && *S <= upper) {
                std::set<unsigned int>::const_iterator C = primes.begin();

                while (C != E && *C < 370) {
                        std::set<unsigned int>::const_iterator F = primes.begin();

                        while (F != E && *F < 85) {
                                unsigned long long n = pow(*S, 2) + pow(*C, 3) + pow(*F, 4);

                                if (n < 50000000)
                                        results.insert(n);

                                ++F;
                        }
                        ++C;
                }
                ++S;
        }

        return results.size();
}

int main(int argc, char* argv[])
{
        std::cout<<problem87()<<std::endl;
}
