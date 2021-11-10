#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "list_node.h"
#include <iostream>
#include <string>
#include <initializer_list>

using namespace std;
template <typename T>
class LinkedList
{
public:
    int count;
    Node<T> *head;
    Node<T> *tail;
    NodeIterator<T> currentPointer;

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

    void printlist(Node<T> *head)
    {
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node<T> *mergeSortedList(Node<T> *h1, Node<T> *h2)
    {
        if (h1 == NULL)
        {
            return h2;
        }

        if (h2 == NULL)
        {
            return h1;
        }

        Node<T> *head;
        Node<T> *tail;

        if (h1->data <= h2->data)
        {
            head = h1;
            tail = h1;
            h1 = h1->next;
        }
        else
        {
            head = h2;
            tail = h2;
            h2 = h2->next;
        }

        while (h1 != NULL && h2 != NULL)
        {
            if (h1->data <= h2->data)
            {
                tail->next = h1;
                tail = h1;
                h1 = h1->next;
            }
            else
            {
                tail->next = h2;
                tail = h2;
                h2 = h2->next;
            }
        }

        if (h1 == NULL)
        {
            tail->next = h2;
        }
        else
        {
            tail->next = h1;
        }

        return head;
    }
    Node<T> *SortList(Node<T> *head)
    {

        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        Node<T> *slow = head;
        Node<T> *fast = head->next;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node<T> *h2 = slow->next;
        slow->next = NULL;

        head = sortList(head);
        h2 = sortList(h2);

        return mergeSortedList(head, h2);
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

#endif