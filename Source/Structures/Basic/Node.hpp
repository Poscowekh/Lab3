#ifndef NODE_HPP
#define NODE_HPP

using namespace std;

template<typename DataType, typename KeyType>
class Node
{
    private:
        DataType* data;
        KeyType* key;
        int height;
        Node* left;
        Node* right;
    public:
        Node()
        {
            data = key = left = right = 0;
            height = 0;
        };
        Node(const Node* other)
        {
            key = other->key;
            height = other->height;
            data = other->data;
            left = other->left;
            right = other->right;
        };
        Node(DataType* new_data, KeyType* new_key)
        {
            height = 0;
            left = right = 0;
            data = new_data;
            key = new_key;
        };
        int Height()
        {
            return height;
        };
        Node* Left()
        {
            return left;
        };
        Node* Right()
        {
            return right;
        };
        KeyType* Key()
        {
            return key;
        };
        DataType* Data()
        {
            return data;
        };
        Node* operator=(Node* other)
        {
            Node* result = new Node();
            data = other->data;
            key = other->key;
            height = other->height;
            left = new Node(other->left);
            right = new Node(other->right);
            return result;
        };
};

#endif // NODE_HPP
