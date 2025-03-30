#include<bits/stdc++.h>
using namespace std;

int v[101]={0};//尽量将数组开在全局 
int n[101]={0}; //n[i]表示个数为i的最大值 
int main(){
	int N;
	cin>>N;
	int num;
	for(int i=1;i<=N;i++){
		cin>>num;
		v[num]++;
	}
	for(int i=1;i<=100;i++){
		n[v[i]]=i;
	}
	for(int i=1;i<=100;i++){
		if(n[i]>0){
			cout<<n[i]<<" "<<i<<endl;
		}
	}
}
