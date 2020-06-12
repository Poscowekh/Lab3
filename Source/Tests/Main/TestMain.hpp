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


//DEQUE
/*
void TestDeque()
{
    Test* deque_test = new Test("deque");
    deque_test->AddTest("Create Deque", TestDequeCreate);
    deque_test->AddTest("Set/Get Deque", TestDequeSetGet);
    deque_test->AddTest("Push/Pop Deque", TestDequePushPop);
    deque_test->AddTest("InsertAt/RemoveAt Deque", TestDequeInsertRemove);
    deque_test->AddTest("SubDeque", TestSubdeque);
    deque_test->AddTest("Concate Deques", TestDequeConcate);
    deque_test->AddTest("Map Deque", TestDequeMap);
    deque_test->AddTest("Where Deque", TestDequeWhere);
    deque_test->AddTest("Reduce Deque", TestDequeReduce);
    deque_test->AddTest("Sort Deque", TestDequeSort);
    deque_test->RunTests();
};
*/

void Tests()
{
    cout << endl << "RUNNING TESTS" << endl;
    TestEngine* tests = CreateTests();
    tests->RunTests();

    delete tests;
    cout << endl << endl;
};

#endif // TESTMAIN_HPP
