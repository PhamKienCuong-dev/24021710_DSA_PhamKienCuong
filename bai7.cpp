#include <iostream>
using namespace std;

int Tong(int a[][100], int n, int m) {
    int tong = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            tong += a[i][j];
        }
    }

    return tong;
}

void XoaDong(int a[][100], int &n, int m, int i) {
    for(int k = i - 1; k < n - 1; k++) {
        for(int j = 0; j < m; j++) {
            a[k][j] = a[k + 1][j];
        }
    }

    n--;
}

int main() {
    int n, m;
    int a[100][100];

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Tong = " << Tong(a, n, m) << endl;

    int i;
    cin >> i;

    XoaDong(a, n, m, i);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
// Do phuc tap O(NM)
// Bo nho O(1)
