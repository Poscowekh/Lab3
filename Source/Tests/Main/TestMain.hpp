#ifndef TESTMAIN_HPP
#define TESTMAIN_HPP
#include "../Basic/TestEngine.hpp"
#include "../Tests/TestsArray.hpp"
#include "../Tests/TestsBinaryTree.hpp"

using namespace std;

TestEngine* CreateTests()
{
    TestEngine* tests = new TestEngine();
    tests->AddTest(TestArray());
    tests->AddTest(TestsBinaryTree());
    return tests;
};

void Tests()
{
    cout << endl << "RUNNING TESTS" << endl;
    TestEngine* tests = CreateTests();
    tests->RunTests();

    delete tests;
    cout << endl << endl;
};

#endif // TESTMAIN_HPP
