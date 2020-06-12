#include "../Structures/Trees/Tree.hpp"
#include "../Utility/DataTypes/FunctionArray.hpp"
#include "../Utility/Randomization/RandomGen.hpp"
#include <iostream>

#include "../Tests/Main/TestMain.hpp"

using namespace std;

int main()
{
    //debug_flag = true;
    //Tests();
    time_t arr_st, arr_end, tree_st, tree_end;
    int seed = time(NULL);
    int size = 15;
    if(debug_flag)
        arr_st = time(NULL);
    DynamicArray< pair<int, int> >* arr = IntPairArray(seed, size);
    cout << "Array of random pairs of keys and values:" << endl;
    for(int i = 0; i < arr->GetLength(); i++)
        cout << arr->Get(i).first << ": " << arr->Get(i).second << endl;
    if(debug_flag)
        arr_end = time(NULL);
    if(debug_flag)
        tree_st = time(NULL);
    BSTree<int, int> tree = BSTree<int, int>();
    for(int i = 0; i < arr->GetLength(); i++)
        tree.Insert(arr->Get(i).first, arr->Get(i).second);
    cout << endl << "Tree size and height: " << tree.Size() << ' ' << tree.Height() << endl << "Tree traverse to string:" << endl;
    cout << "  LeftRootRight:  " << tree.ToString("lRr") << endl;
    cout << "  RightRootLeft:  " << tree.ToString("rRl") << endl;
    cout << "  RootLeftRight:  " << tree.ToString("Rlr") << endl;
    cout << "  RootRightLeft:  " << tree.ToString("Rrl") << endl;
    if(debug_flag)
    {
        tree_end = time(NULL);
        cout << "~Time Data:" << endl << "   Array: " << arr_end-arr_st << endl << "   Tree: " << tree_end-tree_st << endl;
    };
    BSTree<int, int> subtree = tree.Subtree(6);
    cout << endl << "Subtree size and height: " << subtree.Size() << ' ' << subtree.Height() << endl << "Subtree traverse to string:" << endl;
    cout << "  LeftRootRight:  " << subtree.ToString("lRr") << endl;
    //Tree<string, int> subtree;
    /*if(debug_flag)
        cout << "Insert paths" << endl;
    srand(seed);
    int size = rand() % 11 + 5;
    for(int i = 0; i < size; i++)
    {
        int key;
        if(i < size / 2)
            key = i;
        else
            key = -i;
        tree.Insert(RandomLetterString(seed, 1), key);
        seed = RandomInt(seed);
    };
    /*tree.Insert("B", 7);
    tree.Insert("C", -10);
    tree.Insert("D", 6);
    tree.Insert("E", 10);
    tree.Insert("F", 13);
    tree.Insert("G", -4);
    tree.Insert("H", -6);
    tree.Insert("I", 3);
    tree.Insert("J", 0);
    tree.Insert("K", -2);
    tree.Insert("L", 1);
    tree.Insert("M", -5);*/
    /*srand(seed);
    cout << endl << "Tree:\n  Size: " << tree.Size() << ",\n  Heigth: " << tree.Height() << endl;
    cout << endl << "Tree traversal:" << endl;
    tree.Traverse(tree.LRtR, [](string &str, const int &key){cout << key << ": " << str << endl;});
    tree.Traverse(tree.RRtL, [](string &str, const int &key){cout << key << ": " << str << endl;});*/
    /*subtree = tree.SubTree(-size / 2);
    cout << endl << "Subtree:\n  Size: " << subtree.Size() << "\n  Heigth: " << subtree.Height() << endl;
    cout << endl << "Subtree traversal:" << endl;
    subtree.Traverse(tree.LRtR, [](string &str, const int &key){cout << key << ": " << str << endl;});*/
    return 0;
};
