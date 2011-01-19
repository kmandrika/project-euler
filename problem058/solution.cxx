#include <iostream>
#include <cmath>
#include <set>
#include <vector>

void generate_primes(unsigned long long upper, std::set<unsigned long long>& primes)
{
        //! Sieve of Eratosthenes is too slow.

        std::vector<bool> is_prime(upper, false);

        unsigned long long limit = sqrt(upper);
        unsigned long long x = 1;

        while (x <= limit) {
                unsigned long long x_sqr = x * x;
                unsigned long long y = 1;

                while (y <= limit) {
                        unsigned long long y_sqr = y * y;
                        unsigned long long n = 4 * x_sqr + y_sqr;

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

        for (unsigned long long n = 5; n <= limit; ++n)
                if (is_prime[n])
                        for (unsigned long long k = n * n; k < upper; k += n * n)
                                is_prime[k] = false;

        primes.insert(2);
        primes.insert(3);

        for (unsigned long long n = 5; n < upper; n += 2)
                if (is_prime[n])
                        primes.insert(n);
}

bool is_prime_via_primality_test(unsigned long long n, const std::set<unsigned long long>& primes)
{
        std::set<unsigned long long>::const_iterator i = primes.begin();
        std::set<unsigned long long>::const_iterator e = primes.end();

        while (i != e)
                if (n % *i++ == 0)
                        return false;

        return true;
}

inline bool is_prime(unsigned long long n, const std::set<unsigned long long>& primes)
{
        return primes.find(n) != primes.end() || is_prime_via_primality_test(n, primes);
}

unsigned int problem58()
{
        std::set<unsigned long long> primes; generate_primes(30000, primes);

        unsigned int side_length = 2;
        unsigned int i = 1;

        unsigned int corner_count = 1;
        unsigned int prime_count = 0;

        double percent = 100.0;

        while (percent >= 10.0) {
                for (unsigned int j = 0; j < 4; ++j) {
                        ++corner_count;

                        i += side_length;

                        if (is_prime(i, primes))
                                ++prime_count;

                        percent = static_cast<double>(prime_count) / corner_count * 100.0;
                }

                side_length += 2;
        }

        return side_length - 1;
}

int main(int argc, char* argv[])
{
        std::cout<<problem58()<<std::endl;
}
