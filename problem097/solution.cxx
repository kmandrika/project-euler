#include <iostream>

unsigned long long pow_last_10(unsigned long long a, unsigned int p)
{
        unsigned long long R = 1;

        while (p--) {
	        if (R > 10000000000)
		        R -= 10000000000;
	        R *= a;
	}

	return R;
}

unsigned long long problem97()
{
        return (pow_last_10(2, 7830457) * 28433 + 1) % 10000000000;
}

int main(int argc, char* argv[])
{
        std::cout<<problem97()<<std::endl;
}
