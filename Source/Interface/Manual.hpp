#ifndef MANUAL_HPP
#define MANUAL_HPP
#include "Example.hpp"

BSTree<int, int> tree = BSTree<int, int>();
DynamicArray< pair<int, int> >* pairs;

using namespace std;

/*
int Question1()
{
    int q1;
    cout << "Create random? 0 = yes, 1 = no   ";
    cin >> q1;
    cout << endl;
    if(q1 == 0 || q1 == 1)
        return q1;
    else
    {
        cout << "Wrong input" << endl;
        return Question1();
    };
};

int Question2()
{
    int q2;
    cout << "Choose size(up to 30):   ";
    cin >> q2;
    cout << endl;
    if(q2 > 0 && q2 < 31)
        return q2;
    else
    {
        cout << "Wrong input" << endl;
        return Question2();
    };
};

int Question3()
{
    int q3;
    cout << "Choose data type:";
    cout << "   Enter '0' for integers:" << endl;
    cout << "   Enter '1' for strings:" << endl;
    cout << "   Enter '2' for complex:" << endl;
    cin >> q3;
    cout << endl;
    if(q3 > -1 && q3 < 3)
        return q3;
    else
    {
        cout << "Wrong input" << endl;
        return Question3();
    };
};

int Actions()
{
    int action = -1;
    cout << "Choose option:" << endl;
    cout << "   Enter '0' to exit:" << endl;
    cout << "   Enter '1' to PopBack:" << endl;
    cout << "   Enter '2' to PopFront:" << endl;
    cout << "   Enter '3' to PushBack:" << endl;
    cout << "   Enter '4' to PushFront:" << endl;
    cout << "   Enter '5' to SubDeck:" << endl;
    cout << "   Enter '6' to InsertAt:" << endl;
    cout << "   Enter '7' to RemoveAt:" << endl;
    cout << "   Enter '8' to PrintDeque:" << endl;
    cin >> action;
    if(action < 0 && action > 9)
    {
        cout << "Wrong input" << endl;
        return Actions();
    }
    else
        return action;
};*/


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
    cout << "Enter traverse type, like: lRr:  ";
    cin >> trav_t;
    cout << endl << "Tree, traversed " << trav_t << ':' << endl;
    tree.Traverse(trav_t, [](const int& a, int b){cout << a << ":  " << b << endl;});
};

void FillArray()
{
    int key, value;
    cout << "Keys - Values" << endl;
    for(int i = 0; i < pairs->GetLength(); i++)
    {
        cin >> key;
        cout << " - ";
        cin >> value;
        cout << endl;
        pairs->PushBack(make_pair(key, value));
    };
};

void Start()
{
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
            FillArray();
        }
        else

        {
            cout << "Wrong input" << endl;
            Start();
        };
    };
};

/*
template<class Container>
void Choises(Container* deque, int q3)
{
    void* x;
    int el_size = ElementSize(q3);
    int size;
    int index;
    int action = Actions();
    switch(action)
    {
        case 0:
            cout << "Exiting..." << endl;
            break;
        case 1:
            deque->PopBack();
            break;
        case 2:
            deque->PopFront();
            break;
        case 3:
            size = GetElement(q3, el_size, x);
            if(q3 == 0)
                deque->PushBack(IntFromBuffer(x));
            else
            {
                if(q3 == 1)
                    deque->PushBack(StringFromBuffer(x, size));
                else
                    deque->PushBack(ComplexFromBuffer(x));
            };
            break;
        case 4:
            size = GetElement(q3, el_size, x);
            if(q3 == 0)
                deque->PushFront(IntFromBuffer(x));
            else
            {
                if(q3 == 1)
                    deque->PushFront(StringFromBuffer(x, size));
                else
                    deque->PushFront(ComplexFromBuffer(x));
            };
            break;
        case 5:
            int from, to;
            cout << "from:  ";
            cin >> from;
            cout << " -> ";
            cin >> to;
            cout << endl;
            Container* subdeque = deque->SubDeck(from, to);
            if(q3 == 2)
                subdeque->PrintDequeForComplex();
            else
                subdeque->PrintDeque();
            break;
        case 6:
            size = GetElement(q3, el_size, x);
            cout << "at index:  ";
            cin >> index;
            cout << endl;
            if(q3 == 0)
                deque->InsertAt(index, IntFromBuffer(x));
            else
            {
                if(q3 == 1)
                    deque->InsertAt(index, StringFromBuffer(x, size));
                else
                    deque->InsertAt(index, ComplexFromBuffer(x));
            };
            break;
        case 7:
            cout << "at index:  ";
            cin >> index;
            cout << endl;
            deque->RemoveAt(index);
            break;
        case 8:
            cout << "Deque:" << endl;
            if(q3 == 2)
                deque->PrintDequeForComplex();
            else
                deque->PrintDeque();
            break;
        if(action != 0)
            Choises(deque, q3);
    };
};*/

void Manual()
{
    cout << "Manually Controlled Input:" << endl;
    Start();
    FillTree();
    PrintTree();
    tree.Clear();
    pairs->Clear();

    cout << endl << endl;
};

#endif // MANUAL_HPP
