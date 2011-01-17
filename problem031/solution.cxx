#include <iostream>

static unsigned int coins[] = { 0, 1, 2, 5, 10, 20, 50, 100 };

unsigned int C(int total, int coin_index)
{
        if (total == 0)
                return 1;

        if (total < 0)
                return 0;

        if (total >= 1 && coin_index <= 0)
                return 0;

        return C(total, coin_index - 1) + C(total - coins[coin_index], coin_index);
}

unsigned int problem31()
{
        return 1 + C(200, 7);
}

int main(int argc, char* argv[])
{
        std::cout<<problem31()<<std::endl;
}
