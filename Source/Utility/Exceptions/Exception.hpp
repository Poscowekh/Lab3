#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP
#include <iostream>

using namespace std;

class Exception
{
    public:
        Exception(const int code)
        {
            switch(code)
            {
                case 0:
                    cout << "Error code 0: Index out of range!" << endl;
                    break;
                case 1:
                    cout << "Error code 1: Wrong Length!" << endl;
                    break;
                case 2:
                    cout << "Error code 2: Null pointer!" << endl;
                    break;
                exit(code + 1000);
            };
        };
};

#endif // EXCEPTION_HPP
