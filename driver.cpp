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

int doubler(int i) {
    return 2*i;
}

int main() {
    Array<int> t(10, doubler);
    cout << t;
}
