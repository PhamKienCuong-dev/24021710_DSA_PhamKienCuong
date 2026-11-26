#include<iostream>
using namespace std;
class Node{
    public:
    string key;
    int value;
    Node* next;
    Node(string x, int y){
        key = x;
        value = y;
        next = NULL;
    }
};
class ST{
    private:
    Node* head;
    public:
    ST(){
        head = NULL;
    }
    void put(string x, int y){
        Node* tmp = head;
        while(tmp != NULL){
            if(tmp->key == x){
                tmp->value = y;
                return;
            }
            tmp = tmp->next;
        }
        Node* newNode = new Node(x, y);
        newNode->next = head;
        head = newNode;
    }
    int get(string x){
        Node* tmp = head;
        while(tmp != NULL){
            if(tmp->key == x){
                return tmp->value;
            }
            tmp = tmp->next;
        }
        
        cout << "not in table" << endl;
        return 0; 
    }
    bool contains(string x){
        Node* tmp = head;
        while(tmp != NULL){
            if(tmp->key == x){
                return true;
            }
            tmp = tmp->next;
        }
        return false;
    }
    void removeNode(string x){
        if(head == NULL){
            return;
        }
        if(head->key == x){
            Node* tmp = head;
            head = head->next;
            delete tmp; 
            return;
        }
        Node* prev = head;
        Node* curr = head->next;
        while(curr != NULL && curr->key != x){
            prev = curr;
            curr = curr->next;
        }
        if(curr != NULL){
            prev->next = curr->next; 
            delete curr;             
        }
    }
};
int main(){
    ST a;
    a.put("A",1);
    a.put("B",2);
    a.put("C",3);
    cout<<a.get("A");
    a.put("A",4);
    cout<<a.get("A");
}
