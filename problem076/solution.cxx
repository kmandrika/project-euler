#include <iostream>
#include <map>
#include <utility>

unsigned long long C(int n, int m)
{
        static std::map<std::pair<int, int>, unsigned long long> cache;
        std::map<std::pair<int, int>, unsigned long long>::const_iterator cached;

        if ((cached = cache.find(std::make_pair(n, m))) != cache.end())
                return cached->second;

        if (n == 0)
                return 1;

        if (n <  0)
                return 0;

        if (n >= 1 && m <= 0)
                return 0;

        return cache[std::make_pair(n, m)] = C(n, m - 1) + C(n - m, m);
}


unsigned long long problem76()
{
        return C(100, 100 - 1);
}

int main(int argc, char* argv[])
{
        std::cout<<problem76()<<std::endl;
}
