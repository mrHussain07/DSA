#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
    private:
    Node *head, *tail;
    public:
    List();
    void push_front(int val);
    void push_back(int val);
    void display_list();
    void reverse_list();
};

List::List() {
    head = tail = NULL;
}

void List::push_front(int val) {
    Node * newNode = new Node(val);

    if(head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void List::push_back(int val) {
    Node *newNode = new Node(val);

    if(head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void List::display_list() {
    Node *temp = head;

    while(temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

// ===========================
//     Reverse Linked List
// ===========================

void List::reverse_list() {
    Node *prev = NULL;
    Node *next = NULL;
    Node *curr = head;

    tail = head;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

int main() {
    List ll;
    
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.display_list();

    ll.reverse_list();
    ll.display_list();
}