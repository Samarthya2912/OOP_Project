#include <iostream>
#include <string>
#include "./myLibrary/avl.cpp"
using namespace std;

int increment(int i, int index) {
    return (char)(i+index);
}

bool lowthanthree(int i) {
    return i < 3;
}

int main() {
    AVL<int> t;
    for(int i = 0; i < 20; i++) t.insert(i);
    t.printTree();
}