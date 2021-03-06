#include <iostream>

unsigned int problem28(size_t size)
{
        unsigned int current = size * size;
        unsigned int sum = current;
	unsigned int stride = size;

	while (current != 1) {
	        for (unsigned int i = 0; i < 4; ++i) {
		        current -= stride - 1;
			sum += current;
		}

		stride -= 2;
	}

	return sum;
}

int main(int argc, char* argv[])
{
        std::cout<<problem28(1001)<<std::endl;
}
