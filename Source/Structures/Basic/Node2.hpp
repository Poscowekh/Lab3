#ifndef Node_HPP
#define Node_HPP
#include <iostream>
#include <utility>

//ABSOLETE

using namespace std;

bool debug_flag = false;

template<typename DataType, typename KeyType>
class Node2
{
    private:
        using Node = Node2;
        void InsertLeft(Node* node)
        {
            if(left == 0)
            {
                left = new Node(node);
                left->height = 0;
                if(debug_flag)
                    cout<<height+1<<'='<<node->data<<endl;
            }
            else
                left->Insert(node);
        };
        void InsertRight(Node* node)
        {
            if(right == 0)
            {
                right = new Node(node);
                right->height = 0;
                if(debug_flag)
                    cout<<height<<'='<<node->data<<endl;
            }
            else
                right->Insert(node);
        };
    public:
        DataType data;
        KeyType key;
        int height;
        Node* left;
        Node* right;
        Node2()
        {
            left = right = 0;
            height = 0;
        };
        Node2(const Node* other)
        {
            key = other->key;
            height = other->height;
            data = other->data;
            if(other->left == 0)
                left = 0;
            else
                left = new Node(other->left);
            if(other->right == 0)
                right = 0;
            else
                right = new Node(other->right);
        };
        Node2(DataType new_data, KeyType new_key)
        {
            height = 0;
            left = right = 0;
            data = new_data;
            key = new_key;
        };
        Node2(const Node& other)
        {
            key = other.key;
            height = other.height;
            data = other.data;
            if(other.left == 0)
                left = 0;
            else
                left = new Node(other.left);
            if(other.right == 0)
                right = 0;
            else
                right = new Node(other.right);
        };
        size_t Size()
        {
            size_t result = 1;
            if(left != 0)
                result += left->Size();
            if(right != 0)
                result += right->Size();
            return  result;
        };
        Node* FindNode(KeyType some_key)
        {
            if(some_key == key)
                return this;
            if(some_key < key)
            {
                if(left != 0)
                    return left->FindNode(some_key);
                else
                    return 0;
            }
            else
            {
                if(right != 0)
                    return right->FindNode(some_key);
                else
                    return 0;
            };
        };
        Node* FindNodeParent(KeyType some_key)
        {
            if(!Find(some_key))
                throw runtime_error("Non-existent key");
            else
            {
                if(some_key < key)
                {
                    if(some_key == left->key)
                        return this;
                    else
                        return left->FindNodeParent(some_key);
                }
                else
                    if(some_key == right->key)
                        return this;
                    else
                        return right->FindNodeParent(some_key);
            };
        };
        DataType Get(KeyType some_key)
        {
            return FindNode(some_key)->data;
        };
        void RemoveNode(Node* parent, KeyType some_key)
        {
            if(parent == 0)
                throw runtime_error("Tree is empty");
            if(this == parent)
            {
                if(left != 0)
                    left->RemoveNode(this, some_key);
                if(right != 0)
                    right->RemoveNode(this, some_key);
            }
            else
            {
                if(key > some_key)
                    left->RemoveNode(this, some_key);
                 else
                {
                    if(key < some_key)
                        right->RemoveNode(this, some_key);
                    else
                    {
                        if(left == 0 && right == 0)
                        {
                            if(parent->left == this)
                                parent->left = 0;
                            else
                                parent->right = 0;
                        }
                        else
                        {
                            if(left == 0)
                            {
                                if(parent->left == this)
                                    parent->left = right;
                                else
                                    parent->right = right;
                            }
                            else
                            {
                                if(right == 0)
                                {
                                    if(parent->left == this)
                                        parent->left = left;
                                    else
                                        parent->right = left;
                                }
                                else
                                {
                                    if(right->left == 0)
                                    {
                                        data = right->data;
                                        key = right->key;
                                        right = right->right;
                                    }
                                    else
                                    {
                                        Node* tmp = right->FindMin();
                                        data = tmp->data;
                                        key = tmp->key;
                                        right->RemoveNode(right, key);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        };
        bool Find(KeyType some_key)
        {
            if(FindNode(some_key) == 0)
                return false;
            else
                return true;
        };
        void Print()    //tmp not for final
        {
            if(left != 0)
                left->Print();
            cout << data << endl;
            if(right != 0)
                right->Print();
        };
        void Insert(Node* node)
        {
            if(node->key == key)
            {
                cout << endl;
                throw runtime_error("Key already exists");
            };
            if(debug_flag)
                cout << height << "->";
            if(node->key < key)
            {
                if(debug_flag)
                    cout << 'L';
                InsertLeft(node);
            }
            else
            {
                if(debug_flag)
                    cout << 'R';
                InsertRight(node);
            };
        };
        void Insert(DataType data, KeyType key)
        {
            Node* node = new Node(data, key);
            Insert(node);
        };
        void ResetHeight()
        {
            height = 1;
            int h1 = 0;
            int h2 = 0;
            if(left != 0)
            {
                left->ResetHeight();
                h1 = left->height;
            };
            if(right != 0)
            {
                right->ResetHeight();
                h2 = right->height;
            };
            height += max(h1, h2);
        };
        ~Node2()
        {
            if(left != 0)
                delete left;
            if(right != 0)
                delete right;
        };
};

#endif // Node_HPP
