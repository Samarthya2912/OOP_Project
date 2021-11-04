#include "../listLibrary/linked_list_class.h"
#include "../listLibrary/list_node.h"
#include <iostream>
using namespace std;

template <typename T>
class QueueClass : public LinkedList<T>
{
private:
    LinkedList<T> queue;

public:
    void enque(const T &ele)
    {
        queue.push_back(ele);
    }

    int size() const
    {
        return queue.size();
    }

    int front()
    {
        return queue.front();
    }

    void deque()
    {
        if (queue.size() == 0)
        {
            cout << "queue empty";
            return;
        }
        NodeIterator<T> ittr;
        ittr.current = queue.head;
        queue.erase(ittr);
    }

    bool isEmpty()
    {
        return !queue.size();
    }
};