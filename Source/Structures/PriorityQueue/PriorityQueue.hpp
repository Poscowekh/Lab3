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
    public:
        PriorityQueue() = default;
        PriorityQueue(const Queue& queue): tree(queue.tree) {};
        PriorityQueue(Queue&& queue): tree(move(queue.tree)) {};
        template<typename PriorT, typename DataT>
        void Push(PriorT&& priority, DataT&& data)
        {
            //tree.Insert(forward<PriorT>(priority), forward<DataT>(data));
            tree[forward<PriorT>(priority)] = forward<DataT>(data);
        };
        DataType& Top()
        {
            return tree.FindMax().second;
        };
        DataType Pop()
        {
            if(Size() < 1)
                throw runtime_error("PriorityQueue is empty");
            pair<const PriorityType&, DataType&> max = tree.FindMax();
            DataType result = move(max.second);
            tree.Erase(max.first);
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
        ~PriorityQueue()
        {
            tree = 0;
        };
        template<typename Function>
        Queue Map(const Queue& queue, Function function)
        {
            Queue result = queue;
            result.tree.Traverse("lRr", [function](const PriorityType &key, DataType &data)
            {
                data = function(data);
            });
            return result;
        };
        template<typename Function>
        Queue Where(const Queue& queue, Function function)
        {
            Queue result = queue;
            result.tree.Traverse("lRr", [result, function](const PriorityType &key, const DataType &data)
            {
                if(function(data))
                    result.insert(key, data);
            });
            return result;
        };
        template<typename Function>
        DataType Reduce(const Queue& queue, DataType&& init_const, Function function)
        {
            DataType result = init_const;
            queue.tree.Traverse("lRr", [function, result](const PriorityType &key, const DataType &data)
            {
                result += function(data, result);
            });
            return result;
        };
        Queue& operator=(const Queue& other)
        {
            tree = new Tree(other.tree);
            return *this;
        };
};

#endif // PRIORITYQUEUE_HPP
