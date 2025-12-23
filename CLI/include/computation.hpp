#ifndef COMPUTATION_HPP
#define COMPUTATION_HPP

#include <string>
using std::string;

namespace computation
{
    // Utility functions
    int char_to_num(char character);
    char num_to_char(int number);

    // Main Conversion Functions
    double to_decimal(const string original_input, int base);
    string from_decimal(double decimal_number, int target_base);

    // Calculator functions
    void basic();
    void advanced();
    double arithmethic(double num1, double num2, string operation);
}

#endif