#include<iostream>
using namespace std;
void selectionsort(int a[], int n){
    for(int i=0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            if(a[i]>a[j]){
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}
void bubblesort(int a[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}
void sapxepchen(int a[], int n){
    for(int i = 1; i < n; i++){
        int key = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}
void merge(int a[], int l, int mid, int r){
    int n1 = mid-l+1;
    int n2 = r-mid;
    int L[n1];
    int R[n2];
    for(int i=0;i<n1;i++){
        L[i] = a[l+i];
    }
    for(int j=0;j<n2;j++){
        R[j] =a[mid+1+j];
    }
    int i=0, j=0, k=l;
    while(i<n1 && j<n2 ){
        if(L[i]<=R[j]){
            a[k] = L[i];
            i++;
            k++;
        }else{
            a[k] = R[j];
            j++;
            k++;
        }
    }
    while(i<n1){
        a[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        a[k] = R[j];
        j++;
        k++;
    }
}
void mergesort(int a[], int l, int r){
    if(l>=r){
        return;
    }else{
        int mid = (l+r)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}
void quicksort(int a[], int l, int r){
    if(l>=r){
        return;
    }else{
    int pivot = a[l];
    int i = l+1;
    int j = r;
    while(i<=j){
        int done1 = 0, done2 = 0;
        if(a[i]<=pivot){
            i++;
        }else{
            done1 = 1;
        }
        if(a[j]>=pivot){
            j--;
        }else{
            done2 = 1;
        }
        if(done1==1 && done2 ==1){
            int tmp = a[i];
            a[i]=a[j];
            a[j]=tmp;
            i++;
            j--;
        }
    }
    int tmp2 = a[l];
    a[l]=a[j];
    a[j] = tmp2;
    quicksort(a,l,j-1);
    quicksort(a,j+1,r);
}}
int main(){
    int a[] = {8,7,5,2,4,3,1,6};
    int n = 8;
    quicksort(a,0,7);
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    return 0;
}