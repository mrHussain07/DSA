#include <iostream>
#include <algorithm>
using namespace std;

class MinHeap {
private:
    int *arr;
    int size;
    int total_size;

public:
    MinHeap(int n);
    ~MinHeap();

    void insert(int value);
    void print() const;
};

MinHeap::MinHeap(int n) {
    arr = new int[n];
    size = 0;
    total_size = n;
}

MinHeap::~MinHeap() {
    delete[] arr;
}

void MinHeap::insert(int value) {
    if(size == total_size) {
        cout << "Heap is full!" << endl;
        return;
    }

    arr[size] = value;
    int index = size;
    size++;

    // Min Heap Logic
    while(index > 0 && arr[(index - 1) / 2] > arr[index]) {
        swap(arr[index], arr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }

    cout << arr[index] << " is inserted into heap" << endl;
}

void MinHeap::print() const {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main() {
    int arr[8] = {20, 10, 45, 5, 60, 25, 40, 70};

    MinHeap h1(8);

    for(int i = 0; i < 8; i++) {
        h1.insert(arr[i]);
    }

    h1.print();

    return 0;
}