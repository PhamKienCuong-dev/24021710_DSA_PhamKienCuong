#include<iostream>
using namespace std;

struct Queue{
    int a[100];
    int front = 0;
    int rear = 0;

    void enqueue(int item){
        a[rear] = item;
        rear++;
    }

    int dequeue(){
        int item = a[front];
        front++;
        return item;
    }

    void empty(){
        if(front == rear){
            cout<<"empty";
        }else{
            cout<<"not empty";
        }
    }
};

int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    q.empty();
    return 0;
}
