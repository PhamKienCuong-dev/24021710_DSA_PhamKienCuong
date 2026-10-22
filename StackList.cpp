#include <iostream>
using namespace std;

struct Stack {
    int a[100];
    int n = 0;

    bool empty() {
        if (n == 0) {
            return true;
        } else {
            return false;
        }
    }

    void push(int item) {
        a[n] = item;
        n++;
    }

    int pop() {
        if (empty()) return -1;
        n--;
        return a[n];
    }

    int top() {
        if (empty()) return -1;
        return a[n - 1];
    }
};

int main() {
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << boolalpha << s.empty() << endl;

    return 0;
}
