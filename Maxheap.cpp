#include<iostream>
using namespace std;
void swim(int a[], int n, int k){
    while(k > 1 && a[k-1] > a[k/2-1]){
        swap(a[k-1], a[k/2-1]);
        k = k/2;
    }
}
void insert(int a[], int &n, int x){
    n++;
    a[n-1] = x;
    swim(a,n,n);
}
void sink(int a[], int n, int k){
    while(2*k <= n){
        int j = 2*k;
        if(j < n && a[j-1] < a[j]){
            j++;
        }
        if(a[k-1] >= a[j-1]){
            break;
        }
        swap(a[k-1],a[j-1]);
        k = j;
    }
}

void deleteroot(int a[], int &n){
    if(n == 0){return;}
    swap(a[0],a[n-1]);
    n--;
    sink(a,n,1);
}
void heapsort(const int a[], int n, int b[]){
    int temp_a[100];
    int temp_n = n;
    for(int i = 0; i < n; i++){
        temp_a[i] = a[i];
    }
    for(int i = 0; i < n; i++){
        deleteroot(temp_a, temp_n);
        b[i] = temp_a[temp_n]; 
    }
}
int main(){
    int a[100];
    int n = 0;
    int b[100];
    insert(a,n,5);
    insert(a,n,2);
    insert(a,n,3);
    insert(a,n,4);
    insert(a,n,6);
    heapsort(a,n,b);
    for(int i=1;i<=n;i++){
        cout<<b[i-1]<<" ";
    }

    deleteroot(a,n);
    for(int i=1;i<=n;i++){
        cout<<a[i-1]<<" ";
    }

    return 0;
}
