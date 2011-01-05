#include <iostream>
#include <limits>

struct unordered_integer {
private:
        struct cell {
	        cell() : set(false), count(0) {
		}

	        void operator ++() {
		        set = true;
			++count;
		}

	        bool operator != (const cell& rhs) const {
		        return set != rhs.set || count != rhs.count;
		}

	        bool set;
	        unsigned int count;
	};

public:
        explicit unordered_integer(unsigned long long n) {
	        while (n != 0) {
		        ++value[n % 10];
			n /= 10;
		}
	}

        bool operator ==(const unordered_integer& rhs) const {
	        unsigned int i = 0;

		while (i < 10) {
		        if (value[i] != rhs.value[i])
			        return false;
			++i;
		}

		return true;
	}

private:
        cell value[10];
};

unsigned int problem52()
{
        unsigned int n = 1;

	while (n != std::numeric_limits<unsigned long long>::max()) {
	        if (unordered_integer(n) == unordered_integer(n * 2) &&
		    unordered_integer(n) == unordered_integer(n * 3) &&
		    unordered_integer(n) == unordered_integer(n * 4) &&
		    unordered_integer(n) == unordered_integer(n * 5) &&
		    unordered_integer(n) == unordered_integer(n * 6))
		        break;

		++n;
	}

	return n;
}

int main(int argc, char* argv[])
{
        std::cout<<problem52()<<std::endl;
}
