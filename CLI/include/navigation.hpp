#ifndef NAVIGATION_HPP
#define NAVIGATION_HPP

#include <string>
using std::string;

namespace navigation
{
    void menu(string &menu_option, int);                                                                // Main Menu
    void conversion(string &calculator_mode, int &calculator_case, bool &return_request);               // Conversion Menu
    void calculator(string &calculator_mode, int &calculator_case, bool &return_request);               // Calculator Menu
    void conversion_handler(int conversion_case, string &num1, string &target_base, string &result);    // Conversion Sub Menu
    void calculator_handler(int calculator_case);                                                       // Calculator Sub Menu
}

#endif