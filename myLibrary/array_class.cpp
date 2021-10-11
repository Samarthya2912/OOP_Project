#include <iostream>
using namespace std;

template <class T>
class Array {
    T* arr;
    int size;

    public:
    Array(int size) : size(size) { // size initialiser 
        arr = new T[size];
    }

    Array(int size, T initialiser) : Array(size) { // value initialiser
        for(int i = 0; i < size; i++) arr[i] = initialiser;
    }

    Array(int size, T (*initializer_function)(int)) : Array(size) { // function initialiser
        for(int i = 0; i < size; i++) arr[i] = initializer_function(i);
    }

    void display();
    Array operator+(Array<T>&);
    T& operator[](int);
    Array slice(int start, int end);

    ~Array() {
        delete[] arr;
    }
};

template <class T>
void Array<T>::display() {
    for(int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}

template <class T>
Array<T> Array<T>::operator+(Array<T>& a) {
    Array<T> sum_arr(size + a.size);

    int j = 0;
    for(int i = 0; i < size; i++) sum_arr.arr[j++] = arr[i];
    for(int i = 0; i < a.size; i++) sum_arr.arr[j++] = a.arr[i];

    return sum_arr;
}

template <class T> 
T& Array<T>::operator[](int index) {
    if(index < 0) {
        return arr[size + index];
    }

    return arr[index];
}

template <class T>
Array<T> Array<T>::slice(int start, int end) {
    Array sliced_Arr(end - start + 1);

    int j = 0; 
    for(int i = start; i <= end; i++) {
        sliced_Arr.arr[j++] = arr[i];
    }

    return sliced_Arr;
}