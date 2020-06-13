#ifndef BSTREE_HPP
#define BSTREE_HPP
#include <utility>
#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;

template <typename KeyType, typename DataType>
class BSTree
{
    private:
        using Tree = BSTree;
        struct Node
        {
            KeyType key;
            DataType data;
            Node* left;
            Node* right;
            int height;
            Node()
            {
                key = KeyType();
                data = DataType();
                left = right = 0;
                height = 0;
            };
            Node(const Node* other)
            {
                key = other->key;
                data = other->data;
                height = other->height;
                if(other->left != 0)
                    left = new Node(other->left);
                else
                    left = 0;
                if(other->right != 0)
                    right = new Node(other->right);
                else
                    right = 0;
            };
            Node(const Node& other)
            {
                key = other.key;
                data = other.data;
                height = other.height;
                if(other.left != 0)
                    left = new Node(other.left);
                else
                    left = 0;
                if(other.right != 0)
                    right = new Node(other.right);
                else
                    right = 0;
            };
            template<typename KeyT, typename DataT>
            Node(KeyT&& n_key, DataT&& n_data)
            {
                key = n_key;
                data = n_data;
                height = 1;
                left = right = 0;
            };
            ~Node()
            {
                delete right;
                delete left;
            };
        };
        Node* root;
        size_t size;
        void CheckSize() const
        {
            if(root == 0)
                throw logic_error("Tree is empty");
        };

        template<typename KeyT>
        Node* FindNode(Node* parent, KeyT&& key) const
        {
            if(parent == 0)
                return 0;
            if(key == parent->key)
                return parent;
            if(key < parent->key)
                return FindNode(parent->left, forward<KeyT>(key));
            if(key > parent->key)
                return FindNode(parent->right, forward<KeyT>(key));
        };
        Node* FindMinNode(Node* parent) const
        {
            return parent->left ? FindMinNode(parent->left) : parent;
        };
        Node* FindMaxNode(Node *parent) const
        {
            return parent->right ? FindMaxNode(parent->right) : parent;
        };
        template <typename KeyT>
        Node* GetNode(Node* parent, KeyT&& key) const
        {
            if(parent == 0)
                throw out_of_range("Parent is null!");
            if(key == parent->key)
                return parent;
            if(key < parent->key)
                return GetNode(parent->left, key);
            else
                return GetNode(parent->right, key);
        };

        template<typename KeyT, typename DataT>
        Node* NodeInsert(Node* parent, KeyT&& key, DataT&& data)
        {
            if(parent == 0)
                return new Node(forward<KeyT>(key), forward<DataT>(data));
            if(parent->key == key)
                throw runtime_error("Key already exists");
            if(key < parent->key)
                parent->left = NodeInsert(parent->left, forward<KeyT>(key), forward<DataT>(data));
            else
                parent->right = NodeInsert(parent->right, forward<KeyT>(key), forward<DataT>(data));
            FixNodeHeight(parent);
            return BalanceNode(parent);
        };
        template<typename KeyT>
        Node* RemoveNode(Node* parent, KeyT&& key)
        {
            if(parent == 0)
                throw out_of_range("Tree out of range!");
                if(key < parent->key)
                    parent->left = RemoveNode(parent->left, forward<KeyT>(key));
                else if(key > parent->key)
                    parent->right = RemoveNode(parent->right, forward<KeyT>(key));
                else
                {
                    Node* left = parent->left;
                    Node* right = parent->right;
                    parent->left = 0;
                    parent->right = 0;
                    delete parent;
                    if(right == 0)
                        return left;
                    Node* min = FindMinNode(right);
                    min->right = RemoveNodeMin(right);
                    min->left = left;
                    return BalanceNode(min);
                }
                return BalanceNode(parent);
        };
        Node* RemoveNodeMin(Node* parent)
        {
            if(parent->left == 0)
                return parent->right;
            parent->left = RemoveNodeMin(parent->left);
            return BalanceNode(parent);
        };

        size_t GetNodeSize(Node* parent) const
        {
            if(parent == 0)
                return 0;
            else
                return GetNodeSize(parent->left) + GetNodeSize(parent->right) + 1;
        };
        int NodeHeight(Node* parent) const
        {
            return parent ? parent->height : 0;
        };
        void FixNodeHeight(Node* parent)
        {
            parent->height = max(NodeHeight(parent->left), NodeHeight(parent->right)) + 1;
        };
        int NodeHeightDifference(Node* parent) const
        {
            return NodeHeight(parent->right) - NodeHeight(parent->left);
        };

        Node* NodeRotateRight(Node* parent)
        {
            Node* tmp = parent->left;
            parent->left = tmp->right;
            tmp->right = parent;
            FixNodeHeight(parent);
            FixNodeHeight(tmp);
            return tmp;
        };
        Node* NodeRotateLeft(Node* parent)
        {
            Node *tmp = parent->right;
            parent->right = tmp->left;
            tmp->left = parent;
            FixNodeHeight(parent);
            FixNodeHeight(tmp);
            return tmp;
        };
        Node* BalanceNode(Node* parent)
        {
            FixNodeHeight(parent);
            if(NodeHeightDifference(parent) == 2)
            {
                if(NodeHeightDifference(parent->right) < 0)
                    parent->right = NodeRotateRight(parent->right);
                parent = NodeRotateLeft(parent);
            }
            else if(NodeHeightDifference(parent) == -2)
            {
                if(NodeHeightDifference(parent->left) > 0)
                    parent->left = NodeRotateLeft(parent->left);
                parent = NodeRotateRight(parent);
            };
            return parent;
        };

        template<typename Function>
        void TraversePrivate(Node *node, Node *parent, string trav_t, Function function)
        {
            if(node != 0)
            {
                if(node == parent)
                    function(node->key, node->data);
                else
                {
                    Node* left = node->left;
                    Node* rt = node;
                    Node* right = node->right;
                    if(trav_t[0] == 'R')
                        TraversePrivate(rt, node, trav_t, function);
                    else
                    {
                        if(trav_t[0] == 'l')
                            TraversePrivate(left, node, trav_t, function);
                        else
                            TraversePrivate(right, node, trav_t, function);
                    };
                    if(trav_t[1] == 'R')
                        TraversePrivate(rt, node, trav_t, function);
                    else
                    {
                        if(trav_t[1] == 'l')
                            TraversePrivate(left, node, trav_t, function);
                        else
                            TraversePrivate(right, node, trav_t, function);
                    };
                    if(trav_t[2] == 'R')
                        TraversePrivate(rt, node, trav_t, function);
                    else
                    {
                        if(trav_t[2] == 'l')
                            TraversePrivate(left, node, trav_t, function);
                        else
                            TraversePrivate(right, node, trav_t, function);
                    };
                };
            };
        };
        string ToStringTraverse(string trav_t)
        {
            string str;
            TraversePrivate(root, 0, trav_t, [&](const int &key, int& data)
            {
                string tmp = to_string(data) + ' ';
                str += tmp;
            });
            return str;
        };

    public:
        BSTree()
        {
            root = 0;
            size = 0;
        };
        BSTree(const Tree& other)
        {
            if(other.root == 0)
                root = 0;
            else
                root = new Node(other.root);
            size = other.size;
        };
        BSTree(const Tree* other)
        {
            if(other->root == 0)
                root = 0;
            else
                root = new Node(other->root);
            size = other->size;
        };
        BSTree(Tree&& other)
        {
            if(other.root == 0)
                root = 0;
            else
                root = new Node(other.root);
            size = other.size;
            other.root = 0;
            other.size = 0;
        };
        Tree& operator=(const Tree& other)
        {
            delete root;
            root = new Node(other.root);
            return *this;
        };
        Tree& operator=(Tree&& other)
        {
            delete root;
            root = other.root;
            size = other.size;
            other.root = 0;
            other.size = 0;
        };
        ~BSTree()
        {
            delete root;
        };

        size_t Size() const
        {
            return size;
        };
        int Height() const
        {
            return NodeHeight(root);
        };
        template<typename KeyT>
        bool Find(KeyT&& key) const
        {
            return (FindNode(root, forward<KeyT>(key)) != 0);
        };
        bool Empty()
        {
            if(size < 1)
                return true;
            else
                return false;
        };
        template<typename KeyT, typename DataT>
        void Insert(KeyT&& key, DataT&& data)
        {
            if(root == 0)
                root = new Node(forward<KeyT>(key), forward<DataT>(data));
            else
                root = NodeInsert(root, forward<KeyT>(key), forward<DataT>(data));
            size++;
        };

        template<typename KeyT>
        DataType& Get(KeyT&& key)
        {
            return GetNode(root, forward<KeyT>(key))->data;
        };
        template<typename KeyT>
        const DataType& Get(KeyT&& key) const
        {
            return GetNode(root, forward<KeyT>(key))->data;
        };
        template<typename KeyT>
        DataType& operator[](KeyT&& key)
        {
            if(!Find(key))
                Insert(forward<KeyT>(key), DataType());
            return Get(forward<KeyT>(key));
        };
        template<typename KeyT>
        const DataType& operator[](KeyT&& key) const
        {
            return Get(forward<KeyT>(key));
        };

        /*
        void Print()        //DELETE
        {
            PrintNode(root);
        };
        void PrintNode(Node* parent)        //DELETE
        {
            if(parent == 0)
                return;
            if(parent->left != 0)
                PrintNode(parent->left);
            cout << parent->key << ": " << parent->data << endl;
            if(parent->right != 0)
                PrintNode(parent->right);
        };
        */
        void Clear()
        {
            delete root;
            root = 0;
            size = 0;
        };
        template<typename KeyT>
        void Erase(KeyT&& key)
        {
            CheckSize();
            root = RemoveNode(root, forward<KeyT>(key));
            size--;
        };

        template<typename KeyT>
        Tree Subtree(KeyT&& key) const
        {
            Node* parent = FindNode(root, forward<KeyT>(key));
            Tree result;
            result.root = new Node(parent);
            result.size = result.GetNodeSize(result.root);
            return result;
        };

        template<typename Function>
        void Traverse(string trav_t, Function function)
        {
            TraversePrivate(root, 0, trav_t, function);
        };
        string ToString(string trav_t)
        {
            return ToStringTraverse(trav_t);
        };

        pair<KeyType&, DataType&> FindMin() const
        {
            CheckSize();
            Node* result = FindMinNode(root);
            return {result->key, result->data};
        };
        pair<KeyType&, DataType&> FindMax() const
        {
            CheckSize();
            Node* result = FindMaxNode(root);
            return {result->key, result->data};
        };

        template<typename Function>
        Tree Map(Function function)
        {
            Tree result = this;
            result.Traverse("lRr", [&](const KeyType& key, DataType& data)
            {
                data = function(data);
            });
            return result;
        };
        template<typename Function>
        Tree Where(Function function)
        {
            Tree result;
            Traverse("lRr", [&](const KeyType &key, const DataType &data)
            {
                if(function(data))
                    result.Insert(key, data);
            });
            return result;
        };
        template<typename Function>
        DataType Reduce(DataType&& init_const, Function function)
        {
            DataType result = init_const;
            Traverse("lRr", [&](const KeyType &key, const DataType &data)
            {
                result = function(result, data);
            });
            return result;
        };
};

#endif // BSTREE_HPP
