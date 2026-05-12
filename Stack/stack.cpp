#include <iostream>
using namespace std;

const int n = 100;

class Stack {
    private:
    int *arr;
    int top;
    public:
    Stack();
    void push(int x);
    void pop();
    int getTopValue();
    bool isEmpty();
};

Stack::Stack() {
    arr = new int[n];
    top = -1;
}

void Stack::push(int x) {
    if(top == n - 1) {
        cout << "Stack is full" << endl;
        return;
    }

    arr[++top] = x;
    cout << x << " is push in stack." << endl;
}

void Stack::pop() {
    if(top == -1) {
        cout << "stack is empty" << endl;
        return;
    }

    cout << arr[top--] << " is popped" << endl;
}

int Stack::getTopValue() {
    if(top == -1) {
        cout << "Stack is empty" << endl;
        return -1;
    }

    return arr[top];
}

bool Stack::isEmpty() {
    if(top == -1) {
        return true;
    } else {
        return false;
    }
}

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);
    cout << st.getTopValue() << endl;
    
    st.pop();
    cout << st.getTopValue() << endl;

    st.pop();
    st.pop();

    if(st.isEmpty()) {
        cout << "Your stack is empty" << endl;
    } else {
        cout << "Your stack is not empty" << endl;
    }

    return 0;
}