#include <iostream>

//! month is 1 based, assumed to be 1 <= month <= 12
unsigned char days_in_month(unsigned char month, unsigned int year)
{
        static unsigned char days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return days[month - 1] + (
                month == 2 ?
                year % 4 != 0 ? 0 :
		year % 1000 == 0 ? year % 400 == 0 ? 1 : 0 : 1 : 0
        );
}

unsigned int count_sundays_on(unsigned int year, unsigned int& offset)
{
        unsigned int count = 0;
	unsigned int month = 1;

	while (month <= 12) {
		if (offset == 7)
		        ++count;

		if ((offset = (days_in_month(month, year) % 7 + offset) % 7) == 0)
		        offset = 7;

		++month;
	}

	return count;
}


unsigned int count_sundays(unsigned int from_year, unsigned int day_of_first, unsigned int to_year)
{
	unsigned int count = 0;

	//! what day did the 1st of jan of the next year
	//  fall on?
	count_sundays_on(from_year++, day_of_first);

	while (from_year <= to_year)
	        count += count_sundays_on(from_year++, day_of_first);

	return count;
}


int main(int argc, char* argv[])
{
        std::cout<<count_sundays(1900, 1, 2000)<<std::endl;
}
