#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int tich = 1;
	for(int i=0;i<n;i++){
		tich *= (i+1);
	}
	cout<<tich;
	return 0;
}
// Do phuc tap O(N)
// Bo nho O(1)
