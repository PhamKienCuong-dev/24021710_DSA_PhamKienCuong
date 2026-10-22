#include <iostream>
using namespace std;

int UCLN(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void RutGon(int &a, int &b) {
    int u = UCLN(a, b);
    a = a / u;
    b = b / u;
}

int main() {
    int a, b;
    cin >> a >> b;

    RutGon(a, b);

    cout << a << "/" << b;

    return 0;
}
// Do phuc tap O(logN)
// Bo nho O(1)
