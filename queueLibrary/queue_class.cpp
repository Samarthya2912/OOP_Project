#include "../listLibrary/linked_list_class.h"
#include "../listLibrary/list_node.h"
#include <iostream>
using namespace std;

template <typename T>
class Queue : public LinkedList<T>
{

public:
    Queue()
        : count(0), head(nullptr), tail(nullptr)
    {
    }

    Queue(initializer_list<T> l) : count(0), head(nullptr), tail(nullptr)
    {
        for (const T &item : l)
        {
            push_back(item);
        }
    }

    void enque(const T &ele)
    {
        this->push_back(ele);
    }

    void deque()
    {
        if (this->size() == 0)
        {
            cout << "queue empty";
            return;
        }
        NodeIterator<T> ittr;
        ittr.current = this->head;
        this->erase(ittr);
    }

    bool isEmpty()
    {
        return !this->size();
    }
};