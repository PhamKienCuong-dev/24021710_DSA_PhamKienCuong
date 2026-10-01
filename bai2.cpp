#include<iostream>
using namespace std;
void Sapxeptangdan(int n, int a[]){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]){
				int tmp = a[j];
				a[j]=a[i];
				a[i]=tmp;
			}
		}
	}
}
int main(){
	int n;
	cin>>n;
	int a[1000];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	Sapxeptangdan(n,a);
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
	return 0;
}
// Do phuc tap O(N^2)
// Bo nho O(1)
