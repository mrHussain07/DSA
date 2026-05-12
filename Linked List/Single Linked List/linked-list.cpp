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
    void insert_middle(int val, int pos);
    void pop_front();
    void pop_back();
    void delete_mid_node(int pos);
    int search_value(int key);
    void display_list();
};

List::List() {
    head = tail = NULL;
}

// =========================
//     Start Insertion
// =========================

void List::push_front(int val) {
    Node *newNode = new Node(val);
    if(head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

// =========================
//     End Insertion
// =========================

void List::push_back(int val) {
    Node *newNode = new Node(val);
    if(head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// =========================
//     Middle Insertion
// =========================

void List::insert_middle(int val, int pos) {
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
            cout << "Invalid Position" << endl;
            return;
        } else {
            temp = temp->next;
        }
    }

    Node *newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
}

// =========================
//     Start Deletion
// =========================

void List::pop_front() {
    if(head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
}

// =========================
//     End Deletion
// =========================

void List::pop_back() {
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

    while(temp->next != tail) {
        temp = temp->next;
    }

    temp->next = NULL;
    delete tail;
    tail = temp;
}

// =========================
//     Middle Deletion
// =========================

void List::delete_mid_node(int pos) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    if (pos < 0) {
        cout << "Invalid position!" << endl;
        return;
    }

    if (pos == 0) {
        pop_front();
        return;
    }

    Node *temp = head;

    for (int i = 0; i < pos - 1; i++) {
        if (temp->next == NULL) {
            cout << "Invalid position!" << endl;
            return;
        }
        temp = temp->next;
    }

    // temp is now at (pos - 1), target node is temp->next
    Node *target = temp->next;

    if (target == NULL) {
        cout << "Invalid position!" << endl;
        return;
    }

    // If deleting the tail, update tail pointer
    if (target == tail) {
        tail = temp;
    }

    temp->next = target->next;
    target->next = NULL;
    delete target;
}

// =========================
//     Searching Value
// =========================

int List::search_value(int key) {
    Node *temp = head;
    int index = 0;

    while(temp) {
        if(temp->data == key) {
            return index;
        } else {
            temp = temp->next;
            index++;
        }
    }

    return -1;
}

// =======================================
//     Traversing through Linked List
// =======================================

void List::display_list() {
    Node *temp = head;
    while(temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// =====================
//     Driver Code
// =====================

int main() {
    List ll;
    
    ll.push_front(32);
    ll.push_front(17);
    ll.push_front(28);
    ll.push_front(98);
    
    // ll.push_back(4);
    // ll.push_back(5);
    // ll.push_back(6);

    // ll.display_list();
    // cout << endl;

    // ll.pop_front();
    // ll.pop_back();

    ll.display_list();

    // ll.insert_middle(10, 2);

    // ll.display_list();

    // cout << ll.search_value(17) << endl;
    // cout << ll.search_value(32) << endl;
    // cout << ll.search_value(98) << endl;
    // cout << ll.search_value(100) << endl;

    ll.delete_mid_node(5);
    ll.display_list();

    return 0;
}