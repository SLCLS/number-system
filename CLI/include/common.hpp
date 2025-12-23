#ifndef COMMON_HPP
#define COMMON_HPP

#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;

namespace validator
{
    bool valid_input(string &input, int base);                // Error check, Pass by reference on input for performance.
    string remove_whitespace(const string &input);            // Trim whitespace from input string, used inside valid_input function.
    void prefix_checking (string &cleaned_input, int base);   // Check for prefixes like 0b, 0o, 0x and ask user for confirmation.
    bool validate_syntax(string input, int base);             // Final syntax validation after prefix checking.
}

namespace navigation
{
    void menu(string &menu_option, int &option_case);                                                                // Main Menu
    void conversion(string &calculator_mode, int &calculator_case, bool &return_request);               // Conversion Menu
    void calculator(string &calculator_mode, int &calculator_case, bool &return_request);               // Calculator Menu
    void conversion_handler(int conversion_case, string &num1, string &target_base, string &result);    // Conversion Sub Menu
    void calculator_handler(int calculator_case);                                                       // Calculator Sub Menu
}

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
    double arithmetic(double num1, double num2, string operation);
}

namespace utility
{
    // Utility for Calculator (Prompt Helper)
    void calculator_help();
    int get_base_selection(string prompt);
}

// Colored output for errors and logs.
// Defined in logger.hpp :)

struct RedBuf : std::streambuf
{
    std::streambuf* dest;
    bool colored = false;

    RedBuf(std::streambuf* d) : dest(d) {}

    int overflow(int c) 
    override;
};

extern RedBuf redbuf_cerr;
extern RedBuf redbuf_clog;

#endif