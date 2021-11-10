#include "../listLibrary/linked_list_class.h"
#include "../listLibrary/list_node.h"
#include <iostream>
using namespace std;

template <typename T>
class Stack : public LinkedList<T>
{
public:
    void push(const T &ele)
    {
        this->push_front(ele);
    }

    int top()
    {

        return this->front();
    }

    void pop()
    {
        if (this->size() == 0)
        {
            cout << "stack empty";
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