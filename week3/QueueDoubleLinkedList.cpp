#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* back;
    Node(int x){
        data = x;
        next = NULL;
        back = NULL;
    }
};
Node* Inserthead(Node* head, Node*& tail, int x){
    Node* tmp = new Node(x);
    if(head == NULL){
        tail = tmp;
        return tmp;
    }
    tmp->next = head;
    head->back = tmp;
    return tmp;
}
Node* Inserttail(Node*head, Node*& tail, int x){
    Node* tmp = new Node(x);
    if(tail == NULL){
        tail = tmp;
        return tmp;
    }
    tail->next = tmp;
    tmp->back = tail;
    return head;
}
Node* Insertk(Node* head, Node*& tail, int x, int k){
    Node* current = head;
    for(int i=1;i<k-1;i++){
        current = current->next;
    }
    Node* tmp = new Node(x);
    Node* tmpback = current->next;
    tmp->next = tmpback;
    tmpback->back = tmp;
    current->next = tmp;
    tmp->back = current;
    return head;
}
Node* Deletehead(Node* head, Node*& tail){
    if(head == NULL){
        return NULL;
    }
    Node* tmp = head->next;
        delete head;
    if(tmp == NULL){
        tail = NULL;
        return NULL;
    }
    tmp->back = NULL;
    return tmp;
}
Node* Deletetail(Node* head, Node*& tail){
    if(tail == NULL){
        return NULL;
    }
    Node* tmp = tail->back;
    delete tail;
    if(tmp == NULL){
        tail = NULL;
        return NULL;
    }
    tmp->next = NULL;
    tail = tmp;
    return head;
}
Node* Deletek(Node* head, Node*& tail, int k){
    Node* current = head;
    for(int i=1;i<k-1;i++){
        current = current->next;
    }
    Node* tmp1 = current->next;
    Node* tmp2 = tmp1->next;
    current->next = tmp2;
    tmp2->back = current;
    delete tmp1;
    return head;
}
struct Queue{
    Node* a;
    Node* b;
    Queue(){
        a = NULL;
        b = NULL;
    }
    void enqueue(int item){
        a = Inserthead(a,b,item);
    }
    void dequeue(){
         if (b == NULL) {
           cout << "Queue empty" << endl;
           return;
        }
        cout<<b->data<<endl;
        a = Deletetail(a,b);
    }
    int top(){
        return a->data;
    }
    void empty(){
        if(a == NULL || b == NULL){
            cout<<"empty"<<endl;
        }else{
            cout<<"no empty"<<endl;
        }
    }
};
int main(){
    Queue a;
    a.enqueue(1);
    a.enqueue(2);
    int h = a.top();
    cout<<h<<endl;
    a.dequeue();
    a.dequeue();
    a.empty();
}
