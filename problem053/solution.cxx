#include <iostream>

unsigned int C(unsigned int n, unsigned int r, unsigned int bound)
{
        double total = 1;

	while (r > 0)
	        if ((total *= (static_cast<double>(n--) / static_cast<double>(r--))) > bound)
		        return true;

	return false;
}

unsigned int problem53()
{
        unsigned int n = 23;
	unsigned int count = 0;

	while (n <= 100) {
	        unsigned int r = 1;

	        while (r <= n)
		        if (C(n, r++, 1000000))
			        ++count;
		++n;
	}

	return count;
}

int main(int argc, char* argv[])
{
        std::cout<<problem53()<<std::endl;
}
