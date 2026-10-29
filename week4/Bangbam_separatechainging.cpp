#include <iostream>
using namespace std;
const int SIZE = 10;
class Node {
public:
    int key, value;
    Node* next;

    Node(int x, int y) {
        key = x;
        value = y;
        next = NULL;
    }
};
struct separatechaining {
    Node* table[SIZE];
    separatechaining() {
        for (int i = 0; i < SIZE; i++) {
            table[i] = NULL;
        }
    }
    int hashFunction(int key) {
        return key % SIZE;
    }
    void push(int key, int value) {
        int index = hashFunction(key);
        Node* cur = table[index];
        while (cur != NULL) {
            if (cur->key == key) {
                cur->value = value;
                return;
            }
            cur = cur->next;
        }
        Node* tmp = new Node(key, value);
        tmp->next = table[index];
        table[index] = tmp;
    }
    int get(int key) {
        int index = hashFunction(key);
        Node* cur = table[index];
        while (cur != NULL) {
            if (cur->key == key) {
                return cur->value;
            }
            cur = cur->next;
        }
        return -1;
    }
    bool contain(int key) {
        int index = hashFunction(key);
        Node* cur = table[index];
        while (cur != NULL) {
            if (cur->key == key) {
                return true;
            }
            cur = cur->next;
        }
        return false;
    }
};

int main() {
    separatechaining ht;

    ht.push(15, 100);
    ht.push(25, 200);
    ht.push(35, 300);
    ht.push(7, 400);

    cout << ht.get(25) << endl;
    cout << ht.contain(35) << endl;
    cout << ht.contain(99) << endl;

    return 0;
}
