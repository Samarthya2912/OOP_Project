#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node<T> *previous;

    Node(T dataInput)
        : data(dataInput), next(nullptr), previous(nullptr)
    {
    }
};

template <typename T>
class NodeIterator
{
public:
    Node<T> *current;

    NodeIterator(Node<T> *currentIn)
        : current(currentIn)
    {
    }

    NodeIterator()
        : current(nullptr)
    {
    }

    T &operator*() const
    {
        return current->data;
    }

    void operator++()
    {
        current = current->next;
    }

    bool operator!=(const NodeIterator<T> &other) const
    {
        return (current != other.current);
    }

    bool operator==(const NodeIterator<T> &other) const
    {
        return (current == other.current);
    }
};
