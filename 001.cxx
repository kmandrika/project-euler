#include <iostream>

unsigned int sum(unsigned int bound) {
    unsigned int _03s = bound / 3;
    unsigned int _05s = bound / 5 - 1;
    unsigned int _15s = bound / 15;
   

    return
	3  * _03s * (_03s + 1) / 2 +
	5  * _05s * (_05s + 1) / 2 -
	15 * _15s * (_15s + 1) / 2;
}

int main(int argc, char* argv[])
{
    std::cout<<sum(1000)<<std::endl;
}
