#include<iostream>
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
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = temp;
    return head;
}
// Them vao vi tri k
Node* AddK(Node* head, int x, int k) {
    Node* current = head;
    for (int i = 1; i < k - 1; i++) {
        current = current->next;
    }
    Node* temp = new Node(x);
    temp->next = current->next;
    current->next = temp;
    return head;
}
// Xoa dau
Node* DeleteFirst(Node* head) {
    Node* current = head->next;
    delete head;
    return current;
}
// Xoa cuoi
Node* DeleteTail(Node* head) {
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    Node* current = head;
    while (current->next->next!= NULL) {
        current = current->next;
    }
    Node* tmp = current->next;
    current->next = NULL;
    delete tmp;
    return head;
}

// Xoa node tai vi tri k
Node* DeleteK(Node* head, int k) {
    Node* current = head;
    for (int i = 1; i < k - 1 ; i++) {
        current = current->next;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
    return head;
}

struct Stack{
    Node* a;
    Stack(){
        a = NULL;
    }

void push(int item){
    a = AddFirst(a,item);
}
void pop(){
    cout<< a->data<<endl;
    a = DeleteFirst(a);
}
int top(){
    return a->data;
}
void empty(){
    if (a==NULL){
        cout<<"empty"<<endl;
    }else{
        cout<<"not empty";
    }
}
};
int main(){
    Stack s;
    s.push(1);
    s.push(2);
    int a= s.top();
    cout<<a<<endl;
    s.pop();
    s.pop();
    s.empty();
    return 0;
}
