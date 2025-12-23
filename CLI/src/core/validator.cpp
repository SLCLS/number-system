#include "common.hpp"

bool validator::valid_input(string &input, int base)
{
    string cleaned_input = remove_whitespace(input); // Remove whitespace.

    if (cleaned_input.empty()) // Check for empty input.
    {
        clog << "\nERROR: Input cannot be empty.\n";
        return false;
    }

    prefix_checking(cleaned_input, base); // Check for prefixes.

    if (!validate_syntax(cleaned_input, base)) // Final Syntax Validation.
    {
        return false;
    }

    input = cleaned_input; // Lazy refactoring malala.
    return true;
}

string validator::remove_whitespace(const string &input)
{
    string cleaned = "";

    for (char c : input)
    {
        if (c != ' ' && c != '\t' && c != '\n' && c != '\r')
        {
            cleaned += c;
        }
    }

    return cleaned;
}

void validator::prefix_checking(string &cleaned_input, int base)
{
    string prefix; char choice;
    int offset = 0;

    if (!cleaned_input.empty() && (cleaned_input[0] == '+' || cleaned_input[0] == '-'))
    {
        offset = 1; // Adjust offset if there's a sign.
    }

    if (cleaned_input.size() >= (2 + offset) && cleaned_input[offset] == '0')
    {
        prefix = cleaned_input.substr(offset, 2);

        bool isBin = (prefix == "0b" || prefix == "0B");
        bool isOct = (prefix == "0o" || prefix == "0O");
        bool isHex = (prefix == "0x" || prefix == "0X");

        bool detected = (isBin && base == 2) || (isOct && base == 8) || (isHex && base == 16);

        if (detected)
        {
            start_prefix:
            cout << "\nPrefix '" << prefix << "' detected. Crop prefix and proceed? [y/n]: ";
            std::cin >> choice;
            
            if (choice == 'y' || choice == 'Y')
            {
                cleaned_input.erase(offset, 2);
            }
            else if (choice == 'n' || choice == 'N')
            {
                cout << "\nNOTE: Proceeding without cropping prefix.\n";
                return;
            }
            else
            {
                clog << "\nERROR: Invalid choice. Please enter 'y' or 'n'.\n";
                system("PAUSE");
                goto start_prefix;
            }
        }
    }
}

bool validator::validate_syntax(string input, int base)
{
    if (input[0] == '-' || input[0] == '+') // Sign removal for easier syntax validation.
    {
        input.erase(0, 1);
    }

    if (input.empty()) // Check if the user only inputted a sign.
    {
        clog << "\nERROR: Input contains a sign but no numbers.\n";
        return false;
    }

    if (input == ".") // Check if the input is just a decimal point.
    {
         clog << "\nERROR: Input cannot be just a decimal point.\n";
         return false;
    }

    bool has_decimal = false;

    for (char c : input) // Check for multiple decimal points.
    {
        if (c == '.')
        {
            if (has_decimal) 
            {
                clog << "\nERROR: Multiple decimal points detected.\n";
                return false;
            }

            has_decimal = true;
            continue;
        }

        int digit_value = -1; // Sentinel value that resets every iteration.

        if (isdigit(c)) // Converting digit character from computer value to integer value [computer_value - '0' (ASCII)].
        {
            digit_value = c - '0';
        }
        else if (isalpha(c)) // Converting alphabet character to Upper case (toupper(c)) and then from computer value to integer value.
        {
            digit_value = toupper(c) - 'A' + 10;
        }

        if (digit_value == -1 || digit_value >= base) // digit_value == -1 ensures that invalid input is caught if it pass through the if conditions above.
        {
            clog << "\nERROR: Character '" << c << "' is not valid for Base " << base << ".\n";
            return false;
        }
    }

    return true;
}