#include<bits/stdc++.h>
using namespace std;

int a[105];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);//sort(Ҫ������������,Ҫ����������յ�+1,�ȽϺ���)���ȽϺ������Բ����Ĭ��Ϊ��С��������
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}
