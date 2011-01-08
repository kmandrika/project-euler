#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <iterator>

namespace detail {

struct triangle_t {
        triangle_t(const char* filename) {
	        std::ifstream stream(filename, std::fstream::in);

		read(stream);
	}

        unsigned int& operator [](unsigned int i) {
	        return triangle_[i];
	}

private:
        void read(std::ifstream& stream) {
	        if (!stream)
		        throw std::runtime_error("couldn't open");

		std::string line;

		while (std::getline(stream, line)) {
		        std::stringstream s(line);
			std::istream_iterator<unsigned int> i = s;
			std::istream_iterator<unsigned int> e;

			triangle_.insert(triangle_.end(), i, e);
		}
		    
	}

private:
        std::vector<unsigned int> triangle_;
};

}

unsigned int get_triangle_number(unsigned int n)
{
        return n * (n + 1) / 2;
}

unsigned int& get_value_at(detail::triangle_t& triangle, unsigned int level, unsigned int num)
{
        return triangle[get_triangle_number(level + 1) - (level + 1) + num];
}

unsigned int max_sum(detail::triangle_t& triangle, unsigned int level)
{
	while (level--) {
	        unsigned int pos = 0;

		while (pos <= level) {
		        get_value_at(triangle, level, pos) += std::max(
                                get_value_at(triangle, level + 1, pos)
			      , get_value_at(triangle, level + 1, pos + 1)
			);

			++pos;
		}
	}

	return get_value_at(triangle, 0, 0);
}

unsigned int problem67()
{
        detail::triangle_t triangle("triangle.txt");

	return max_sum(triangle, 100 - 1);
}

int main(int argc, char* argv[])
{

        std::cout<<problem67()<<std::endl;
}
