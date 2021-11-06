#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Array {
    protected:
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
    T& operator[](int);
    int length();
    Array operator+(Array<T>&);
    Array slice(int start, int end);
    Array filter(bool (*filter_function)(T arg));

    friend ostream & operator<< (ostream &out, const Array &a) {
        out << '[' << ' ';
        for(int i = 0; i < a.size; i++) out << a.arr[i] << (i == a.size - 1? " ":", ");
        out << ']' << endl;
        return out;
    }

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

template <class T>
Array<T> Array<T>::filter(bool (*filter_func)(T arg)) {
    int cnt = 0;
    vector<T> selected;

    for(int i = 0; i < size; i++) {
        if(filter_func(arr[i])) selected.push_back(arr[i]);
    }

    Array<T> newArray(selected.size());
    int j = 0;

    for(auto i:selected) {
        newArray.arr[j++] = i;
    }

    return newArray;
}

template <class T>
int Array<T>::length() {
    return this->size;
}
