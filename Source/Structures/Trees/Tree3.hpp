#ifndef Tree3_HPP
#define Tree3_HPP
#include "../Basic/Node3.hpp"
#include "../Basic/DynamicArray.hpp"

using namespace std;

template<typename DataType, typename KeyType>
class Tree3
{
    private:
        using Node = Node3<DataType, KeyType>;
        using traversal_type = void(*)(void*&, void*&, void*&, void*&);
        Node* root;
        size_t size;
        size_t height;
        void CheckEmpty()
        {
            if(size == 0)
                runtime_error("No elements in tree");
        };
        Node* GetNode(KeyType key)
        {
            root->GetNode(key);
        };
        Node* GetNode(KeyType key, Node* node)
        {
            node->Get(key);
        };
        bool Find(KeyType key, Node* node)
        {
            return node->Find(key);
        };
        size_t Size(Node* node)
        {
            if(node == 0)
                return 0;
            else
                return node->Size();
        };
        void ResetHeight()
        {
            if(root == 0)
                height = 1;
            else
            {
                root->ResetHeight();
                height = root->height;
            };
        };
        //traversal_type base = ;
        template<typename Function>
        void Traverse(Node *node, Node *parent, traversal_type trav_t, Function function)
        {
            if(node != 0)
            {
                if(node == parent)
                    function(node->data, node->key);
                else
                {
                    void* n = node;
                    void* n1 = node->left;
                    void* n2 = node->centre;
                    void* n3 = node->right;
                    trav_t(n, n1, n2, n3);
                    Traverse((Node*)n, node, trav_t, function);
                    Traverse((Node*)n1, node, trav_t, function);
                    Traverse((Node*)n2, node, trav_t, function);
                    Traverse((Node*)n3, node, trav_t, function);
                };
            };
        };
        /*
        static void RtLR(void* &n1, void* &n2, void* &n3)
        {
            swap(n1, n2);
        };*/
        /*
        traversal_type TraversalTypeFromString(string trav_str)
        {   //Format "R123"
            int pos_R = trav_str.find('R');

        };
        string ToStringTraverse(traversal_type trav_t)
        {

        };*/
        /*
        template<typename Function>
        void Traverse(Node *node, Node *parent, Function function)
        {
            Traverse(node, parent, , function)
        };*/
    public:
        Tree3()
        {
            root = 0;
            size = 0;
        };
        Tree3(const Tree3& other)
        {
            root = other.root;
            size = other.size;
            height = other.height;
        };
        Tree3(const Tree3* other)
        {
            root = other->root;
            size = other->size;
            height = other->height;
        };
        bool Empty()
        {
            if(size > 0)
                return false;
            else
                return true;
        };
        bool Find(KeyType key)
        {
            return root->Find(key);
        };
        size_t Size()
        {
            return size;
        };
        size_t Height()
        {
            return height;
        };
        void Insert(DataType data, KeyType key)
        {
            Node* node = new Node(data, key);
            if(root == 0)
            {
                if(debug_flag)
                    cout << "0=" << data << endl;
                root = node;
            }
            else
                root->Insert(node);
            ResetHeight();
            size++;
        };
        /*
        void Print()
        {
            if(size > 0)
                root->Print();
            else
                cout << "Tree3 is empty" << endl;
        };*/
        void Clear()
        {
            delete root;
            size = 0;
            height = 0;
        };
        /*
        void SmartPrint();   //Nice Tree3 look?
        */
        /*
        template<typename Function>
        void Traverse(string trav_str, Function function)
        {
            traversal_type trav_t = TraversalTypeFromString(trav_str);
            Traverse(root, 0, trav_t, function);
        };*/
        DataType Get(KeyType key)
        {
            return root->Get(key);
        };
        /*
         * DataType Max()
        {

        };
        DataType Min()
        {
            ;
        };
        */
        /*
        DataType operator[](const int key)
        {
            if(!Find(key))
                Insert(0, key);
            return Get(key);
        };*/
        /*
        string ToString(traversal_type trav_t)
        {
            return ToStringTraverse(trav_t);
        };*/
        Tree3<DataType, KeyType>& operator=(const Tree3<DataType, KeyType>& other)
        {
            delete root;
            root = new Node(other.root);
            size = other.size;
            height = other.height;
            return *this;
        };
        Tree3<DataType, KeyType>* operator=(const Tree3<DataType, KeyType>* other)
        {
            delete root;
            root = new Node(other->root);
            size = other->size;
            height = other->height;
            return this;
        };
        Tree3<DataType, KeyType>* SubTree3(KeyType key)
        {
            Tree3<DataType, KeyType>* result = new Tree3<DataType, KeyType>();
            Node* tmp = GetNode(key);
            cout<<"H";
            result->root = new Node(tmp);

            result->size = Size(tmp);
            result->ResetHeight();
            return result;
        };
        ~Tree3(){};
};

#endif // Tree3_HPP
