#include <iostream>

unsigned int ones[] = {
        0
      , sizeof "one"       - 1
      , sizeof "two"       - 1
      , sizeof "three"     - 1
      , sizeof "four"      - 1
      , sizeof "five"      - 1
      , sizeof "six"       - 1
      , sizeof "seven"     - 1
      , sizeof "eight"     - 1
      , sizeof "nine"      - 1
};

unsigned int teens[] = {
        sizeof "ten"       - 1
      , sizeof "eleven"    - 1
      , sizeof "twelve"    - 1
      , sizeof "thirteen"  - 1
      , sizeof "fourteen"  - 1
      , sizeof "fifteen"   - 1
      , sizeof "sixteen"   - 1
      , sizeof "seventeen" - 1
      , sizeof "eighteen"  - 1
      , sizeof "nineteen"  - 1
};

unsigned int deci[] = {
        0
      , sizeof "ten"       - 1
      , sizeof "twenty"    - 1
      , sizeof "thirty"    - 1
      , sizeof "forty"     - 1
      , sizeof "fifty"     - 1
      , sizeof "sixty"     - 1
      , sizeof "seventy"   - 1
      , sizeof "eighty"    - 1
      , sizeof "ninety"    - 1
};

unsigned int cent[] = {
        0
      , sizeof "hundred"   - 1
};

unsigned int kilo[] = {
        0
      , sizeof "thousand"  - 1
};

unsigned int misc[] = {
        sizeof "hundred"   - 1
      , sizeof "thousand"  - 1
};

unsigned int count_letters(unsigned int upper_bound)
{
        unsigned int count = 0;
	unsigned int i = 1;

        while (i <= upper_bound) {
	        unsigned int num = i;

		unsigned int thousands = num / 1000;

		count += ones[thousands];
		count += kilo[thousands != 0];
		num %= 1000;

		unsigned int hundreds = num / 100;

		count += ones[hundreds];
		count += cent[hundreds != 0];
		count += hundreds != 0 && num % 100 != 0 ? sizeof "and" - 1 : 0;
		num %= 100;

		unsigned int tens = num / 10;

		if (tens < 2)
		        count += tens == 0 ? ones[num % 10] : teens[num % 10];

		if (tens >= 2)
		        count += deci[tens] + ones[num % 10];

		++i;
	}

	return count;
}

int main(int argc, char* argv[])
{
        std::cout<<count_letters(1000)<<std::endl;
}
