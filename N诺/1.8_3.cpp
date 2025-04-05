#include<bits/stdc++.h>
using namespace std;

int main(){
	priority_queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	while(!q.empty()){
		cout<<q.top()<<endl;
		q.pop();
	}
}
