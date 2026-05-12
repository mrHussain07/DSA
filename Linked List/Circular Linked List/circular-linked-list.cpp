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

class CircularList {
    private:
    Node *head, *tail;
    public:
    CircularList();
    void insert_at_head(int val);
    void insert_at_tail(int val);
    void delete_at_head();
    void delete_at_tail();
    void display_list();
};

CircularList::CircularList() {
    head = tail = NULL;
}

void CircularList::insert_at_head(int val) {
    Node *newNode = new Node(val);

    if(head == NULL) {
        head = tail = newNode;
        tail->next = head;
    } else {
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
}

void CircularList::insert_at_tail(int val) {
    Node *newNode = new Node(val);

    if(head == NULL) {
        head = tail = newNode;
        tail->next = head;
    } else {
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
    }
}

void CircularList::delete_at_head() {
    if(head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    if(head == tail) {
        delete head;
        head = tail = NULL;
        return;
    }
    
    Node *temp = head;
    head = head->next;
    tail->next = head;
    temp->next = NULL;
    delete temp;
}

void CircularList::delete_at_tail() {
    if(head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    if(head == tail) {
        delete head;
        head = tail = NULL;
        return;
    }

    Node *temp = tail;
    Node *prev = head;

    while(prev->next != tail) {
        prev = prev->next;
    }

    tail = prev;
    tail->next = head;
    temp->next = NULL;
    delete temp;
}

void CircularList::display_list() {
    if(head == NULL) {
        return;
    }

    Node *temp = head;

    do{
        cout << temp->data << " -> ";
        temp = temp->next;
    } while(temp != head);

    cout << temp->data << endl;
}

int main() {
    CircularList cll;

    // cll.insert_at_head(3);
    // cll.insert_at_head(2);
    // cll.insert_at_head(1);
    
    cll.insert_at_tail(1);
    cll.insert_at_tail(2);
    cll.insert_at_tail(3);

    // cll.delete_at_head();
    cll.delete_at_tail();

    cll.display_list();
    return 0;
}