#ifndef TREE_HPP
#define TREE_HPP
#include "../Basic/Node.hpp"
#include "../Basic/DynamicArray.hpp"

using namespace std;

template<typename DataType, typename KeyType>
class Tree
{
    private:
        Node<DataType, KeyType>* root;
        size_t size;
    public:
        Tree()
        {
            root = 0;
            size = 0;
        };
        Tree(const Tree& other)
        {
            root = other.root;
            size = other.size;
        };
        bool Empty()
        {
            if(size > 0)
                return false;
            else
                return true;
        };
        size_t Size()
        {
            return size;
        };
        void Add(DataType* data, KeyType* key)
        {
            Node<DataType, KeyType>* node = new Node<DataType, KeyType>(data, key);

        };
        ~Tree(){};
};

#endif // TREE_HPP
