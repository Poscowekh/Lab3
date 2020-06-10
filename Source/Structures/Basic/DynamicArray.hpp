#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP
#include <mem.h>
#include <stdlib.h>
#include "../../Utility/Exceptions/Exception.hpp"

using namespace std;

template<typename DataType>
class DynamicArray
{
    private:
        int length;
        int element_size;
        bool empty;
        DataType* data;
        void Allocate(int new_length)
        {
            data = 0;
            length = new_length;
            data = (DataType*)malloc(element_size * length);
        };
        void Reallocate(int new_length)
        {
            length = new_length;
            DataType* tmp = NewDataPointer(length);
            memcpy(tmp, data, element_size * length);
            data = tmp;
        };
        DataType* NewDataPointer(int new_length)
        {
            DataType* tmp = (DataType*)malloc(element_size * new_length);
            return tmp;
        };
        void CheckEmpty()
        {
            if(length > 0)
                empty = false;
            else
                empty = true;
        };
        void CheckIndex(int index)
        {
            if(index < 0 || index + 1 > length)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
        };
        void CheckIndex(int index1, int index2)
        {
            if(index1 < 0 || index1 + 1 > length || index2 < 0 || index2 + 1 > length)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
        };
        void CheckNegative(int value)
        {
            if(value < 0)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
        };
        void CheckPointer(DataType* pointer)
        {
            if(pointer == 0)
            {
                try{
                    throw 2;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
        };
        DataType* GetPointer(int index)
        {
            CheckIndex(index);
            DataType* tmp = data + index;
            CheckPointer(tmp);
            return tmp;
        };
    public:
        DynamicArray()
        {
            element_size = sizeof(DataType);
            Allocate(0);
            empty = true;
        };
        DynamicArray(int new_length)
        {
            element_size = sizeof(DataType);
            Allocate(new_length);
            empty = true;
        };
        DynamicArray(DataType* new_data, int count)
        {
            CheckNegative(count);
            element_size = sizeof(DataType);
            Allocate(count);
            memcpy(data, new_data, element_size * length);
            CheckEmpty();
        };
        DynamicArray(const DynamicArray<DataType>& array)
        {
            element_size = array.element_size;
            Allocate(array.length);
            memcpy(data, array.data, element_size * length);
            CheckEmpty();
        };
        int GetLength()
        {
            return length;
        };
        int GetElementSize()
        {
            return element_size;
        };
        DataType Front()
        {
            CheckNegative(length - 1);
            CheckPointer(data);
            return *data;
        };
        DataType* DataPointer()
        {
            return data;
        };
        DataType Get(int index)
        {
            return *GetPointer(index);
        };
        DataType Back()
        {
            CheckNegative(length - 1);
            return *GetPointer(length - 1);
        };
        void CopyToArray(DataType* new_data, int from, int count)
        {
            //CheckIndex(from, count);
            /*if(from + count - 1 > length)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };*/
            int old_length = length;
            Reallocate(length + count);
            memcpy(data + old_length, new_data + from, element_size * count);
            CheckEmpty();
        };  
        void Set(int index, DataType* new_data)
        {   //One elememnt
            CheckIndex(index);
            memcpy(data + index, new_data, element_size);
            empty = false;
        };
        void Set(int index, DataType new_data)
        {
            Set(index, &new_data);
        };
        void PopBack()
        {
            CheckNegative(length - 1);
            Reallocate(length - 1);
            if(length == 0)
                empty = true;
        };
        void PushBack(DataType* new_data)
        {
            Reallocate(length + 1);
            memcpy(data + length - 1, new_data, element_size);
            empty = false;
        };
        void PushBack(DataType new_data)
        {
            PushBack(&new_data);
        };
        void PopFront()
        {
            CheckNegative(length - 1);
            DataType* tmp = NewDataPointer(length - 1);
            memcpy(tmp, data + 1, element_size * (length - 1));
            data = tmp;
            length--;
            CheckEmpty();
        };
        void PushFront(DataType* new_data)
        {
            DataType* tmp = NewDataPointer(length + 1);
            memcpy(tmp, new_data, element_size);
            memcpy(tmp + 1, data, element_size * length);
            data = tmp;
            length++;
            CheckEmpty();
        };
        void PushFront(DataType new_data)
        {
            PushFront(&new_data);
        };
        void Resize(int new_length)
        {
            CheckNegative(new_length - 1);
            Reallocate(new_length);
            CheckEmpty();
        };
        void RemoveAt(int index)
        {
            CheckIndex(index);
            if(index == 0)
                PopFront();
            else
            {
                if(index == length - 1)
                    PopBack();
                else
                {
                    DataType* tmp = NewDataPointer(length - 1);
                    memcpy(tmp, data, element_size * index);
                    memcpy(tmp + index, data + index + 1, element_size * (length - index));
                    data = tmp;
                    length--;
                };
            };
            CheckEmpty();
        };
        void InsertAt(DataType* new_data, int index)
        {
            CheckIndex(index);
            if(index == 0)
                PushFront(new_data);
            else
            {
                DataType* tmp = NewDataPointer(length + 1);
                memcpy(tmp, data, index * element_size);
                memcpy(tmp + index, new_data, element_size);
                memcpy(tmp + index + 1, data + index, element_size * (length - index));
                data = tmp;
                length++;
            };
            CheckEmpty();
        };
        void InsertAt(DataType new_data, int index)
        {
            InsertAt(&new_data, index);
        };
        void Clear()
        {
            free((void*)data);
            Reallocate(0);
            length = 0;
            empty = true;
        };
        void Sort()
        {
            for(int i = 0; i < length; i++)
                for(int j = 0; j < length - 1; j++)
                    if(Get(j) < Get(j + 1))
                    {
                        DataType tmp = Get(j);
                        Set(j, Get(j + 1));
                        Set(j + 1, tmp);
                    };
        };
        void Concate(const DynamicArray<DataType>& array)
        {
            CopyToArray(array.data, 0, array.length);
        };
        void Concate(const DynamicArray<DataType>& array1, const DynamicArray<DataType>& array2)
        {
            CopyToArray(array1.data, 0, array1.length);
            CopyToArray(array2.data, 0, array2.length);
        };
        DynamicArray<DataType>* GetConcated(const DynamicArray<DataType>& array)
        {
            DynamicArray<DataType>* result = new DynamicArray<DataType>(*this);
            result->Concate(array);
            return result;
        };
        DynamicArray<DataType>* GetConcated(const DynamicArray<DataType>& array1, const DynamicArray<DataType>& array2)
        {
            DynamicArray<DataType>* result = new DynamicArray<DataType>(this);
            result->Concate(array1);
            result->Concate(array2);
            return result;
        };
        DataType& operator[](const int index)
        {
            return *GetPointer(index);
        };
        DynamicArray<DataType>* GetSubArray(int from, int to)
        {
            CheckIndex(from, to);
            if(to - from + 1 > length)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            DynamicArray<DataType>* result = new DynamicArray<DataType>(data + from, to - from + 1);
            return result;
        };
        DynamicArray<DataType>* operator+(const DynamicArray<DataType>& array)
        {
            DynamicArray<DataType>* result = new DynamicArray<DataType>(this);
            result->Concate(array);
            return result;
        };
        DynamicArray<DataType>* operator+=(DataType new_data)
        {
            this->PushBack(new_data);
            return this;
        };
        DynamicArray<DataType>* operator+=(DataType* new_data)
        {
            return operator+=(&new_data);
        };
        DynamicArray<DataType>* operator-(int cut)
        {
            for(int i = 0; i < cut; i++)
                this->PopBack();
            return this;
        };
        DynamicArray<DataType>* operator--()
        {
            this->PopBack();
            return this;
        };
        bool operator==(const DynamicArray<DataType>& array)
        {
            if(length == 0 && array.length == 0)
                return true;
            if(length != array.length)
                return false;
            DataType* tmp1 = data;
            DataType* tmp2 = array.data;
            for(int i = 0; i < length; i++)
            {
                tmp1 = tmp1 + i;
                tmp2 = tmp2 + i;
                if(tmp1 != tmp2)
                    return false;
            };
            return true;
        };
        bool operator!=(const DynamicArray<DataType>& array)
        {
            return !(this == array);
        };
        bool operator>(const DynamicArray<DataType>& array)
        {
            return (length > array.length);
        };
        bool operator<(const DynamicArray<DataType>& array)
        {
            return (length < array.length);
        };
        bool operator>=(const DynamicArray<DataType>& array)
        {
            return (length >= array.length);
        };
        bool operator<=(const DynamicArray<DataType>& array)
        {
            return (length <= array.length);
        };
        bool Empty()
        {
            return empty;
        };
        ~DynamicArray(){};
};

#endif // DYNAMICARRAY_HPP
