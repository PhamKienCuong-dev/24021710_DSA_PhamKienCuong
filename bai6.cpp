#include <iostream>
using namespace std;

void Xoa(int a[], int &n, int k) {
    for (int i = k - 1; i < n - 1; i++) {
        a[i] = a[i + 1];
    }

    n--;
}

void Chen(int a[], int &n, int y, int m) {
    for (int i = n; i >= m; i--) {
        a[i] = a[i - 1];
    }

    a[m - 1] = y;
    n++;
}

int main() {
    int n;
    int a[100];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int k;
    cin >> k;
    Xoa(a, n, k);

    int y, m;
    cin >> y >> m;
    Chen(a, n, y, m);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
// Do phuc tap O(NM)
// Bo nho O(1)
