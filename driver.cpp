#include <iostream>
#include <string>
#include "./myLibrary/array_class.cpp"
using namespace std;

int doubler(int i) {
    return 2*i;
}

bool lowthanthree(int i) {
    return i < 3;
}

int main() {
    // Array<int> a(5, 7);
    // Array<int> b(5, 8);
    // auto c = a + b;
    // c.display();
    // cout << c[-3];
    // c[-3] = 44;
    // c.display();

    Array<int> d(10, doubler);
    d.display();
    // auto e = d.slice(2,6);
    // e.display();
    auto f = d.filter(lowthanthree);
    f.display();
    return  0;
}