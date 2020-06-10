#ifndef RANDOMGEN_HPP
#define RANDOMGEN_HPP
#include <random>
#include "../DataTypes/Person.hpp"
#include "../DataTypes/Complex.hpp"
#include "../../Structures/Basic/DynamicArray.hpp"

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
    char result = (char)(rand() % (127 - 33) + 33);
    return result;
};

char RandomLetter(int seed)
{
    srand(seed);
    char result = ('A' + rand() % 26);
    return result;
};

char* RandomString(int seed, int size)
{
    char* result = (char*)malloc(sizeof(char) * size);
    for(int i = 0; i < size; i++)
    {
        char tmp = RandomChar(seed);
        memcpy(result + i, &tmp, sizeof(char));
        seed = seed + RandomInt(seed);
    };
    return result;
};

char* RandomLetterString(int seed, int size)
{
    char* result = (char*)malloc(sizeof(char) * size);
    for(int i = 0; i < size; i++)
    {
        char tmp = RandomLetter(seed);
        memcpy(result + i, &tmp, sizeof(char));
        seed = seed + RandomInt(seed);
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

DynamicArray<char*>* StringArray(int seed, int size, int string_size)
{
    DynamicArray<char*>* result = new DynamicArray<char*>();
    srand(seed);
    for(int i = 0; i < size; i++)
    {
        result->PushFront(RandomString(seed, string_size));
        seed = seed + RandomInt(seed);
        srand(seed);
    };
    return result;
};

DynamicArray<char*>* StringArray(int seed, int size)
{
    DynamicArray<char*>* result = new DynamicArray<char*>();
    srand(seed);
    int random_size = rand() % 3 + 3;
    for(int i = 0; i < size; i++)
    {
        result->PushFront(RandomString(seed, random_size));
        seed = seed + RandomInt(seed);
        srand(seed);
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

DynamicArray<Person>* PersonArray(int seed, int size)
{
    DynamicArray<Person>* result = new DynamicArray<Person>();
    srand(seed);
    int id_count = 0;
    for(int i = 0; i < size; i++)
    {
        char* f_name = RandomString(seed, 3);
        seed++;
        char* m_name = RandomString(seed, 3);
        seed++;
        char* l_name = RandomString(seed, 3);
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
