#include<bits/stdc++.h>
using namespace std;

int v[101]={0};//���������鿪��ȫ�� 
int n[101]={0}; //n[i]��ʾ����Ϊi�����ֵ 
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
