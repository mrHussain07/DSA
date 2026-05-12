#include <iostream>
using namespace std;

const int n = 100;

class DeQueue {
    private:
    int *arr;
    int front, rear;
    public:
    DeQueue();
    void push_front(int x);
    void push_rear(int x);
    void pop_front();
    void pop_rear();
};

DeQueue::DeQueue() {
    arr = new int[n];
    front = rear = -1;
}

void DeQueue::push_front(int x) {
    if(front == 0) {
        cout << "Front is full!" << endl;
        return;
    } else {
        if(front == -1) {
            front = rear = 0;
        } else {
            front--;
        }

        arr[front] = x;
        cout << "value is push at front..." << endl;
    }
}

void DeQueue::push_rear(int x) {
    if(rear == n-1) {
        cout << "Rear is full!" << endl;
        return;
    } else {
        if(rear == -1) {
            front = rear = 0;
        } else {
            rear++;
        }

        arr[rear] = x;
        cout << "Value is pushed at rear..." << endl;
    }
}

void DeQueue::pop_front() {
    if(front == -1) {
        cout << "Dequeue is empty!" << endl;
        return;
    }

    cout << "Popped element: " << arr[front++] << endl;
}

void DeQueue::pop_rear() {
    if(rear == -1) {
        cout << "Dequeue is empty!" << endl;
        return;
    }

    cout << "Popped element: " << arr[rear--] << endl; 
}

int main() {
    DeQueue dq;
    dq.push_front(1);
    dq.push_rear(2);
    dq.push_rear(3);
    // dq.pop_front();
    // dq.pop_front();
    // dq.pop_front();
    dq.pop_rear();
    dq.pop_rear();
    dq.pop_rear();
    return 0;
}