#ifndef EXAMPLE_HPP
#define EXAMPLE_HPP
#include "../Structures/PriorityQueue/PriorityQueue.hpp"
#include "../Utility/Randomization/RandomGen.hpp"
#include "../Utility/GlobalFlags.hpp"

using namespace std;

void Example()
{
    //debug_flag = true;
    time_t arr_st, arr_end, tree_st, tree_end;
    int seed = time(NULL);
    int size = 12;
    //if(debug_flag)
    //    arr_st = time(NULL);
    DynamicArray< pair<int, int> >* arr = IntPairArray(seed, size);
    cout << "Array of random pairs of keys and values:" << endl;
    cout << "Indexes:" << endl;
    for(int i = 0; i < arr->GetLength(); i++)
        cout <<  arr->Get(i).first << ' ';
    cout << endl << "Values:" << endl;
    for(int i = 0; i < arr->GetLength(); i++)
        cout <<  arr->Get(i).second << ' ';
    cout << endl;
    //if(debug_flag)
    //    arr_end = time(NULL);
    //if(debug_flag)
    //    tree_st = time(NULL);
    BSTree<int, int> tree = BSTree<int, int>();
    for(int i = 0; i < arr->GetLength(); i++)
        tree.Insert(arr->Get(i).first, arr->Get(i).second);
    cout << endl << "Tree size and height: " << tree.Size() << ' ' << tree.Height() << endl << "Tree traverse to string:" << endl;
    cout << "  LeftRootRight:  " << tree.ToString("lRr") << endl;
    cout << "  RightRootLeft:  " << tree.ToString("rRl") << endl;
    cout << "  RootLeftRight:  " << tree.ToString("Rlr") << endl;
    cout << "  RootRightLeft:  " << tree.ToString("Rrl") << endl;
    tree.Erase(4);
    tree.Erase(7);
    cout << "Erased 4 and 7:" << endl;
    cout << "  " << tree.ToString("lRr") << endl;
    //if(debug_flag)
    //{
    //    tree_end = time(NULL);
    //    cout << "~Time Data:" << endl << "   Array: " << arr_end-arr_st << endl << "   Tree: " << tree_end-tree_st << endl;
    //};
    BSTree<int, int> subtree = tree.Subtree(6);
    cout << endl << "Subtree size and height: " << subtree.Size() << ' ' << subtree.Height() << endl << "Subtree traverse to string:" << endl;
    cout << "  LeftRootRight:  " << subtree.ToString("lRr") << endl;
    int reduce = tree.Reduce(0, [](int x1, int x2){return x1 + x2;});
    cout << endl << "Reduce=sum: " << reduce << endl;
    //subtree = tree.Map([](int x){return x % 100;});
    //cout << endl << "Map=(x % 100): " << endl;
    //cout << "  LeftRootRight:  " << subtree.ToString("lRr") << endl;
    cout << endl << "Priority Queue:" << endl;
    PriorityQueue<int, int> queue;
    queue.SetType("MAX");
    for(size_t i = 0; i < arr->GetLength(); i++)
        queue.Push(arr->Get(i).first, arr->Get(i).second);
    while(!queue.Empty())
        cout << queue.Pop() << ' ';

    cout << endl << endl;
};

#endif // EXAMPLE_HPP
