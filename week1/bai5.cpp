#include <iostream>
using namespace std;

int main() {
    int n;
    double a[100];
    double tong = 0, trungbinh;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tong += a[i];
    }

    trungbinh = tong / n;

    for (int i = 0; i < n; i++) {
        if (a[i] >= trungbinh) {
            cout << a[i] << " ";
        }
    }

    return 0;
}
// Do phuc tap O(N)
// Bo nho O(1)
