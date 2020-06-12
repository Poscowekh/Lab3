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
        Tree* tree;
    public:
        PriorityQueue()
        {
            tree = new Tree();
        };
        PriorityQueue(const Queue& queue)
        {
            tree = new Tree(queue.tree);
        };
        PriorityQueue(Queue* queue)
        {
            tree = new Tree(queue->tree);
        };
        void Push(PriorityType priority, DataType data)
        {
            tree->Insert(priority, data);
        };
        DataType& Top()
        {
            return tree->FindMax().second;
        };
        DataType Pop()
        {
            if(Size() < 1)
                throw runtime_error("PriorityQueue is empty");
            pair<PriorityType, DataType> max = tree->find_max();
            DataType result = max.second;
            tree->erase(max.first);
            return result;
        };
        void Clear()
        {
            tree->Clear();
        };
        size_t Size() const
        {
            return tree->Size();
        };
        bool Empty() const
        {
            return (Size() == 0);
        };
        ~PriorityQueue()
        {
            tree = 0;
        };
};

#endif // PRIORITYQUEUE_HPP
