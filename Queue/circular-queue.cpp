#include <iostream>
using namespace std;

const int n = 100;

class CircularQueue {
    private:
    int *arr;
    int front, rear;
    public:
    CircularQueue();
    void push(int x);
    void pop();
    void display() const;
};

CircularQueue::CircularQueue() {
    arr = new int[n];
    front = rear = -1;
}

void CircularQueue::push(int x) {
    if((rear+1) % n == front) {
        cout << "Queue is full!" << endl;
        return;
    }

    if(front == -1) {
        front++;
    }

    rear = (rear+1) % n;
    arr[rear] = x;
}

void CircularQueue::pop() {
    if(front == -1 && front > rear) {
        cout << "Queue is empty!" << endl;
        return;
    }

    cout << "Popped element: " << arr[front] << endl;

    if(front == rear) {
        front = rear = -1;
    } else {
        front = (front+1) % n;
    }
}

void CircularQueue::display() const {
    if(front == -1) {
        cout << "Queue is empty!" << endl;
        return;
    }

    int temp = front;
    
    while(true) {
        cout << arr[temp] << " ";
        
        if(temp == rear) {
            break;
        } else {
            temp = (temp+1) % n;
        }
    }

    cout << endl;
}

int main() {
    CircularQueue cq;
    cq.push(10);
    cq.push(20);
    cq.push(30);
    cq.push(40);
    cq.push(50);
    cq.display();

    cq.pop();
    cq.pop();
    cq.pop();
    cq.display();
    return 0;
}