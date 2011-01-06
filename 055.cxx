#include <iostream>
#include <set>
#include <cmath>
#include <vector>
#include <algorithm>

struct ulong_t {
        ulong_t() {
	}

        ulong_t(unsigned long long number) {
	        while (number != 0) {
		        number_.push_back(number % 10);
			number /= 10;
		}
	}

        ulong_t reversed() const {
	        ulong_t result;

		result.number_ = number_;
		std::reverse(result.number_.begin(), result.number_.end());

		return result;
	}

        ulong_t operator +(const ulong_t& rhs) const {
	        ulong_t result;

		const ulong_t& L = number_.size() >= rhs.number_.size() ? *this : rhs;
		const ulong_t& S = number_.size() <  rhs.number_.size() ? *this : rhs;

		result.number_.reserve(L.number_.size() + 2);

		add(result, L, S);

		return result;
	}

        bool operator ==(const ulong_t& rhs) const {
	        return number_ == rhs.number_;
	}

        unsigned int digits() const {
	        return number_.size();
	}

        unsigned int integral() const {
	        unsigned int result = 0;
		unsigned int digit = 0;

		while (digit != digits()) {
		        result += pow(10, digit) * number_[digit];
			++digit;
		}

		return result;
	}

private:
	void add(ulong_t& result, const ulong_t& longer, const ulong_t& shorter) const {
	        unsigned int carry = 0;
		unsigned int i = 0;

		while (i < shorter.number_.size()) {
		        unsigned int sum = shorter.number_[i] + longer.number_[i] + carry;

			result.number_.push_back(sum % 10);
			carry = sum / 10;

			++i;
		}

		while (i < longer.number_.size()) {
		        unsigned int sum = longer.number_[i] + carry;

			result.number_.push_back(sum % 10);
			carry = sum / 10;

			++i;
		}

		if (carry != 0) {
		        result.number_.push_back(carry % 10);

		        if (carry >= 10)
			        result.number_.push_back(carry / 10);
		}
	}

private:
        std::vector<char> number_;
};

bool is_palindrome(const ulong_t& n)
{
        return n == n.reversed();
}

bool is_lychrel(unsigned int n, std::set<unsigned int>& lychrel)
{
        if (lychrel.find(n) != lychrel.end())
	        return true;

	ulong_t N = n;
	ulong_t N_reversed = N.reversed();

	std::set<unsigned int> maybe_lychrel;

	for (unsigned int i = 0; i < 50; ++i) {
	        if (N.digits() < 5) {
		        maybe_lychrel.insert(N.integral());
			maybe_lychrel.insert(N_reversed.integral());
		}

		ulong_t sum = N + N_reversed;

		if (is_palindrome(sum)) {
		        lychrel.insert(maybe_lychrel.begin(), maybe_lychrel.end());
			return true;
		}

		N = sum;
		N_reversed = N.reversed();
	}

	return false;
}

unsigned int problem55()
{
	unsigned int n = 1;
	unsigned int count = 0;

	std::set<unsigned int> lychrel;

	while (n < 10000)
	        if (!is_lychrel(n++, lychrel))
		        ++count;

	return count;
}

int main(int argc, char* argv[])
{
        std::cout<<problem55()<<std::endl;
}
