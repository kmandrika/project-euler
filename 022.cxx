#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <boost/tokenizer.hpp>

using namespace std;
using namespace boost;

typedef    pair<string, unsigned int>    name_value;
typedef    char_separator<char>          separator_t;

unsigned int alphabetical_value(const string& name)
{
        return accumulate(name.begin(), name.end(), 0) - name.size() * 64;
}

void read(ifstream& file, vector<name_value>& names)
{
        static separator_t comma(",");

	string line;

	while (getline(file, line)) {
	        tokenizer<separator_t> tokens(line, comma);

		tokenizer<separator_t>::const_iterator i = tokens.begin();
		tokenizer<separator_t>::const_iterator e = tokens.end();

		while (i != e) {
		        string stripped_name(i->begin() + 1, i->begin() + i->length() - 1);

			names.push_back(make_pair(
                                stripped_name
			      , alphabetical_value(stripped_name)
                        ));

			++i;
		}
	}
}

struct name_value_pred {
        bool operator ()(const name_value& lhs, const name_value& rhs) const {
	        return lhs.first < rhs.first;
	}
};

unsigned int get_sum(const char* filename)
{
        unsigned int sum = 0;

	vector<name_value> names;
	ifstream file(filename, fstream::in);

	if (file) {
	        read(file, names);

	        sort(names.begin(), names.end(), name_value_pred());

		vector<name_value>::iterator i = names.begin();
		vector<name_value>::iterator e = names.end();

		while (i != e)
		        sum += i->second * (distance(names.begin(), i++) + 1);
	}

	return sum;
}

int main(int argc, char* argv[])
{
        cout<<get_sum("names.txt")<<endl;
}
