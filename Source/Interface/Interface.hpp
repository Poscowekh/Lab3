#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include "Example.hpp"
#include "Manual.hpp"
#include "../Tests/Main/TestMain.hpp"

using namespace std;

void ClearConsole()
{
    for(int i = 0; i < 50; i++)
        cout << endl;
};

void StartMenu()
{
    int choise = -1;
    cout << "Choose option:" << endl;
    cout << "   Enter '0' to exit:" << endl;
    cout << "   Enter '1' for example:" << endl;
    cout << "   Enter '2' for tests:" << endl;
    cout << "   Enter '3' for manual input:" << endl;
    cout << "Chosen:  ";
    cin >> choise;
    switch(choise)
    {
        case 0:
            cout << "Exiting..." << endl;
            exit(0);
        break;
        case 1:
            cout << "Running example..." << endl;
            Example();
            getchar();
            StartMenu();
        break;
        case 2:
            Tests();
            getchar();
            StartMenu();
        break;
        case 3:
            Manual();
            getchar();
            StartMenu();
        break;
        cout << "Wrong input" << endl;
        StartMenu();
        break;
    };
};

#endif // INTERFACE_HPP
