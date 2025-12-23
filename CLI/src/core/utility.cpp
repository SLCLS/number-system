#include "common.hpp"

int utility::get_base_selection(string prompt)
{
    string choice;
    int base = 0;
    bool valid = false;

    do
    {
        cout << prompt;
        cin >> choice;

        if (choice == "1") { base = 10; valid = true; }       // Decimal
        else if (choice == "2") { base = 2; valid = true; }   // Binary
        else if (choice == "3") { base = 8; valid = true; }   // Octal
        else if (choice == "4") { base = 16; valid = true; }  // Hex
        else
        {
            clog << "\nERROR: Invalid choice. Enter 1 (Dec), 2 (Bin), 3 (Oct), or 4 (Hex).\n";
            std::cin.clear();
            if (std::cin.peek() == '\n') std::cin.ignore();
        }
    } while (!valid);

    return base;
}

void utility::calculator_help()
{
    cout << "\n***********************************************\n" << "          CALCULATOR MODE HELP SECTION         ";
    cout << "\n***********************************************\n" << "\n [1] Basic Arithmetic Mode:\n";
    cout << " 1. Performs addition, subtraction, division,\n";
    cout << " and multiplication (basic arithmetic).\n";
    cout << " 2. Operation only support same number system.\n";
    cout << "\n [1] Advanced Arithmetic Mode:\n";
    cout << " 1. Performs addition, subtraction, division,\n";
    cout << " and multiplication (basic arithmetic).\n";
    cout << " 2. Supports different number system\n";
    cout << " 3. Answers in preferred number system.\n";
    cout << "\n\n***********************************************";
    cout << "\n>>>>>>     Press any key to continue     <<<<<<\n" << "***********************************************\n\n";
}