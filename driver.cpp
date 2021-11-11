#include <iostream>
#include <string>
#include <time.h>
#include "./myLibrary/array.cpp"
#include "./myLibrary/binaryTree.cpp"
using namespace std;

int increment(int i, int index) {
    return (char)(i+index);
}

bool lowthanthree(int i) {
    return i < 3;
}

int doubler(int i) {
    return 2*i;
}

int main() {
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
}
