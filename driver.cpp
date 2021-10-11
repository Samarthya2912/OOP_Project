#include <iostream>
#include <string>
#include "./myLibrary/array_class.cpp"
#include "./myLibrary/bigint.cpp"
using namespace std;

int doubler(int i) {
    return 2*i;
}

bool lowthanthree(int i) {
    return i < 3;
}

int main() {
    bigint a("156654646554555555555555555555555555555555555555");
    bigint b("111111111111111111111111111111111111111111111111");
    cout << a+b << endl;

}