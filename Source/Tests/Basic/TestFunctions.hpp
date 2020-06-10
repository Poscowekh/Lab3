#ifndef TESTFUNCTIONS_HPP
#define TESTFUNCTIONS_HPP
#include <string>

using namespace std;

template<class ReturnType, class ArgumentType>
class TestFunctionWithArgs
{
    public:
        string function_name;
        ReturnType(*const function(ArgumentType))();
        ReturnType operator()()
        {
            return function();
        };
        TestFunctionWithArgs(string func_name, ReturnType(*const func(ArgumentType))())
        {
            function_name = func_name;
            function = func;
        };
};

template<class ReturnType>
class TestFunction
{
    public:
        string function_name;
        ReturnType(*function)() = 0;
        ReturnType operator()()
        {
            return function();
        };
        TestFunction(string func_name, ReturnType(*const func)())
        {
            function_name = func_name;
            function = func;
        };
};

#endif // TESTFUNCTIONS_HPP
