#include<bits/stdc++.h>
using namespace std;

int a[105];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);//sort(要排序区间的起点,要排序区间的终点+1,比较函数)。比较函数可以不填，则默认为从小到大排序。
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}
