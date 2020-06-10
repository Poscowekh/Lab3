/*ENGINE WILL BE HERE
 *SHOULD UNITE ALL IN ONE TEST TO RUN
 */
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
        const int el_size = sizeof(Test);
        void Realloc()
        {
            Test* tmp = (Test*)malloc(test_count * el_size);
            memcpy(tmp, tests, test_count * el_size);
            tests = tmp;
        };
    public:
        TestEngine()
        {
            tests = 0;
        };
        void AddTest(Test* new_test)
        {
            Realloc();
            memcpy(tests, new_test, el_size);
            test_count++;
        };
        void RunTests()
        {
            cout << "RUNNING ALL TESTS" << endl;
            for(int i = 0; i < test_count; i++)
            {
                cout << "TEST " << i << ":" << endl;
                (tests + i)->RunTests();
            };
            cout << "TESTS FINISHED";
            if(overall_errors > 0)
                cout << ":" << endl << overall_errors << " errors found." << endl;
            else
                cout << ":" << "No errors found." << endl;
            overall_errors = 0;
        };
};

#endif // TESTENGINE_HPP
