#include "common.hpp"

int main()
{
    // Red logs and errors for main.
    std::cerr.rdbuf(&redbuf_cerr);
    std::clog.rdbuf(&redbuf_clog);
    
    cout << "\n***********************************************\n" << "----->>>>>>>     MADE BY SLCLS     <<<<<<<-----";
    cout << "\n***********************************************\n" << "       https://github.com/SLCLS/WORKSPACE      ";
    cout << "\n***********************************************\n" << ">>>>>>     Press any key to continue     <<<<<<\n\n\n\n";
    system("PAUSE"); system("CLS");

    start_main:

    string menu_option; int option_case;            // Main menu variables
    string conversion_option, calculator_mode;      // Sub-menu option variables
    string exit_option;                             // Exit option variable
    int conversion_case, calculator_case;           // Sub-menu switch variables 
    bool return_request = false;                    // Return request to main menu
    string num1, num2, target_base, result;         // Calculation variables

    num1 = ""; num2 = ""; target_base = ""; result = "";    // Reset variables upon start_main execution

    navigation::menu(menu_option, option_case);   // Main menu

    start_logic:

    // Main menu selection switch
    switch (option_case)
    {
        case 1:     // Conversion Menu
        navigation::conversion(conversion_option, conversion_case, return_request);
        break;

        case 2:     // Calculator Menu
        navigation::calculator(calculator_mode, calculator_case, return_request);
        break;

        case 3:     // Exit Program option
        cout << "\nExiting the program...\n";
        system("PAUSE");
        return 0;
        break;

        default:    // Fail-safe default
        cerr << "\nWARNING: An unexpected error occured.\n" << "Press any key to restart the program...\n";
        system("PAUSE"); system("CLS");
        goto start_main;
        break;
    }

    // Sub-menu return request
    if (return_request == true)
    {
        return_request = false;
        goto start_logic;
    }

    // Sub-menu Selection
    if (option_case == 1)
    {
        system("CLS");
        navigation::conversion_handler(conversion_case, num1, target_base, result);
        cout << "\nResult: " << result << "\n";
    }
    else if (option_case == 2)
    {
        system("CLS");
        navigation::calculator_handler(calculator_case);
    }

    // Exit Prompt
    cout << "\n***********************************************";
    cout << "\n Enter 'B' to go back to Number System Menu...\n";
    cout << " Enter any other key to return to Main Menu...";
    cout << "\n***********************************************\n";
    cout << "\nPlease choose your action: ";
    cin >> exit_option;

    if (exit_option == "B" || exit_option == "b")
    {
        system("CLS");
        num1 = ""; num2 = ""; target_base = ""; result = "";
        goto start_logic;
    }
    else
    {
        system("CLS");
        goto start_main;
    }

    return 0;
}