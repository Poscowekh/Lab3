#ifndef TESTENGINE_HPP
#define TESTENGINE_HPP
#include "Test.hpp"

using namespace std;

class TestEngine
{
    private:
        int overall_errors = 0;
        int test_count;
        Test* tests;
        int el_size;
        void Realloc()
        {
            Test* tmp = (Test*)malloc((test_count + 1) * el_size);
            memcpy(tmp, tests, test_count * el_size);
            tests = tmp;
        };
    public:
        TestEngine()
        {
            el_size = sizeof(Test);
            tests = 0;
        };
        void AddTest(Test* new_test)
        {
            Realloc();
            memcpy(tests + test_count, new_test, el_size);
            test_count++;
        };
        void RunTests()
        {
            cout << "RUNNING ALL TESTS" << endl;
            for(int i = 0; i < test_count; i++)
            {
                cout << "TEST " << i + 1 << ":" << endl;
                overall_errors += (tests + i)->RunTests();
            };
            cout << "TESTS FINISHED:  ";
            if(overall_errors > 0)
                cout << overall_errors << " errors found." << endl;
            else
                cout << "no errors found." << endl;
            overall_errors = 0;
        };
};

#endif // TESTENGINE_HPP
