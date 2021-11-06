#include <iostream>
#include <string>
#include "./myLibrary/array.cpp"
using namespace std;

int increment(int i) {
    return (char)(i+1);
}

bool lowthanthree(int i) {
    return i < 3;
}

int main() {
    Array<int> c(10, increment);
    auto d = c.filter(lowthanthree);
    cout << c << d;
}