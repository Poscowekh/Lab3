#ifndef INTERFACE_HPP
#define INTERFACE_HPP

using namespace std;

void ClearConsole();

/*void StartMenu()
{
    int choise = -1;
    cout << "Choose option:" << endl;
    cout << "   Enter '0' to exit:" << endl;
    cout << "   Enter '1' for example:" << endl;
    cout << "   Enter '2' for tests:" << endl;
    //cout << "   Enter '3' for manual input:" << endl;
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
        break;
        cout << "Wrong input" << endl;
        StartMenu();
        break;
    };
};*/

#endif // INTERFACE_HPP
