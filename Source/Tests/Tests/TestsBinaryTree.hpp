#ifndef TESTSBINARYTREE_HPP
#define TESTSBINARYTREE_HPP
#include "../Basic/Test.hpp"
#include "../../Structures/Trees/Tree.hpp"
#include "../../Utility/Randomization/RandomGen.hpp"

using namespace std;

using Array = DynamicArray< pair<int, int> >;
using IndexArray = DynamicArray<int>;
using Tree = BSTree<int, int>;

Check TestBTreeCreate()
{
    size_t seed = time(NULL);
    srand(seed);
    size_t size = rand() % 1000 + 1;
    seed++;
    Array* arr = IntPairArray(seed, size);
    Tree* tree = new Tree();
    for(size_t i = 0; i < size; i++)
        tree->Insert(arr->Get(i).first, arr->Get(i).second);
    Tree* tree_copy = new Tree(*tree);
    if(tree_copy->Size() != size)
        return ERROR;
    if(tree->Size() != size)
        return ERROR;
    for(size_t i = 0; i < size; i++)
        if(tree->Get(i) != tree_copy->Get(i))
            return ERROR;
    delete arr;
    delete tree;
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
    for(size_t i = 0; i < size; i++)
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

Test* TestsBinaryTree()
{
    Test* test = new Test("binary tree");
    test->AddTest("Create Binary Tree", TestBTreeCreate);
    test->AddTest("Insert Find Erase Clear Empty Binary Tree", TestBTreeInsertFindEraseClearEmpty);
    return test;
};

#endif // TESTSBINARYTREE_HPP
