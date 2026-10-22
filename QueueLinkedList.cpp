
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Them vao dau
Node* AddFirst(Node* head, int x) {
    Node* temp = new Node(x);
    temp->next = head;
    return temp;
}

// Them vao cuoi
Node* AddTail(Node* head, int x) {
    Node* temp = new Node(x);

    if (head == NULL) {
        return temp;
    }

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = temp;
    return head;
}

// Them vao vi tri k (tinh tu 1)
Node* AddK(Node* head, int x, int k) {
    if (k < 1) return head;

    if (k == 1) {
        return AddFirst(head, x);
    }

    Node* current = head;

    for (int i = 1; i < k - 1; i++) {
        if (current == NULL) return head;
        current = current->next;
    }

    if (current == NULL) return head;

    Node* temp = new Node(x);
    temp->next = current->next;
    current->next = temp;

    return head;
}

// Xoa dau
Node* DeleteFirst(Node* head) {
    if (head == NULL) return NULL;

    Node* current = head->next;
    delete head;

    return current;
}

// Xoa cuoi
Node* DeleteTail(Node* head) {
    if (head == NULL) return NULL;

    if (head->next == NULL) {
        delete head;
        return NULL;
    }

    Node* current = head;

    while (current->next->next != NULL) {
        current = current->next;
    }

    Node* temp = current->next;
    current->next = NULL;
    delete temp;

    return head;
}

// Xoa node tai vi tri k (tinh tu 1)
Node* DeleteK(Node* head, int k) {
    if (head == NULL || k < 1) return head;

    if (k == 1) {
        return DeleteFirst(head);
    }

    Node* current = head;

    for (int i = 1; i < k - 1; i++) {
        if (current == NULL) return head;
        current = current->next;
    }

    if (current == NULL || current->next == NULL) {
        return head;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;

    return head;
}

// Cai dat Queue bang Linked List
struct Queue {
    Node* a;

    Queue() {
        a = NULL;
    }

    // Them vao cuoi hang doi
    void enqueue(int item) {
        a = AddTail(a, item);
    }

    // Lay va xoa phan tu dau hang doi
    void dequeue() {
        if (empty()) {
            cout << "Queue rong" << endl;
            return;
        }

        cout << a->data << endl;
        a = DeleteFirst(a);
    }

    // Xem phan tu dau hang doi
    int front() {
        return a->data;
    }

    // Kiem tra Queue rong
    bool empty() {
        return a == NULL;
    }
};

int main() {
    Queue tmp;

    tmp.enqueue(1);
    tmp.enqueue(2);
    tmp.enqueue(3);

    if (!tmp.empty()) {
        cout << "Front: " << tmp.front() << endl;
    }

    tmp.dequeue();
    tmp.dequeue();
    tmp.dequeue();

    if (tmp.empty()) {
        cout << "Queue rong" << endl;
    } else {
        cout << "Queue khong rong" << endl;
    }

    return 0;
}

