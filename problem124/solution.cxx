#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>

unsigned int RAD(unsigned int n, const std::set<unsigned int>& primes)
{
        static std::map<unsigned int, unsigned int> cache;

	std::map<unsigned int, unsigned int>::iterator cached;

	if ((cached = cache.find(n)) != cache.end())
	        return cached->second;

	unsigned int N = n;

        std::set<unsigned int>::const_iterator i = primes.begin();
	std::set<unsigned int>::const_iterator e = primes.end();

	unsigned int product = 1;
	unsigned int previous = 0;

	while (i != e && *i <= N) {
	        while (n % *i == 0) {
		        if (*i != previous)
			        product *= *i;

			n /= *i;
			previous = *i;
		}

		++i;
	}

	return cache[N] = product;
}

struct Rad {
        Rad(const std::set<unsigned int>& primes) : primes_(primes) {
	}

        bool operator ()(unsigned int a, unsigned int b) const {
	        return RAD(a, primes_) < RAD(b, primes_);
	}

private:
        const std::set<unsigned int>& primes_;
};

struct Consecutive {
        unsigned int operator ()() const {
	        static unsigned int sequence = 1;
		return sequence++;
	}
};

unsigned int problem124()
{
        unsigned int primes_list[] = { 2, 3, 5, 7, 11, 13, 17, 19 };
	unsigned int n = 23;

	std::set<unsigned int> primes(
                primes_list
	      , primes_list + sizeof primes_list / sizeof (unsigned int)
        );

	unsigned int bound = 100000;

	while (*primes.rbegin() < bound) {
	        std::set<unsigned int>::const_iterator i = primes.begin();
		std::set<unsigned int>::const_iterator e = primes.end();

		while (i != e)
		        if (n % *i++ == 0)
			        //! this use of goto is justified
			        goto next_number;

		primes.insert(n);

	next_number:
		n += 2;
	}

	std::vector<unsigned int> generated(100000, 0);

	std::generate(generated.begin(), generated.end(), Consecutive());
	std::sort(generated.begin(), generated.end(), Rad(primes));

	return generated[10000 - 2];
}

int main(int argc, char* argv[])
{
        std::cout<<problem124()<<std::endl;
}
