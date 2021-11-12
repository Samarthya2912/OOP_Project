#include <iostream>
#include <string>
#include <time.h>
#include "./myLibrary/array.cpp"
#include "./myLibrary/stack_class.cpp"
#include "./myLibrary/queue_class.cpp"
#include "./myLibrary/linked_list_class.h"
#include "./myLibrary/binaryTree.cpp"
#include "./myLibrary/bigint.cpp"
using namespace std;

int increment(int i, int index)
{
    return (char)(i + index);
}

bool lowthanthree(int i)
{
    return i < 3;
}

int doubler(int i)
{
    return 2 * i;
}

int main()
{
    // Array Implementation
    // Array<int> a(5, 0);
    // Array<int> b(5, doubler);
    // Array<int> c = a + b;
    // cout << a << b << c << endl;

    // BigInt Implementation
    // string s = "1000";
    // bigint a = s;
    // bigint b("100");
    // cout << a * b << endl;

    // Tree Implementation
    binaryTree<int> a;
    a.insert(44);
    a.insert(7);
    a.insert(8);
    a.insert(12);
    a.insert(1);
    a.insert(23);
    a.insert(19);
    a.insert(10);
    srand(10);
    a.inorder();
    a.printTree();

    // LinkedList Implementation
    // LinkedList<int> ll{2, 3, 4, 1, 5};
    // cout << ll.front() << endl;
    // ll.push_front(1);
    // cout << ll.front() << endl;
    // ll.sortList(ll.head);
    // cout << ll.back() << endl;
    // ll.printlist();

    // Stack Implementation
    // Stack<int> st{1, 2, 4 , 5,6,7,8,9,10,11};
    // cout << st.top() << " ";
    // st.pop();
    // cout << st.top();

    // Queue Implementation
    // Queue<int> q{1, 2, 4, 5, 6, 7, 8, 9, 10};
    // cout << q.front() << " ";
    // q.deque();
    // cout << q.front();
}
