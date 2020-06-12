#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP
#include "../Basic/Node2.hpp"
#include "../Basic/DynamicArray.hpp"

using namespace std;            //ABSOLETE

template<typename DataType, typename KeyType>
class BinaryTree
{
    private:
        using Node = Node2<DataType, KeyType>;
        Node* root;
        size_t size;
        size_t height;
        string trav_type;
        void CheckEmpty()
        {
            if(size == 0)
                runtime_error("Tree is empty");
        };
        int NodeHeight(Node *parent) const
        {
            return parent->height;
        };
        void FixNodeHeight(Node *parent)
        {
            parent->height = max(NodeHeight(parent->left), NodeHeight(parent->right)) + 1;
        };
        int NodeHeight(Node* parent)
        {
            return parent ? parent->height : 0;
        };
        int HeightDiff(Node *parent) const
        {
            return NodeHeight(parent->right) - NodeHeight(parent->left);
        };
        Node* RotateRight(Node *parent)
        {
            Node* tmp = parent->left;
            parent->left = tmp->right;
            tmp->right = parent;
            FixNodeHeight(parent);
            FixNodeHeight(tmp);
            return tmp;
        };
        Node* RotateLeft(Node* parent)
        {
            Node* tmp = parent->right;
            parent->right = tmp->left;
            tmp->left = parent;
            FixNodeHeight(parent);
            FixNodeHeight(tmp);
            return tmp;
        };
        Node* Balance(Node *parent)
        {
            FixNodeHeight(parent);
            if(HeightDiff(parent) == 2)
            {
                if(HeightDiff(parent->right) < 0)
                    parent->right = RotateRight(parent->right);
                parent = RotateLeft(parent);
            }
            else
                if(HeightDiff(parent) == -2)
                {
                    if(HeightDiff(parent->left) > 0)
                        parent->left = RotateLeft(parent->left);
                    parent = RotateRight(parent);
                };
            return parent;
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
        Node* FindMin(Node* parent) const
        {
            if(parent->left)
                return FindMin(parent->left);
            else
                return parent;
        };
        Node* FindMax(Node* parent) const
        {
            if(parent->right)
                return FindMax(parent->right);
            else
                return parent;
        };
        Node* RemoveMin(Node* parent)
        {
            if(parent->left == 0)
                return parent->right;
            parent->left = RemoveMin(parent->left);
            return Balance(parent);
        };
        template<typename KeyT>
        Node* Remove(Node* parent, KeyT&& key)
        {
            if(parent == 0)
                throw runtime_error("Tree is empty");
            if(key < parent->key)
                parent->left = Remove(parent->left, forward<KeyT>(key));
            else if(key > parent->key)
                parent->right = Remove(parent->right, forward<KeyT>(key));
            else
            {
                Node* left = parent->left;
                Node* right = parent->right;
                parent->left = 0;
                parent->right = 0;
                delete parent;
                if(right == 0)
                    return left;
                Node* min = FindMin(right);
                min->right = RemoveMin(right);
                min->left = left;
                return Balance(min);
            };
            return Balance(parent);
        };
        bool Find(KeyType key, Node* node)
        {
            return node->Find(key);
        };
        size_t SizeCheck(Node* node)
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
        void ResetSize()
        {
            size = SizeCheck(root);
        };
        template<typename Function>
        void Traverse(Node *node, Node *parent, string trav_t, Function function)
        {
            if(node != 0)
            {
                if(node == parent)
                    function(node->data, node->key);
                else
                {
                    Node* left = node->left;
                    Node* rt = node;
                    Node* right = node->right;
                    if(trav_t[0] == 'R')
                        Traverse(rt, node, trav_t, function);
                    else
                    {
                        if(trav_t[0] == 'l')
                            Traverse(left, node, trav_t, function);
                        else
                            Traverse(right, node, trav_t, function);
                    };
                    if(trav_t[1] == 'R')
                        Traverse(rt, node, trav_t, function);
                    else
                    {
                        if(trav_t[1] == 'l')
                            Traverse(left, node, trav_t, function);
                        else
                            Traverse(right, node, trav_t, function);
                    };
                    if(trav_t[2] == 'R')
                        Traverse(rt, node, trav_t, function);
                    else
                    {
                        if(trav_t[2] == 'l')
                            Traverse(left, node, trav_t, function);
                        else
                            Traverse(right, node, trav_t, function);
                    };
                };
            };
        };
        string ToStringTraverse(string trav_t)
        {
            string str;
            Traverse(root, 0, trav_t, [&](int &data, const int &key)
            {
                string tmp = to_string(data) + ' ';
                str += tmp;
            });
            return str;
        };
    public:
        BinaryTree()
        {
            root = 0;
            size = 0;
        };
        BinaryTree(const BinaryTree& other)
        {
            root = other.root;
            size = other.size;
            height = other.height;
        };
        BinaryTree(const BinaryTree* other)
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
        void Erase(KeyType key)
        {
            if(size < 1)
                throw runtime_error("Tree empty");
            if(!Find(key))
                throw runtime_error("Key does not exist");
            root = Remove(root, key);
            ResetHeight();
            size--;
        };
        void EraseSubtree(KeyType key)
        {
            if(size < 1)
                throw runtime_error("Tree empty");
            Remove(FindNode(key), key);
            ResetHeight();
            SizeCheck(root);
        };
        void Insert(DataType data, KeyType key)
        {
            Node* node = new Node(data, key);
            if(root == 0)
            {
                if(debug_flag)
                    cout << ">0=" << data << endl;
                root = node;
            }
            else
            {
                root->Insert(node);
            };
            ResetHeight();
            size++;
        };
        void Clear()
        {
            delete root;
            size = 0;
            height = 0;
        };
        template<typename Function>
        void Traverse(string trav_t, Function function)
        {
            Traverse(root, 0, trav_t, function);
        };
        DataType Get(KeyType key)
        {
            return root->Get(key);
        };
        DataType PopMin()
        {
            DataType result = FindMin(root)->data;
            RemoveMin(root);
            return result;
        };
        DataType PopMax()
        {
            DataType result = FindMax(root)->data;
            RemoveMax(root);
            return result;
        };
        DataType operator[](const int key)
        {   //If new sets root's data as default
            if(!Find(key))
                Insert(root->data, key);
            return Get(key);
        };
        string ToString(string trav_t)
        {
            return ToStringTraverse(trav_t);
        };
        BinaryTree<DataType, KeyType>& operator=(const BinaryTree<DataType, KeyType>& other)
        {
            delete root;
            root = new Node(other.root);
            size = other.size;
            height = other.height;
            return *this;
        };
        BinaryTree<DataType, KeyType>* operator=(const BinaryTree<DataType, KeyType>* other)
        {
            delete root;
            root = new Node(other->root);
            size = other->size;
            height = other->height;
            return this;
        };
        BinaryTree<DataType, KeyType>* SubTree(KeyType key)
        {
            BinaryTree<DataType, KeyType>* result = new BinaryTree<DataType, KeyType>();
            result->root = new Node(FindNode(key));
            result->ResetSize();
            result->ResetHeight();
            return result;
        };
        ~BinaryTree(){};
        template<typename Function>
        BinaryTree* Map(const BinaryTree& tree, Function function)
        {
            BinaryTree* result = BinaryTree(tree);
            result->traversal(result->LRtR, [function](DataType& x){
                x = function(x);
            });
            return result;
        };
        template<typename Function>
        BinaryTree* Where(const BinaryTree& tree, Function function)
        {
            BinaryTree* result;
            tree.traversal(tree.LRtR, [&function, result](DataType& x, KeyType& key){
                if(function(x))
                {
                    result->insert(x, key);
                };
            });
            return result;
        };
        template <typename Function>
        DataType Reduce(const BinaryTree& tree, DataType init_const, Function function)
        {
            DataType result = init_const;
            tree.traversal("lRr", [&function, result](KeyType& key, DataType& x){
                result = function(result, x);
            });
            return result;
        };
};

#endif // BINARYTREE_HPP
