#include <iostream>
#include <string>
#include "./myLibrary/array.cpp"
using namespace std;

int increment(int i, int index) {
    return (char)(i+index);
}

bool lowthanthree(int i) {
    return i < 3;
}

int main() {
    Array<int> c(10, 5);
    auto d = c.map(increment);
    cout << c << d;
}