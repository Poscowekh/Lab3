#ifndef Node3_HPP
#define Node3_HPP
#include <iostream>
#include <utility>

//ABSOLETE

using namespace std;

bool debug_flag = false;

template<typename DataType, typename KeyType>
class Node3
{
    private:
        void InsertLeft(Node3<DataType, KeyType>* node)
    {
        if(left == 0)
        {
            left = new Node3(node);
            left->height = 0;
            if(debug_flag)
                cout<<height+1<<'='<<node->data<<endl;
        }
        else
            left->Insert(node);
    };
        void InsertCentre(Node3<DataType, KeyType>* node)
        {
            if(centre == 0)
            {
                centre = new Node3(node);
                centre->height = 0;
                if(debug_flag)
                    cout<<height<<'='<<node->data<<endl;
            }
            else
                centre->Insert(node);
        };
        void InsertRight(Node3<DataType, KeyType>* node)
        {
            if(right == 0)
            {
                right = new Node3(node);
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
        Node3* left;
        Node3* centre;
        Node3* right;
        Node3()
        {
            data = 0;
            key = 0;
            left = 0;
            centre = 0;
            right = 0;
            height = 0;
        };
        Node3(const Node3* other)
        {
            key = other->key;
            height = other->height;
            data = other->data;
            if(other->left == 0)
                left = 0;
            else
                left = new Node3(other->left);
            if(other->centre == 0)
                centre = 0;
            else
                centre = new Node3(other->centre);
            if(other->right == 0)
                right = 0;
            else
                right = new Node3(other->right);
        };
        Node3(DataType new_data, KeyType new_key)
        {
            height = 0;
            left = 0;
            centre = 0;
            right = 0;
            data = new_data;
            key = new_key;
        };
        Node3(DataType new_data, KeyType new_key, int new_height, Node3* new_left, Node3* new_centre, Node3* new_right)
        {
            data = new_data;
            key = new_key;
            height = new_height;
            if(new_left == 0)
                left = 0;
            else
                left = new Node3(new_left);
            if(new_centre == 0)
                centre = 0;
            else
                centre = new Node3(new_centre);
            if(new_right == 0)
                right = 0;
            else
                right = new Node3(new_right);
        };
        size_t Size()
        {
            return left->Size() + centre->Size() + right->Size() + 1;
        };
        Node3* GetNode(KeyType some_key)
        {
            if(!Find(some_key))
                throw runtime_error("Non-existent key");
            else
            {
                if(some_key == key)     //Shall include those equal to this?
                    return this;
                if(some_key < key)
                    return left->GetNode3(some_key);
                else
                    return right->GetNode3(some_key);
            };
        };
        DataType Get(KeyType some_key)
        {
            return GetNode3(some_key)->data;
        };
        bool Find(KeyType some_key)
        {
            if(some_key == key)
                return true;
            if(some_key < key)
            {
                if(left != 0)
                    return left->Find(some_key);
                else
                    return false;
            }
            else
            {
                if(right != 0)
                    return right->Find(some_key);
                else
                    return false;
            };
        };
        void Print()    //tmp not for final
        {
            if(left != 0)
                left->Print();
            cout << data << endl;
            if(centre != 0)
                centre->Print();
            if(right != 0)
                right->Print();
        };
        void Insert(Node3<DataType, KeyType>* node)
        {
            if(debug_flag)
                cout << height << "->";
            if(node->key == key)
            {
                if(debug_flag)
                    cout << height << 'C';
                InsertCentre(node);
            }
            else
            {
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
        };
        void Insert(DataType data, KeyType key)
        {
            Node3* node = new Node3(data, key);
            Insert(node);
        };
        void ResetHeight()
        {

            height = 1;
            int h1 = 0;
            int h2 = 0;
            int h3 = 0;
            if(left != 0)
            {
                left->ResetHeight();
                h1 = left->height;
            };
            if(centre != 0)
            {
                centre->ResetHeight();
                h2 = centre->height;
            };
            if(right != 0)
            {
                right->ResetHeight();
                h3 = right->height;
            };
            height += max(h1, max(h2, h3));
        };
        ~Node3()
        {
            if(left != 0)
                delete left;
            if(centre != 0)
                delete left;
            if(right != 0)
                delete right;
        };
};

#endif // Node3_HPP
