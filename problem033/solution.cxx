#include <iostream>

unsigned int problem33()
{
        unsigned int num = 10;
	unsigned int product_num = 1;
	unsigned int product_denom = 1;

	while (num < 100) {
	        unsigned int num_1st = num / 10;
		unsigned int num_2nd = num % 10;
		unsigned int denom = num + 1;

	        while (denom < 100) {
		        unsigned int denom_1st = denom / 10;
			unsigned int denom_2nd = denom % 10;

			double decimal = static_cast<double>(num) / denom;

			if (num_2nd == denom_1st && decimal == static_cast<double>(num_1st) / denom_2nd) {
				product_num *= num;
				product_denom *= denom;
			}

			++denom;
		}

		++num;
	}

	return product_denom / product_num;
}

int main(int argc, char* argv[])
{
        std::cout<<problem33()<<std::endl;
}
