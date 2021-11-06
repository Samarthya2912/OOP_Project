#include "../listLibrary/linked_list_class.h"
#include "../listLibrary/list_node.h"
#include <iostream>
using namespace std;

template <typename T>
class StackClass : public LinkedList<T>
{
private:
    LinkedList<T> stack;

public:
    void push(const T &ele)
    {
        stack.push_front(ele);
    }

    int size() const
    {
        return stack.size();
    }

    int top()
    {
        return stack.front();
    }

    void pop()
    {
        if (stack.size() == 0)
        {
            cout << "stack empty";
            return;
        }
        NodeIterator<T> ittr;
        ittr.current = stack.head;
        stack.erase(ittr);
    }

    bool isEmpty()
    {
        return !stack.size();
    }
};