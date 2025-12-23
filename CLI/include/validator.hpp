#ifndef VALIDATOR_HPP
#define VALIDATOR_HPP

#include <string>
using std::string;

namespace validator
{
    bool valid_input(string &input, int base);                // Error check, Pass by reference on input for performance.
    string remove_whitespace(const string &input);            // Trim whitespace from input string, used inside valid_input function.
    void prefix_checking (string &cleaned_input, int base);   // Check for prefixes like 0b, 0o, 0x and ask user for confirmation.
    bool validate_syntax(string input, int base);             // Final syntax validation after prefix checking.
}

#endif