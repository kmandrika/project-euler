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

inline bool is_prime(unsigned int n, const std::set<unsigned int>& primes)
{
        return primes.find(n) != primes.end();
}

unsigned int problem50()
{
        std::set<unsigned int> primes; generate_primes(1000000, primes);

        std::set<unsigned int>::const_iterator i = primes.begin();
        std::set<unsigned int>::const_iterator e = primes.end();

        unsigned int longest_sum = 0;
        unsigned int longest_sum_prime = 0;

        while (i != e) {
                std::set<unsigned int>::const_iterator s = i;
                unsigned int sum = *s++;

                while (s != e && sum < 1000000) {
                        sum += *s;

                        size_t sum_length = std::distance(i, s) + 1;

                        if (is_prime(sum, primes) && sum_length > longest_sum) {
                                longest_sum = sum_length;
                                longest_sum_prime = sum;
                        }

                        ++s;
                }

                ++i;
        }

        return longest_sum_prime;
}

int main(int argc, char* argv[])
{
        std::cout<<problem50()<<std::endl;
}
