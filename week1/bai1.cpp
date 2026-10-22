#include<iostream>
using namespace std;
int main(){
	int n;
	int sum = 0;
	cin>>n;
	int a[1000];
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum += a[i];
	}
    cout<<sum;
    return 0;
}
// Do phuc tap O(N)
// Bo nho O(1)
