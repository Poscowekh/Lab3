#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP
#include "../Trees/Tree.hpp"

using namespace std;

template<typename PriorityType, typename DataType>
class PriorityQueue
{
    private:
        using Queue = PriorityQueue<PriorityType, DataType>;
        using Tree = BSTree<PriorityType, DataType>;
        Tree tree;
        string type;        //MAX or MIN (MAX BY DEFAULT)
    public:
        PriorityQueue() = default;
        PriorityQueue(const Queue& queue): tree(queue.tree) {};
        PriorityQueue(Queue&& queue): tree(move(queue.tree)) {};
        template<typename PriorT, typename DataT>
        void Push(PriorT&& priority, DataT&& data)
        {
            tree.Insert(forward<PriorT>(priority), forward<DataT>(data));
            //tree[forward<PriorT>(priority)] = forward<DataT>(data);
        };
        void SetType(string n_type)
        {
            type = n_type;
        };
        string GetType()
        {
            return type;
        };
        DataType& Top()
        {
            return tree.FindMax().second;
        };
        DataType Pop()
        {
            DataType result;
            if(Size() < 1)
                throw runtime_error("PriorityQueue is empty");
            if(type == "MAX")
            {
                pair<const PriorityType&, DataType&> max = tree.FindMax();
                result = move(max.second);
                tree.Erase(max.first);
            }
            else
            {
                pair<const PriorityType&, DataType&> min = tree.FindMin();
                result = move(min.second);
                tree.Erase(min.first);
            };
            return result;
        };
        void Clear()
        {
            tree.Clear();
        };
        size_t Size() const
        {
            return tree.Size();
        };
        bool Empty() const
        {
            return (tree.Size() == 0);
        };
        /*~PriorityQueue()
        {
            tree = 0;
        };*/
        template<typename Function>
        Queue Map(Function function)
        {
            Queue result = this;
            result.tree.Traverse("lRr", [&](const PriorityType &key, DataType &data)
            {
                data = function(data);
            });
            return result;
        };
        template<typename Function>
        Queue Where(Function function)
        {
            Queue result = this;
            result.tree.Traverse("lRr", [&](const PriorityType &key, const DataType &data)
            {
                if(function(data))
                    result.insert(key, data);
            });
            return result;
        };
        template<typename Function>
        DataType Reduce(DataType&& init_const, Function function)
        {
            DataType result = init_const;
            tree.Traverse("lRr", [&](const PriorityType &key, const DataType &data)
            {
                result += function(data, result);
            });
            return result;
        };
        /*Queue& operator=(const Queue& other)
        {
            tree = Tree(other.tree);
            return *this;
        };*/
};

#endif // PRIORITYQUEUE_HPP
