#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *prev, *next;
    Node(int val) {
        data = val;
        prev = next = NULL;
    }
};

class DoublyList {
    private:
    Node *head, *tail;
    public:
    DoublyList();
    void push_front(int val);
    void push_back(int val);
    void insert_node(int val, int pos);
    void pop_front();
    void pop_back();
    void display_list();
    int search_node(int key);
};

DoublyList::DoublyList() {
    head = tail = NULL;
}

void DoublyList::push_front(int val) {
    Node *newNode = new Node(val);
    if(head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void DoublyList::push_back(int val) {
    Node *newNode = new Node(val);
    if(head == NULL) {
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void DoublyList::insert_node(int val, int pos) {
    if(pos < 0) {
        cout << "Invalid position" << endl;
        return;
    }

    if(pos == 0) {
        push_front(val);
        return;
    }

    Node *temp = head;

    for(int i = 0; i < pos - 1; i++) {
        if(temp == NULL) {
            cout << "Invalid position" << endl;
            return;
        }

        temp = temp->next;
    }

    Node *newNode = new Node(val);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next = newNode;
    temp->next->prev = newNode; 
}

void DoublyList::pop_front() {
    if(head == NULL) {
        cout << "List is empty..." << endl;
        return;
    }

    Node *temp = head;
    head = head->next;

    if(head != NULL) {
        head->prev = NULL;
    }

    temp->next = NULL;
    delete temp;
}

void DoublyList::pop_back() {
    if(head == NULL) {
        cout << "List is empty..." << endl;
        return;
    }

    Node *temp = tail;
    tail = tail->prev;

    if(tail != NULL) {
        tail->next = NULL;
    }

    temp->prev = NULL;
    delete temp;
}

void DoublyList::display_list() {
    Node *temp = head;
    while(temp) {
        cout << temp->data << " <=> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int DoublyList::search_node(int key) {
    Node *temp = head;
    int index = 0;

    while(temp != NULL) {
        if(temp->data == key) {
            return index;
        }

        temp = temp->next;
        index++;
    }

    return -1;
}

int main() {
    DoublyList dll;

    dll.push_front(30);
    dll.push_front(20);
    dll.push_front(10);

    dll.push_back(40);
    dll.push_back(50);
    dll.push_back(60);

    dll.insert_node(35, 6);
    dll.display_list();

    // dll.pop_front();
    // dll.pop_front();
    // dll.pop_front();
    // dll.display_list();

    // dll.pop_back();
    // dll.pop_back();
    // dll.pop_back();
    // dll.display_list();

    cout << "Index value of node is: " << dll.search_node(35) << endl;
    return 0;
}