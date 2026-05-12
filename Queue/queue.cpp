#include <iostream>
using namespace std;

const int n = 10;

class Queue {
    private:
    int *arr;
    int front, back;
    public:
    Queue();
    void enQueue(int x);
    void deQueue();
    int getPeekValue();
    int getRearValue();
    bool isEmpty();
};

Queue::Queue() {
    arr = new int[n];
    front = back = -1;
};

void Queue::enQueue(int x) {
    if(back == n - 1) {
        cout << "Queue id full!" << endl;
        return;
    }

    if(front == -1) {
        front++;
    }

    arr[++back] = x;
}

void Queue::deQueue() {
    if(front == -1 || front > back) {
        cout << "Queue is empty!" << endl;
        return;
    }

    cout << "Popped Element: " << arr[front++] << endl;
}

int Queue::getPeekValue() {
    if(front == -1 || front > back) {
        cout << "Queue is empty!" << endl;
        return -1;
    }

    return arr[front];
}

int Queue::getRearValue() {
    if(front == -1 || front > back) {
        cout << "Queue is empty!" << endl;
        return -1;
    }

    return arr[back];
}

bool Queue::isEmpty() {
    if(front == -1 || front > back) {
        return true;
    } else {
        return false;
    }
}

int main() {
    Queue q;
    q.enQueue(100);
    q.enQueue(200);
    q.enQueue(300);
    // cout << q.getPeekValue() << endl;
    // cout << q.getRearValue() << endl;
    // q.deQueue();
    // q.deQueue();
    // cout << q.getPeekValue() << endl;
    // cout << q.getRearValue() << endl;

    //display funtion
    int front = q.getPeekValue();
    int rear = q.getRearValue();
    for(int i = front; i <= rear; i++) {
        q.deQueue();
    }

    return 0;
}