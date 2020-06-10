#ifndef TEST_HPP
#define TEST_HPP
#include "Check.h"
#include <iostream>
#include "TestFunctions.hpp"

using namespace std;

class Test
{
    private:
        void Realloc(int new_size)
        {
            TestFunction<Check>* tmp = (TestFunction<Check>*)malloc(new_size * el_size);
            memcpy(tmp, functions, count * el_size);
            free(functions);
            functions = tmp;
        };
        int el_size;
        int errors;
        string name;
        TestFunction<Check>* functions;
        int count;
    public:
        Test(string test_name)
        {
            name = test_name;
            count = 0;
            functions = 0;
            errors = 0;
            el_size = sizeof(TestFunction<Check>);
        };
        void AddTest(string func_name, Check(*const func)())
        {
            TestFunction<Check>* new_func = new TestFunction<Check>(func_name, func);
            Realloc(count + 1);
            memcpy(functions + count, new_func, el_size);
            count++;
        };
        void RunTests()
        {
            Check check;
            TestFunction<Check>* tmp;
            cout << "   Testing " << name << "..." << endl;
            for(int i = 0; i < count; i++)
            {
                tmp = functions + i;
                check = tmp->function();
                cout << "       " << "Test " << i + 1 << ": " << tmp->function_name << " - ";
                if(check == ERROR)
                {
                    errors++;
                    //overall_errors++;
                    cout << "error" << endl;
                }
                else
                    cout << "no errors" << endl;
            };
            cout << "   Test finished";
            if(errors > 0)
                cout << "with " << errors << " errors." << endl;
            else
                cout << " succesfully." << endl;
        };
};

#endif // TEST_HPP
