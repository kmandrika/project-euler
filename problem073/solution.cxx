#include <iostream>

unsigned int GCD(unsigned int a, unsigned int b)
{
	while (b != 0) {
	        unsigned int t = b;

	        b = a % b;
		a = t;
	}

	return a;
}

unsigned int problem73()
{
	unsigned int count = 0;

	for (unsigned int d = 3; d <= 12000; ++d)
	        for (unsigned int n = d / 3 + 1; n <= d / 2; ++n)
		        if (GCD(n, d) == 1)
			        ++count;

	return count;
}

int main(int argc, char* argv[])
{
        std::cout<<problem73()<<std::endl;
}
