#include <iostream>
#include <cmath>
#include <cfloat>

enum direction_t { Negative = -1, Neutral = 0, Positive = 1 };

direction_t direction(unsigned int d1, unsigned int d2)
{
        return d1 == d2 ? Neutral : d1 < d2 ? Negative : Positive;
}

bool is_bouncy(unsigned int n)
{
	unsigned int L = n % 10; n /= 10;
	unsigned int N = n % 10; n /= 10;

	direction_t initial_direction = direction(N, L);

	while (n != 0) {
	        direction_t this_direction = direction(n % 10, N);

		if (this_direction != Neutral) {
		        if (initial_direction != Neutral) {
			        if (this_direction != initial_direction)
				        return true;

				goto next_digit;
			}

			initial_direction = this_direction;
		}

	next_digit:
		N = n % 10;
		n /= 10;
	}

	return false;
}

bool compare_less(double a, double b)
{
        return fabs(b - a) > DBL_EPSILON;
}

unsigned int problem112()
{
        unsigned int bouncy = 0;
	unsigned int n = 100;

	double percent = 0;

	while (compare_less(percent, 0.99)) {
	        if (is_bouncy(n))
		        ++bouncy;

		percent = static_cast<double>(bouncy) / n;
		++n;
	}

	return n - 1;
}

int main(int argc, char* argv[])
{
        std::cout<<problem112()<<std::endl;
}
