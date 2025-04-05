#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int> v;
	for(int i=1;i<=10;i++){
		v.push_back(i*i);
	}
	for(int i=0;i<10;i++){
		cout<<v[i]<<" ";
	}
}
