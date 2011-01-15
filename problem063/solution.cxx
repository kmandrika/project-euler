#include <iostream>
#include <vector>

struct number_t {
        number_t(unsigned int initial) {
		while (initial != 0) {
		        number_.push_back(initial % 10);
			initial /= 10;
		}
	}

        void raise(unsigned int power) {
		std::vector<unsigned char> original = number_;

		while (--power) {
		        std::vector<unsigned int> acyclic(number_.size() + original.size(), 0);
		    
			unsigned int pos = 0;

			for (unsigned int i = 0; i < original.size(); ++i) {
			        std::vector<unsigned int> local_acyclic;

				for (unsigned int j = 0; j < number_.size(); ++j)
				        local_acyclic.push_back(number_[j] * original[i]);

				for (unsigned int j = 0; j < local_acyclic.size(); ++j)
				        acyclic[pos + j] += local_acyclic[j];

				++pos;
			}

			number_.clear();
			number_.reserve(acyclic.size());

			unsigned int carry = 0;

			for (unsigned int i = 0; i < acyclic.size() - 1; ++i) {
			        number_.push_back((acyclic[i] + carry) % 10);
				carry = (acyclic[i] + carry) / 10;
			}

			if (carry > 0)
			        number_.push_back(carry);
		}
	}

        unsigned int digits() const {
	        return number_.size();
	}

private:
        std::vector<unsigned char> number_;
};

unsigned int problem63()
{
        unsigned int count = 0;

        for (unsigned int i = 1; i < 50; ++i) {
	        for (unsigned int j = 1; j < 50; ++j) {
		        number_t N(i);

			N.raise(j);

			if (N.digits() == j)
			        ++count;
		}
	}

	return count;
}

int main(int argc, char* argv[])
{
        std::cout<<problem63()<<std::endl;
}
