//MAP WHERE REDUCE BASIC RANDOM VARIANTS TO BE HERE
#ifndef RANDOMTESTFUNCTIONS_HPP
#define RANDOMTESTFUNCTIONS_HPP
#include "../../Utility/Randomization/RandomGen.hpp"

using namespace std;

template<typename NumType>
NumType Sum(NumType x1, NumType x2)
{
    return x1 + x2;
};

template<typename NumType>
NumType Subtract(NumType x1, NumType x2)
{
    return x1 - x2;
};

template<typename NumType>
NumType Square(NumType x)
{
    return x * x;
};

template<typename NumType>
NumType Divide(NumType x1, NumType x2)
{
    return x1 / x2;
};

template<typename NumType>
NumType Multiply(NumType x1, NumType x2)
{
    return x1 * x2;
};

template<typename NumType>
NumType RandReduce(NumType x1, NumType x2)
{
    int seed = time(NULL);
    float a = RandomFloat(seed);
    seed++;
    float b = RandomFloat(seed);
    srand(seed);
    int r = rand() % 12;
    switch(r)
    {
        case 0:
            return Sum<NumType, NumType>(a * x1, b * x2);
        case 1:
            return Sum<NumType, NumType>(b * x1, a * x2);
        case 2:
            return Subtract<NumType, NumType>(a * x1, b * x2);
        case 3:
            return Subtract<NumType, NumType>(b * x1, a * x2);
        case 4:
            return Subtract<NumType, NumType>(a * x2, b * x1);
        case 5:
            return Subtract<NumType, NumType>(b * x2, a * x1);
        case 6:
            return Multiply<NumType, NumType>(a * x1, b * x2);
        case 7:
            return Multiply<NumType, NumType>(b * x1, a * x2);
        case 8:
            return Divide<NumType, NumType>(a * x1, b * x2);
        case 9:
            return Divide<NumType, NumType>(b * x1, a * x2);
        case 10:
            return Divide<NumType, NumType>(a * x2, b * x1);
        case 11:
            return Divide<NumType, NumType>(b * x2, a * x1);
    };
};

//NumType RandMap(NumType x);
//NumType RandWhere(NumType x1); //etc

#endif // RANDOMTESTFUNCTIONS_HPP
