#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <fstream>
#include <stdexcept>
#include <numeric>
#include <cmath>
#include <cfloat>
#include <boost/tokenizer.hpp>

using namespace std;
using namespace boost;

namespace detail {

typedef    pair<string, unsigned int>    name_value;
typedef    char_separator<char>          separator_t;

unsigned int alphabetical_value(const string& word)
{
        return accumulate(word.begin(), word.end(), 0) - word.size() * 64;
}

struct words_t {
        typedef vector<name_value>::const_iterator const_iterator;

        words_t(const char* filename) {
	        ifstream stream(filename, fstream::in);
		read(stream);
	}

        const name_value& operator [](unsigned int i) const {
	        return words_[i];
	}

        const_iterator begin() const {
	        return words_.begin();
	}

        const_iterator end() const {
	        return words_.end();
	}

private:
        void read(ifstream& stream) {
	        if (!stream)
		        throw runtime_error("couldn't open");

		static separator_t comma(",");

		string line;

		while (getline(stream, line)) {
		        tokenizer<separator_t> tokens(line, comma);

			tokenizer<separator_t>::const_iterator i = tokens.begin();
			tokenizer<separator_t>::const_iterator e = tokens.end();

			while (i != e) {
			        string stripped_word(
                                        i->begin() + 1
				      , i->begin() + i->length() - 1
                                );

				words_.push_back(make_pair(
                                        stripped_word
				      , alphabetical_value(stripped_word)
				));

				++i;
			}
		}
	}

        std::vector<name_value> words_;
};

bool is_triangle_number(unsigned int n)
{
        double root = (-1 + sqrt(1.0 + 8.0 * n)) / 2.0;
	return root - floor(root) < 4 * DBL_EPSILON;
}

}

unsigned int count_triangle_words(const ::detail::words_t& words)
{
        unsigned int count = 0;

        ::detail::words_t::const_iterator i = words.begin();
	::detail::words_t::const_iterator e = words.end();

	while (i != e) {
	        if (::detail::is_triangle_number(i->second))
		        ++count;
		++i;
	}

	return count;
}

int main(int argc, char* argv[])
{
        cout<<count_triangle_words(::detail::words_t("words.txt"))<<endl;
}
