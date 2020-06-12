#ifndef RANDOMGEN_HPP
#define RANDOMGEN_HPP
#include <random>
#include "../DataTypes/Person.hpp"
#include "../DataTypes/Complex.hpp"
#include "../../Structures/Basic/DynamicArray.hpp"
#include <utility>

using namespace std;

int RandomInt(int seed)
{
    srand(seed);
    int r = rand() % 2000 - 1000;
    return r;
};

float RandomFloat(int seed)
{
    srand(seed);
    float tmp1 = (float)RandomInt(seed);
    seed = seed + RandomInt(seed);
    srand(seed);
    float tmp2 = (float)RandomInt(seed);
    float r = (tmp1 / tmp2);
    return r;
};

char RandomChar(int seed)
{
    srand(seed);
    char result = (char)(rand() % 94 + 33);
    return result;
};

char RandomLetter(int seed)
{
    srand(seed);
    char result = (char)('A' + rand() % 26);
    return result;
};

string RandomString(int seed, int size)
{
    string result;
    for(int i = 0; i < size; i++)
    {
        char tmp = RandomChar(seed);
        result.push_back(tmp);
        seed += RandomInt(seed);
    };
    return result;
};

string RandomLetterString(int seed, int size)
{
    string result;
    for(int i = 0; i < size; i++)
    {
        char tmp = RandomLetter(seed);
        result.push_back(tmp);
        seed += RandomInt(seed);
    };
    return result;
};

DynamicArray<int>* IntArray(int seed, int size)
{
    DynamicArray<int>* result = new DynamicArray<int>();
    srand(seed);
    for(int i = 0; i < size; i++)
    {
        result->PushFront(RandomInt(seed));
        seed = seed + RandomInt(seed);
        srand(seed);
    };
    return result;
};

DynamicArray<float>* FloatArray(int seed, int size)
{
    DynamicArray<float>* result = new DynamicArray<float>();
    srand(seed);
    for(int i = 0; i < size; i++)
    {
        result->PushFront(RandomFloat(seed));
        seed = seed + RandomInt(seed);
        srand(seed);
    };
    return result;
};

DynamicArray<string>* StringArray(int seed, int size, int string_size)
{
    DynamicArray<string>* result = new DynamicArray<string>();
    for(int i = 0; i < size; i++)
    {
        result->PushFront(RandomString(seed, string_size));
        seed += RandomInt(seed);
    };
    return result;
};

DynamicArray<string>* StringArray(int seed, int size)
{
    DynamicArray<string>* result = new DynamicArray<string>();
    srand(seed);
    int random_size;
    for(int i = 0; i < size; i++)
    {
        random_size = rand() % 3 + 3;
        result->PushFront(RandomString(seed, random_size));
        seed += RandomInt(seed);
        srand(seed);
    };
    return result;
};

DynamicArray<string>* LetterStringArray(int seed, int size)
{
    DynamicArray<string>* result = new DynamicArray<string>();
    srand(seed);
    int random_size;
    for(int i = 0; i < size; i++)
    {
        random_size = rand() % 10 + 3;
        string tmp = RandomLetterString(seed, random_size);
        result->PushBack(&tmp);
        seed += RandomInt(seed);
        srand(seed);
    };
    return result;
};

DynamicArray<string>* LetterStringArray(int seed, int size, int string_size)
{
    DynamicArray<string>* result = new DynamicArray<string>();
    for(int i = 0; i < size; i++)
    {
        string tmp = RandomLetterString(seed, string_size);
        result->PushBack(&tmp);
        seed = seed + RandomInt(seed);
    };
    return result;
};

DynamicArray< Complex<int, int> >* IntComplexArray(int seed, int size)
{
    DynamicArray< Complex<int, int> >* result = new DynamicArray< Complex<int, int> >();
    srand(seed);
    for(int i = 0; i < size; i++)
    {
        int tmp1 = RandomInt(seed);
        seed = seed + RandomInt(seed);
        srand(seed);
        int tmp2 = RandomInt(seed);
        seed = seed + RandomInt(seed);
        srand(seed);
        Complex<int, int> tmp(tmp1, tmp2);
        result->PushFront(tmp);
    };
    return result;
};

DynamicArray< Complex<float, float> >* FloatComplexArray(int seed, int size)
{
    DynamicArray< Complex<float, float> >* result = new DynamicArray< Complex<float, float> >();
    srand(seed);
    for(int i = 0; i < size; i++)
    {
        float tmp1 = RandomFloat(seed);
        seed = seed + RandomInt(seed);
        srand(seed);
        float tmp2 = RandomFloat(seed);
        seed = seed + RandomInt(seed);
        srand(seed);
        Complex<float, float> tmp(tmp1, tmp2);
        result->PushFront(tmp);
    };
    return result;
};

DynamicArray<int>* Indexes(int size)
{
    DynamicArray<int>* result = new DynamicArray<int>();
    for(int i = 0; i < size; i++)
        result->PushBack(i);
    return result;
};

template<typename DataType>
void Shuffle(DynamicArray<DataType>* array)
{
    int seed = time(NULL);
    srand(seed);
    int size = array->GetLength();
    int times = 5 * (rand() % size + 1);
    for(int i = 0; i < times; i++)
    {
        seed++;
        srand(seed);
        int index1 = rand() % size;
        seed++;
        srand(seed);
        int index2 = rand() % size;
        DataType tmp = array->Get(index1);
        array->Set(index1, array->Get(index2));
        array->Set(index2, tmp);
    };
};


DynamicArray< pair<int, int> >* IntPairArray(int seed, int size)
{
    DynamicArray< pair<int, int> >* result = new DynamicArray< pair<int, int> >();
    DynamicArray<int>* values = IntArray(seed, size);
    DynamicArray<int>* indexes = Indexes(size);
    Shuffle(indexes);
    for(int i = 0; i < size; i++)
        result->PushBack(make_pair(indexes->Get(i), values->Get(i)));
    return result;
};

DynamicArray<Person>* PersonArray(int seed, int size)
{
    DynamicArray<Person>* result = new DynamicArray<Person>();
    srand(seed);
    int id_count = 0;
    for(int i = 0; i < size; i++)
    {
        string f_name = RandomString(seed, 3);
        seed++;
        string m_name = RandomString(seed, 3);
        seed++;
        string l_name = RandomString(seed, 3);
        seed++;
        time_t b_day = time(NULL) + RandomInt(seed);
        seed++;
        size_t id = id_count;
        id_count++;
        Person* tmp = new Person(id, b_day, f_name, m_name, l_name);
        srand(seed);
        seed = seed - rand() % (seed / 2);
        result->PushFront(tmp);
    };
    return result;
};

#endif // RANDOMGEN_HPP
