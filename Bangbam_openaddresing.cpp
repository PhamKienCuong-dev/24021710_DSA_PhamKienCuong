#include <iostream>
using namespace std;
const int SIZE = 10;
class Node {
public:
    int key, value;
    Node(int x, int y) {
        key = x;
        value = y;
    }
};
struct openaddressing {
    Node* table[SIZE];
    openaddressing(){
        for (int i = 0; i < SIZE; i++) {
            table[i] = NULL;
        }
    }
    // Ham bam
    int hashFunction(int key) {
        return key%SIZE;
    }
    void push(int key, int value){
        Node* tmp = new Node(key,value);
        int index = hashFunction(key);
        if(table[index]==NULL){
            table[index] = tmp;
            return;
        }else{
            int i = index;
    int count = 0;

    while (table[i] != NULL && count < SIZE) {
        i = (i + 1) % SIZE;
        count++;
    }
    if (count < SIZE) {
        table[i] = tmp;
    } else {
        delete tmp;
        cout << "Hash table is full!\n";
    }
        }
    }
    int get(int key) {
        int index = hashFunction(key);
        for (int count = 0; count < SIZE; count++) {
           int i = (index + count) % SIZE;
           if (table[i] == NULL) {
            cout << "This key is not in table\n";
            return -1;
           }
           if (table[i]->key == key) {
            return table[i]->value;
        }
    }
    cout << "This key is not in table\n";
    return -1;
    }
    bool contain(int key){
        int index = hashFunction(key);
        for (int count = 0; count < SIZE; count++) {
           int i = (index + count) % SIZE;
           if (table[i] == NULL) {
            return false;
           }
           if (table[i]->key == key) {
            return true;
        }
    }
    return false;
    }
};
int main() {
    openaddressing ht;

    ht.push(12, 100);
    ht.push(22, 200);
    ht.push(32, 300);

    cout << ht.get(22) << endl;       // 200
    cout << ht.contain(32) << endl;   // 1
    cout << ht.contain(42) << endl;   // 0
    
    return 0;
}
