#ifndef MANUAL_HPP
#define MANUAL_HPP
#include "../Examples/Example.hpp"

/*using namespace std;

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

Deque<int>* IntDeque(int size, int q1)
{
    Deque<int>* result;
    DynamicArray<int>* arr = new DynamicArray<int>();
    if(q1 == 0)
    {
        int seed;
        cout << "seed:  ";
        cin >> seed;
        cout << endl;
        arr = IntArray(seed, size);
        result = new Deque<int>(arr);
        result->PrintDeque();
    }
    else
    {
        for(int i = 0; i < size; i++)
        {
            int x;
            cout << i << ": ";
            cin >>  x;
            cout << endl;
            arr->PushBack(x);
        };
        result = new Deque<int>(arr);
    };
    cout << endl;
    return result;
};

Deque<string>* StringDeque(int size, int q1)
{
    Deque<string>* result;
    DynamicArray<string>* arr = new DynamicArray<string>();
    if(q1 == 0)
    {
        int seed;
        cout << "seed:  ";
        cin >> seed;
        cout << endl;
        arr = StringArray(seed, size);
        result = new Deque<string>(arr);
        result->PrintDeque();
    }
    else
    {
        for(int i = 0; i < size; i++)
        {
            string x;
            cout << i << ": ";
            cin >>  x;
            cout << endl;
            arr->PushBack(x);
        };
        result = new Deque<string>(arr);
    };
    cout << endl;
    return result;
};

Deque< Complex<int,int> >* ComplexDeque(int size, int q1)
{
    Deque< Complex<int,int> >* result;
    DynamicArray< Complex<int,int> >* arr = new DynamicArray< Complex<int,int> >();
    if(q1 == 0)
    {
        int seed;
        cout << "seed:  ";
        cin >> seed;
        cout << endl;
        arr = IntComplexArray(seed, size);
        result = new Deque< Complex<int,int> >(arr);
    }
    else
    {
        for(int i = 0; i < size; i++)
        {
            int x1, x2;
            cout << i << ": (";
            cin >>  x1;
            cout << ") +i (";
            cin >> x2;
            cout << ")" << endl;
            Complex<int,int> x(x1, x2);
            arr->PushBack(x);
        };
        result = new Deque< Complex<int,int> >(arr);
    };
    cout << endl;
    return result;
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
};

int ElementSize(int q3)
{
    int x = 0;
    switch(q3)
    {
        case 0:
            x = sizeof(int);
            break;
        case 1:
            x = sizeof(string);
            break;
        case 2:
            x = sizeof(Complex<int, int>);
            break;
    };
    return x;
};

int GetElement(int q3, int el_size, void* buffer)
{
    int size = 0;
    cout << "Enter element:  ";
    if(q3 == 2)
    {
        int x1, x2;
        cout << "(";
        cin >> x1;
        cout << ") +i (";
        cin >> x2;
        cout << ")" << endl;
        buffer = malloc(el_size);
        memcpy(buffer, &x1, sizeof(int));
        memcpy(buffer, &x2, sizeof(int));
    }
    else
    {
        if(q3 == 0)
        {
            int x;
            cin >> x;
            cout << endl;
            buffer = malloc(el_size);
            memcpy(buffer, &x, el_size);
        }
        else
        {
            string x;
            cin >> x;
            cout << endl;
            size = x.size();
            memcpy(buffer, &x, el_size);
        };
    };
    return size;
};

int IntFromBuffer(void* buffer)
{
    int* x;
    memcpy((void*)x, buffer, sizeof(int));
    return *x;
};

string StringFromBuffer(void* buffer, int size)
{
    string x;
    for(int i = 0; i < size; i++)
        x.push_back(*((char*)buffer + i));
    return x;
};

Complex<int, int> ComplexFromBuffer(void* buffer)
{
    Complex<int, int> result(*((int*)buffer), *((int*)buffer + sizeof(int)));
    return result;
};

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
};

void Manual()
{
    Deque<int>* int_deque;
    Deque<string>* str_deque;
    Deque< Complex<int, int> >* comp_deque;
    int q1 = -1;
    int q2 = -1;
    int q3 = -1;
    q1 = Question1();
    q2 = Question2();
    q3 = Question3();
    /*if(q3 == 0)
    {
        int_deque = IntDeque(q2, q1);
        Choises(int_deque, q3);
    }
    else
    {
        if(q3 == 1)
        {
            str_deque = StringDeque(q2, q1);
            Choises(str_deque, q3);
        }
        else
        {
            comp_deque = ComplexDeque(q2, q1);
            Choises(comp_deque, q3);
        };
    };
};*/

#endif // MANUAL_HPP
