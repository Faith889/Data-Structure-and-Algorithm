#include<bits/stdc++.h>
using namespace std;

int v[100]={0};//尽量将数组开在全局 
int main(){
	int N;
	cin>>N;
	int num;
	for(int i=0;i<N;i++){
		cin>>num;
		v[num-1]++;
	}
	for(int i=0;i<100;i++){
		if(v[i]>0){
			cout<<i+1<<" "<<v[i]<<endl;
		}
	}
}
