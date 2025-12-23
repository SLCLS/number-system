#include "common.hpp"

// Main Menu
void navigation::menu(string &menu_option, int &option_case)
{
    system("CLS");
    cout << "\n***********************************************\n" << "     NUMBER SYSTEM CONVERSION & CALCULATOR     ";
    cout << "\n***********************************************\n";
    cout << "\n    [1] Number System Conversion" << "\n    [2] Number System Calculator";
    cout << "\n\n***********************************************";
    cout << "\n-------- Press 'X' to exit the program --------\n" << "***********************************************\n";
    cout << "\nChoose a menu option: ";

    std::cin >> menu_option;

    while (menu_option != "1" && menu_option != "2" && menu_option != "X" && menu_option != "x")
    {
        clog << "\nERROR: Invalid input, please choose a valid menu option.\n";
        system("PAUSE");
        system("CLS");
        navigation::menu(menu_option, option_case);
    }

    if (menu_option == "1")
    {
        option_case = 1;
    }
    else if (menu_option == "2")
    {
        option_case = 2;
    }
    else if (menu_option == "X" || menu_option == "x")
    {
        option_case = 3;
    }
}

// Conversion Menu
void navigation::conversion(string &conversion_option, int &conversion_case, bool &return_request)
{
    system("CLS");

    start_conversion:

    cout << "\n***********************************************\n" << "        NUMBER SYSTEM CONVERSION MODULE        ";
    cout << "\n***********************************************\n" << "\n     Select the number system:\n";
    cout << "\n    [1] Decimal" << "\n    [2] Binary" << "\n    [3] Octal" << "\n    [4] Hexadecimal";
    cout << "\n\n***********************************************";
    cout << "\n------- Press 'X' to return to main menu ------\n" << "***********************************************\n";
    cout << "\nPlease choose a number system: ";

    std::cin >> conversion_option;

    while (conversion_option != "1" && conversion_option != "2" && conversion_option != "3" && conversion_option != "4" && conversion_option != "X" && conversion_option != "x")
    {
        clog << "\nERROR: Invalid input, please choose a valid conversion option.\n";
        system ("PAUSE"); system ("CLS");
        goto start_conversion;
    }

    if (conversion_option == "1")
    {
        conversion_case = 1;
    }
    else if (conversion_option == "2")
    {
        conversion_case = 2;
    }
    else if (conversion_option == "3")
    {
        conversion_case = 3;
    }
    else if (conversion_option == "4")
    {
        conversion_case = 4;
    }
    else if (conversion_option == "X" || conversion_option == "x")
    {
        system("CLS");
        return_request = true;
        return;
    }
}

// Calculator Menu
void navigation::calculator(string &calculator_mode, int &calculator_case, bool &return_request)
{
    system("CLS");

    start_calculator:
    cout << "\n***********************************************\n" << "        NUMBER SYSTEM CALCULATOR MODULE        ";
    cout << "\n***********************************************\n" << "\n   Please select the calculator mode:\n";
    cout << "\n    [1] Basic Arithmetic" << "\n    [2] Advanced Mode" << "\n    [3] Help (What's the difference?)";
    cout << "\n\n***********************************************";
    cout << "\n------- Press 'X' to return to main menu ------\n" << "***********************************************\n";
    cout << "\nChoose a menu option: ";

    std::cin >> calculator_mode;

    while (calculator_mode != "1" && calculator_mode != "2" && calculator_mode != "3" && calculator_mode != "X" && calculator_mode != "x")
    {
        clog << "\nERROR: Invalid input, please choose a valid calculator mode.\n";
        system("PAUSE");
    	system("CLS");
        goto start_calculator;
    }

    if (calculator_mode == "1")
    {
        calculator_case = 1;
    }
    else if (calculator_mode == "2")
    {
        calculator_case = 2;
    }
    else if (calculator_mode == "3")
    {
        system("CLS");
        utility::calculator_help();
        system("PAUSE");
        system("CLS");
        goto start_calculator;
    }
    else if (calculator_mode == "X" || calculator_mode == "x")
    {
        system("CLS");
        return_request = true;
        return;
    }
}

//
void navigation::conversion_handler(int conversion_case, string &num1, string &target_base, string &result)
{
    int source_base_int = 0;

    start_conversion_handler:

    cout << "\n***********************************************\n" << "        NUMBER SYSTEM CONVERSION MODULE        ";
    cout << "\n***********************************************\n" << "\n     Select the number system:\n";
    cout << "\n    [1] Decimal" << "\n    [2] Binary" << "\n    [3] Octal" << "\n    [4] Hexadecimal";
    cout << "\n\n***********************************************";
    cout << "\n------- Press 'X' to return to main menu ------\n" << "***********************************************\n\n";

    switch (conversion_case) // Error checking & Input Cleaning.
    {
        case 1: // Decimal Conversion
            source_base_int = 10;
            do
            {
                cout << "Enter decimal number: ";

                if (std::cin.peek() == '\n') std::cin.ignore(); // Clears enter key, prevents skipped input on next iteration.
                std::getline(std::cin, num1);
            }
            while (!validator::valid_input(num1, 10));
            break;
        
        case 2: // Binary Conversion
            source_base_int = 2;
            do
            {
                cout << "Enter binary number: ";

                if (std::cin.peek() == '\n') std::cin.ignore();
                std::getline(std::cin, num1);
            }
            while (!validator::valid_input(num1, 2));
            break;
        
        case 3: // Octal Conversion
            source_base_int = 8;
            do
            {
                cout << "Enter octal number: ";

                if (std::cin.peek() == '\n') std::cin.ignore();
                std::getline(std::cin, num1);
            }
            while (!validator::valid_input(num1, 8));
            break;
        
        case 4: // Hexadecimal Conversion
            source_base_int = 16;
            do
            {
                cout << "Enter hexadecimal number: ";

                if (std::cin.peek() == '\n') std::cin.ignore();
                std::getline(std::cin, num1);
            }
            while (!validator::valid_input(num1, 16));
            break;
        
        default: // Fail-safe
            cerr << "\nWARNING: An unexpected error occurred in conversion handler.\n" << "Press any key to restart the program...\n";
            system("PAUSE");
            system("CLS");
            goto start_conversion_handler;
            break;
    }

    // Target Base Selection.
    int target_base_int = 0;
    bool valid_target = false;

    do
    {
        cout << "\nEnter target number system (1-4): ";
        std::cin >> target_base;

        if (target_base == "1") 
        {
            target_base_int = 10; // Choice 1 -> Base 10, Decimal.
            valid_target = true;
        }
        else if (target_base == "2") 
        {
            target_base_int = 2;  // Choice 2 -> Base 2, Binary.
            valid_target = true;
        }
        else if (target_base == "3") 
        {
            target_base_int = 8;  // Choice 3 -> Base 8, Octal.
            valid_target = true;
        }
        else if (target_base == "4") 
        {
            target_base_int = 16; // Choice 4 -> Base 16, Hexadecimal.
            valid_target = true;
        }
        else 
        {
            clog << "\nERROR: Invalid choice. Please enter 1 (Dec), 2 (Bin), 3 (Oct), or 4 (Hex).\n";
            std::cin.clear();
            if (std::cin.peek() == '\n') std::cin.ignore();
        }

        if (valid_target && target_base_int == source_base_int) {
             cout << "NOTE: Source and Target bases are the same. Result will be identical.\n";
        }
    
    } while (!valid_target);

    // Conversion Process
    double decimal_value = computation::to_decimal(num1, source_base_int);
    result = computation::from_decimal(decimal_value, target_base_int);
}

void navigation::calculator_handler(int calculator_case)
{
    start_calculator_handler:
    switch (calculator_case)
    {
        case 1: // Basic Arithmetic Module
            computation::basic();
            break;
        case 2: // Advanced Mode Module
            computation::advanced();
            break;
        default: // Fail-safe
            cerr << "\nWARNING: An unexpected error occurred in calculator handler.\n" << "Press any key to restart the program...\n";
            system("PAUSE");
            system("CLS");
            goto start_calculator_handler;
            break;
    }
}