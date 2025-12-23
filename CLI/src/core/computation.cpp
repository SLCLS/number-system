#include "common.hpp"

int computation::char_to_num(char character)
{
    if (character >= '0' && character <= '9')
    {
        return character - '0';
    }
    else
    {
        return toupper(character) - 'A' + 10; // toupper converts lowercase to uppercase.
    }
}

char computation::num_to_char(int number)
{
    if (number >= 0 && number <= 9)
    {
        return '0' + number;
    }
    else
    {
        return 'A' + (number - 10);
    }
}

double computation::to_decimal(const string original_input, int base)
{
    string input = original_input;

    bool is_negative = false;

    // Negative sign checking and temporary stripping.
    if (input[0] == '-')
    {
        is_negative = true;
        input = input.substr(1);
    }
    else if (input[0] == '+')
    {
        input = input.substr(1);
    }

    // Separating integer and fractional parts. "npos" stands for "no position".
    size_t decimal_point = input.find('.');
    string integer_part = (decimal_point == string::npos) ? input : input.substr(0, decimal_point);
    string fractional_part = (decimal_point == string::npos) ? "" : input.substr(decimal_point + 1);

    // Computation for integer part.
    double total_value = 0.0;

    for (char c : integer_part) // Horner's Method, instead of summation, we use logic. See notebook for formula. 
    {
        total_value = (total_value * base) + char_to_num(c);
    }

    // Computation for fractional part.
    double divisor = base;

    for (char c : fractional_part) {
        total_value += (char_to_num(c) / divisor);
        divisor *= base;
    }

    return is_negative ? -total_value : total_value;
}

string computation::from_decimal(double decimal_number, int target_base)
{
    if (decimal_number == 0)
    {
        return "0";
    }

    // Stripping negative sign temporarily for calculation.
    bool is_negative = false;
    if (decimal_number < 0) {
        is_negative = true;
        decimal_number = -decimal_number;
    }

    // Separating integer and fractional parts.
    double double_integer, fraction_part;
    fraction_part = modf(decimal_number, &double_integer); // Cmath "modf" function separates (e.g.) 10.5 into 10.0 and 0.5
    long long integer_part = (long long)double_integer; // '%' only works on integers, so we convert to long long.

    string result = "";

    // Integer Conversion.
    if (integer_part == 0)
    {
        result = "0";
    }
    else
    {
        while (integer_part > 0) // Same FEU Tech Formula for "from decimal" conversion.
        {
            int remainder = integer_part % target_base;
            result += num_to_char(remainder);
            integer_part /= target_base;
        }
        
        reverse(result.begin(), result.end()); // From left to right so we reverse.
    }

    // Fractional Conversion.
    if (fraction_part > 0)
    {
        result += ".";
        int precision_limit = 12; // Crash guard for infinite fractions (e.g. 1/3 in decimal is 0.3333...)

        while (fraction_part > 0 && precision_limit > 0) // Same FEU Tech formula.
        {
            fraction_part *= target_base;
            int digit = (int)fraction_part;
            result += num_to_char(digit);
            fraction_part -= digit;
            precision_limit--;
        }
    }

    if (is_negative)
    {
        result = "-" + result;
    }

    return result;
}

double computation::arithmetic(double num1, double num2, string operation)
{
    if (operation == "+") return num1 + num2;
    if (operation == "-") return num1 - num2;
    if (operation == "*") return num1 * num2;
    if (operation == "/") 
    {
        if (num2 == 0)
        {
            clog << "\nERROR: Division by zero is not allowed. Returning 0.\n";
            return 0;
        }
        return num1 / num2;
    }

    return 0; // Should not happen if validated
}

void computation::basic()
{
    system("CLS");
    cout << "\n***********************************************\n" << "            BASIC CALCULATOR MODULE            ";
    cout << "\n***********************************************\n" << "\n   Number System Options:\n";
    cout << "\n    [1] Decimal" << "\n    [2] Binary" << "\n    [3] Octal" << "\n    [4] Hexadecimal";
    cout << "\n\n***********************************************";
    cout << "\n------- Press 'X' to return to main menu ------\n" << "***********************************************\n";

    int base = utility::get_base_selection("\nSelect the number system for this operation: ");

    string num1_string, num2_string, operation;

    // Data Input with Validation.
    do
    {
        cout << "\nEnter first number: ";
        if (cin.peek() == '\n') cin.ignore();
        getline(cin, num1_string);
    }
    while (!validator::valid_input(num1_string, base));

    bool valid_operation = false;

    do
    {
        cout << "Enter operation (+, -, *, /): ";
        cin >> operation;
        if (operation == "+" || operation == "-" || operation == "*" || operation == "/") valid_operation = true;
        else clog << "ERROR: Invalid operator.\n";
    }
    while (!valid_operation);

    do
    {
        cout << "Enter second number: ";
        if (cin.peek() == '\n') cin.ignore();
        getline(cin, num2_string);
    }
    while (!validator::valid_input(num2_string, base));

    // Conversion to decimal for computation.
    double val1 = to_decimal(num1_string, base);
    double val2 = to_decimal(num2_string, base);

    // Computation.
    double result_val = computation::arithmetic(val1, val2, operation);

    // Conversion back to original base for output.
    string result_str = from_decimal(result_val, base);

    cout << "\n-----------------------------------------------";
    cout << "\nResult (" << num1_string << " " << operation << " " << num2_string << ") in Base " << base << " is:\n";
    cout << ">>    " << result_str << "   <<\n";
    cout << "-----------------------------------------------\n";
}

void computation::advanced()
{
    system("CLS");

    cout << "\n***********************************************\n" << "           ADVANCED CALCULATOR MODULE          ";
    cout << "\n***********************************************\n" << "\n   Number System Options:\n";
    cout << "\n    [1] Decimal" << "\n    [2] Binary" << "\n    [3] Octal" << "\n    [4] Hexadecimal";
    cout << "\n\n***********************************************";
    cout << "\n------- Press 'X' to return to main menu ------\n" << "***********************************************\n";

    string num1_string, num2_string, operation;

    // First Number.
    int base1 = utility::get_base_selection("\nSelect Base for First Number: ");
    do
    {
        cout << "Enter first number: ";
        if (cin.peek() == '\n') cin.ignore();
        getline(cin, num1_string);
    }
    while (!validator::valid_input(num1_string, base1));

    // Operation.
    bool valid_op = false;
    do
    {
        cout << "Enter operation (+, -, *, /): ";
        cin >> operation;
        if (operation == "+" || operation == "-" || operation == "*" || operation == "/") valid_op = true;
        else clog << "ERROR: Invalid operator.\n";
    }
    while (!valid_op);

    // Second Number.
    int base2 = utility::get_base_selection("\nSelect Base for Second Number: ");
    do
    {
        cout << "Enter second number: ";
        if (cin.peek() == '\n') cin.ignore();
        getline(cin, num2_string);
    }
    while (!validator::valid_input(num2_string, base2));

    // Target Base for Answer.
    int target_base = utility::get_base_selection("\nSelect Target Base for the Answer: ");

    // Convert to decimal for computation.
    double val1 = to_decimal(num1_string, base1);
    double val2 = to_decimal(num2_string, base2);

    // Computation.
    double result_value = computation::arithmetic(val1, val2, operation);

    // Convert back to target base for output.
    string result_string = from_decimal(result_value, target_base);

    cout << "\n-----------------------------------------------";
    cout << "\nCalculation: " << num1_string << " (Base " << base1 << ") " << operation << " " << num2_string << " (Base " << base2 << ")";
    cout << "\nResult in Base " << target_base << ":\n";
    cout << ">>    " << result_string << "    <<\n";
    cout << "-----------------------------------------------\n";
}