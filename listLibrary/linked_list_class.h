#include "list_node.h"
#include <iostream>
#include <string>
#include <initializer_list>

using namespace std;

template <typename T>
class LinkedList
{
private:
    int count;
    Node<T> *head;
    Node<T> *tail;
    NodeIterator<T> currentPointer;

public:
    LinkedList()
        : count(0), head(nullptr), tail(nullptr)
    {
    }

    LinkedList(initializer_list<T> l) : count(0), head(nullptr), tail(nullptr)
    {
        for (const T &item : l)
        {
            push_back(item);
        }
    }

    NodeIterator<T> &insert(NodeIterator<T> &ittr, const T &elem)
    {
        T oldElem = ittr.current->data;
        ittr.current->data = elem;
        Node<T> *newNode = new Node<T>(oldElem);
        newNode->next = ittr.current->next;
        newNode->previous = ittr.current;
        if (tail == ittr.current)
        {
            tail = newNode;
        }
        else
        {
            ittr.current->next->previous = newNode;
        }
        ittr.current->next = newNode;
        ++count;
        return ittr;
    }

    NodeIterator<T> &erase(NodeIterator<T> &ittr)
    {

        Node<T> *nodeToRemove = ittr.current;
        if (head == ittr.current)
        {
            head = nodeToRemove->next;
            head->previous = nullptr;
        }
        else if (tail == ittr.current)
        {
            tail = nodeToRemove->previous;
            tail->next = nullptr;
        }
        else
        {
            (nodeToRemove->next)->previous = nodeToRemove->previous;
            (nodeToRemove->previous)->next = nodeToRemove->next;
        }
        --count;
        ++ittr;
        delete nodeToRemove;
        return ittr;
    }

    void push_front(const T &ele)
    {
        Node<T> *newNode = new Node<T>(ele);
        if (count > 0)
        {
            newNode->next = head;
            head->previous = newNode;
        }
        else
        {
            tail = newNode;
        }
        head = newNode;
        ++count;
    }

    T &front() const
    {
        return head->data;
    }

    void push_back(const T &ele)
    {
        Node<T> *newNode = new Node<T>(ele);
        if (count > 0)
        {
            newNode->previous = tail;
            tail->next = newNode;
        }
        else
        {
            head = newNode;
        }
        tail = newNode;
        ++count;
    }

    T &back() const
    {
        return tail->data;
    }

    int size() const
    {
        return count;
    }

    NodeIterator<T> &begin()
    {
        currentPointer.current = head;
        return currentPointer;
    }

    NodeIterator<T> &end()
    {
        currentPointer.current = tail->next;
        return currentPointer;
    }

    ~LinkedList()
    {
        Node<T> *current = head;
        while (current != nullptr)
        {
            Node<T> *next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
};