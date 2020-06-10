#ifndef TESTSNODE_HPP
#define TESTSNODE_HPP
#include "../../Structures/Basic/Node.hpp"
#include "../Basic/Test.hpp"
#include "../../Utility/Randomization/RandomGen.hpp"
#include <time.h>

using namespace std;

Check TestNodeCreate()
{
    int seed = time(NULL);
    Node<int, int>* node;
    for(int i = 0; i < 1000; i++)
    {
        int* data = &(RandomInt)

        node = new Node<int, int>();
    };
    delete node;
};

Check TestNodeRightLeft()
{

};

Check TestNodeKeyData()
{

}


Test* CreateNodeTests()
{
    Test* test = new Test("node");
    return test;
};

#endif // TESTNODE_HPP
