#ifndef TESTPRIORITYQUEUE_HPP
#define TESTPRIORITYQUEUE_HPP
#include "../Basic/Test.hpp"
#include "../../Structures/PriorityQueue/PriorityQueue.hpp"
#include "../../Utility/Randomization/RandomGen.hpp"

using namespace std;

using Array = DynamicArray< pair<int, int> >;
using IndexArray = DynamicArray<int>;
using Queue = PriorityQueue<int, int>;

/*Check TestBTreeCreate()
{
    size_t seed = time(NULL);
    srand(seed);
    size_t size = rand() % 1000 + 1;
    seed++;
    Array* arr = IntPairArray(seed, size);
    Queue queue;
    int max_index = -100000;
    int max_value = -100000;
    for(size_t i = 0; i < arr->GetLength(); i++)
    {
        queue.Push(arr->Get(i).first, arr->Get(i).second);
        if(arr->Get(i).second > max_value)
        {
            max_value = arr->Get(i).first;
            max_index = arr->Get(i).first;
        };
    };
    if(queue.Size() != arr->GetLength())
        return ERROR;
    if(queue.Size() != arr->GetLength())
        return ERROR;
    delete arr;
    return NO_ERROR;
};

Check TestBTreeInsertFindEraseClearEmpty()
{
    size_t seed = time(NULL);
    srand(seed);
    size_t size = rand() % 1000 + 1;
    seed++;
    Array* arr = IntPairArray(seed, size);
    Tree* tree = new Tree();
    for(size_t i = 0; i < arr->GetLength(); i++)
        tree->Insert(arr->Get(i).first, arr->Get(i).second);
    if(tree->Size() != size)
        return ERROR;
    for(size_t i = 0; i < size; i++)
    {
        seed++;
        srand(seed);
        int r_key = rand() % size;
        if(!tree->Find(r_key))
            return ERROR;
    };
    for(size_t i = 0; i < size; i++)
        if(tree->Get(arr->Get(i).first) != arr->Get(i).second)
            return ERROR;
    int tmp = rand() % size;
    tree->Erase(tmp);
    if(tree->Find(tmp))
        return ERROR;
    tree->Clear();
    if(tree->Size() != 0 || !tree->Empty())
        return ERROR;
    delete arr;
    delete tree;
    return NO_ERROR;
};

/*Check TestBTreeMap()
{
    size_t seed = time(NULL);
    srand(seed);
    size_t size = rand() % 1000 + 1;
    seed++;
    Array* arr = IntPairArray(seed, size);
    //Array* copy = new Array(*arr);
    Tree* tree = new Tree();
    for(size_t i = 0; i < arr->GetLength(); i++)
        tree->Insert(arr->Get(i).first, arr->Get(i).second);
    *tree = tree->Map([](int x)
    {
        return x % 100;
    });
    if(tree->Size() != arr->GetLength())
        return ERROR;
    for(size_t i = 0; i < arr->GetLength(); i++)
        if(tree->Get(arr->Get(i).first) != arr->Get(i).second % 100)
            return ERROR;
    return NO_ERROR;
    delete arr;
    delete tree;
};*/

Check TestBTreeWhere()
{
    size_t seed = time(NULL);
    srand(seed);
    size_t size = rand() % 1000 + 1;
    size_t count = 0;
    seed++;
    Array* arr = IntPairArray(seed, size);
    Tree* tree = new Tree();
    for(size_t i = 0; i < size; i++)
    {
        tree->Insert(arr->Get(i).first, arr->Get(i).second);
        if(arr->Get(i).second < 0)
            count++;
    };
    *tree = tree->Where([](int x)
    {
        return x < 100;
    });
    if(tree->Size() != count)
        return ERROR;
    for(size_t i = 0; i < tree->Size(); i++)
        if(tree->Find(arr->Get(i).first))
            if(tree->Get(arr->Get(i).first >= 0))
                return ERROR;
    delete arr;
    delete tree;
    return NO_ERROR;
};

Check TestBTreeReduce()
{
    size_t seed = time(NULL);
    srand(seed);
    size_t size = rand() % 1000 + 1;
    int sum = 0;
    seed++;
    Array* arr = IntPairArray(seed, size);
    Tree* tree = new Tree();
    for(size_t i = 0; i < size; i++)
    {
        tree->Insert(arr->Get(i).first, arr->Get(i).second);
        sum += arr->Get(i).second;
    };
    int reduce = tree->Reduce(0, [](int x1, int x2)
    {
        return x1 + x2;
    });
    if(reduce != sum)
        return ERROR;
    return NO_ERROR;
    delete arr;
    delete tree;
};


Test* TestsPQueue()
{
    Test* test = new Test("priority queue");
    test->AddTest("Create Priority Queue", TestPQueueCreate);
    test->AddTest("Insert Find Erase Clear Empty Binary Tree", TestBTreeInsertFindEraseClearEmpty);
    //test->AddTest("Map Binary Tree", TestBTreeMap);
    //test->AddTest("Where Binary Tree", TestBTreeWhere);
    test->AddTest("Reduce Binary Tree", TestBTreeReduce);
    return test;
};*/

#endif // TESTSBINARYTREE_HPP
