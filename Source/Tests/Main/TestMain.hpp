#ifndef TESTMAIN_HPP
#define TESTMAIN_HPP
/*#include "../Tests/TestsArray.hpp"
#include "../Tests/TestsList.hpp"
#include "../Tests/TestsSequence.hpp"
#include "../Tests/TestsDeque.hpp"*/
#include "../Basic/TestEngine.hpp"
#include "../Tests/TestsNode.hpp"
//#include "../Basic/TestEngine.hpp"

void CreateTests()
{
    TestEngine* tests = new TestEngine();
    //tests->AddTest()
};

using namespace std;
/*
//Array
void TestArray()
{
    Test* array_test = new Test("array");
    array_test->AddTest("Create Array", TestArrayCreate);
    array_test->AddTest("Set/Get Array", TestArraySetGet);
    array_test->AddTest("Push/Pop Array", TestArrayPushPop);
    array_test->AddTest("InsertAt/RemoveAt Array", TestArrayInsertRemove);
    array_test->AddTest("SubArray", TestSubArray);
    array_test->AddTest("Concate Arrays", TestArrayConcate);
    array_test->RunTests();
    cout << endl;
};

//List
void TestList()
{
    Test* list_test = new Test("list");
    list_test->AddTest("Create List", TestListCreate);
    list_test->AddTest("Set/Get List", TestListSetGet);
    list_test->AddTest("Push/Pop List", TestListPushPop);
    list_test->AddTest("InsertAt/RemoveAt List", TestListInsertRemove);
    list_test->AddTest("SubList", TestSublist);
    list_test->AddTest("Concate Lists", TestListConcate);
    list_test->RunTests();
    cout << endl;
};

//SEQUENCE
void TestSequence() //Tests for LinkedListSequence only
{
    Test* sequence_test = new Test("sequence");
    sequence_test->AddTest("Create Sequence", TestSequenceCreate);
    sequence_test->AddTest("Set/Get Sequence", TestSequenceSetGet);
    sequence_test->AddTest("Push/Pop Sequence", TestSequencePushPop);   //Append&Prepend
    sequence_test->AddTest("InsertAt/RemoveAt Sequence", TestSequenceInsertRemove);
    sequence_test->AddTest("SubSequence", TestSubsequence);
    sequence_test->AddTest("Concate Sequences", TestSequenceConcate);
    sequence_test->RunTests();
    cout << endl;
};

//DEQUE
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
    /*TestArray();
    TestList();
    TestSequence();
    TestDeque();*/
    getchar();
};

#endif // TESTMAIN_HPP
