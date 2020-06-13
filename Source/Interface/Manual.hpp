#ifndef MANUAL_HPP
#define MANUAL_HPP
#include "Example.hpp"

BSTree<int, int> tree = BSTree<int, int>();
DynamicArray< pair<int, int> >* pairs;
bool flag = true;

using namespace std;

void End()
{
    tree.Clear();
    pairs->Clear();
    flag = false;
    cout << endl << endl;
};

void SumReduce()
{
    int reduce = 0;
    reduce = tree.Reduce(0, [](int x1, int x2){return x1 + x2;});
    cout << endl << "Reduce=sum: " << reduce << endl << endl;
};

void InsertNew()
{
    int key, value;
    cout << endl << "Inserting..." << endl << " Key:  ";
    cin >> key;
    cout << " Value:  ";
    cin >> value;
    tree.Insert(key, value);
    cout << endl;
};

void FillTree()
{
    for(int i = 0; i < pairs->GetLength(); i++)
        tree.Insert(pairs->Get(i).first, pairs->Get(i).second);
};

void PrintArray()
{
    cout << "Keys - Values" << endl;
    for(int i = 0; i < pairs->GetLength(); i++)
        cout << pairs->Get(i).first << " - " << pairs->Get(i).second << endl;
};

void PrintTree()
{
    string trav_t;
    cout << endl << "Enter traverse type, like: lRr:  ";
    cin >> trav_t;
    cout << endl << "Tree, traversed " << trav_t << ':' << endl;
    tree.Traverse(trav_t, [](const int& a, int b){cout << b << ' ';});
    cout << endl << endl;
};

void FillArray(int size)
{
    int key, value;
    cout << "Keys - Values" << endl;
    for(int i = 0; i < size; i++)
    {
        cout << i << " Key:  ";
        cin >> key;
        if(i < 10)
            cout << "  Value:  ";
        else
            cout << "   Value:  ";
        cin >> value;
        pairs->PushBack(make_pair(key, value));
    };
    cout << endl;
};

void Start()
{
    pairs = new DynamicArray< pair<int, int> >();
    int seed, size, tmp;
    cout << "Create random?" << endl << "0 = yes, 1 = no:  ";
    cin >> tmp;
    cout << endl;
    if(tmp == 0)
    {
        cout << "Enter size:  ";
        cin >> size;
        cout << endl << "Enter seed:   ";
        cin >> seed;
        cout << endl;
        pairs = IntPairArray(seed, size);
        PrintArray();
    }
    else
    {
        if(tmp == 1)
        {
            cout << "Enter size:  ";
            cin >> size;
            cout << endl;
            FillArray(size);
        }
        else

        {
            cout << "Wrong input" << endl << endl;
            Start();
        };
    };
    flag = false;
    FillTree();
    PrintTree();
};

void CreateNew()
{
    End();
    Start();
};

void Subtree()
{
    int key = 0;
    string trav_t;
    cout << endl << "Choose key for root: ";
    cin >> key;
    cout << "Traverse type: ";
    cin >> trav_t;
    BSTree<int, int> subtree = tree.Subtree(key);
    cout << "Subtree size and height: " << subtree.Size() << ' ' << subtree.Height() << endl << "Subtree traverse to string:" << endl;
    cout << "  LeftRootRight:  " << subtree.ToString(trav_t) << endl << endl;
};

void Actions(int action)
{
    switch(action)
    {
    case 1:
        InsertNew();
        break;
    case 2:
        SumReduce();
        break;
    case 3:
        Subtree();
        break;
    case 4:
        CreateNew();
        break;
    case 5:
        PrintTree();
        break;
    };
};

void ActionChoise()
{
    if(flag)
        Start();
    int action = -1;
    cout << "Choose option:" << endl;
    cout << "   Enter '0' to exit:" << endl;
    cout << "   Enter '1' to Insert:" << endl;
    cout << "   Enter '2' to Sum-Reduce:" << endl;
    cout << "   Enter '3' to Subtree:" << endl;
    cout << "   Enter '4' to CreateNew:" << endl;
    cout << "   Enter '5' to PrintTraverse:" << endl;
    cout << "Chosen: ";
    cin >> action;
    if(action < 0 && action > 5)
    {
        cout << "Wrong input" << endl;
        return ActionChoise();
    }
    else
        if(action == 0)
            End();
        else
            Actions(action);
    ActionChoise();
};

void Manual()
{
    cout << "Manually Controlled Input:" << endl << endl;
    ActionChoise();
    cout << "Exited." << endl;
};

#endif // MANUAL_HPP
