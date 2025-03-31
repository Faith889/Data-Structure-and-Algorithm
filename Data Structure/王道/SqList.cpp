#include<bits/stdc++.h>
using namespace std;


#define ElemType int
#define MaxSize 50
typedef struct{
	ElemType data[MaxSize];
	int length;
}SqList;

//#define InitSize 100
//typedef struct{
//	ElemType *data;
//	int MaxSize,length;
//}SeqList;

void InitList(SqList &L){
	L.length=0;
}

//void InitList(SeqList &L){
//	L.data=new ElemType[InitSize];
//	L.length=0;
//	L.MaxSize=InitSize;
//}

bool ListInsert(SqList &L,int i,ElemType e){
	if(i<1||i>L.length+1){
		return false;
	}
	if(L.length>=MaxSize){
		return false;
	}
	for(int j=L.length;j>=i;j--){
		L.data[j]=L.data[j-1];
	}
	L.data[i-1]=e;
	L.length--;
	return true;
}

bool ListDelete(SqList &L,int i,ElemType &e){
	if(i<1||i>L.length){
		return false;
	}
	e=L.data[i-1];
	for(int j=i;j<L.length;j++){
		L.data[j-1]=L.data[j];
	}
	L.length--;
	return true;
}

int LocateElem(SqList L,ElemType e){
	int i;
	for(i=0;i<L.length;i++){
		if(L.data[i]==e){
			return i+1;
		}
	}
	return 0;
}

void ListInput(SqList &L, int n) //顺序表数据的输入
{
	int i = 0;
	for (i=0; i<n; i++){
		cout<<"请输入第"<<i+1<<"个数据:";
		cin>>L.data[i];
	}
	L.length = i;

}

void ListOutput(SqList &L) //输出List
{
	cout<<"顺序表为:";
	for (int i = 0; i < L.length; i++)
		cout << L.data[i] << " ";
	cout << endl;
}


//01
ElemType DeleteMinimum(SqList &L){
	if(L.length==0){
		return NULL;
	}
	ElemType min=L.data[0];
	int min_i=0;
	for(int i=1;i<L.length;i++){
		if(L.data[i]<min){
			min=L.data[i];
			min_i=i;
		}
	}
	L.data[min_i]=L.data[L.length-1];
	L.length--;                      //空出的位置由最后一个元素填补 
	return min;
}

//02
void Reverse(SqList &L){
	ElemType temp;
	for(int i=0;i<L.length/2;i++){
		temp=L.data[i];
		L.data[i]=L.data[L.length-1-i];
		L.data[L.length-1-i]=temp;
	}
}

//03
void del_x(SqList &L,ElemType x){
	int k=0,i;
	for(i=0;i<L.length;i++){
		if(L.data[i]!=x){
			L.data[k]=L.data[i];
			k++;
		}
	}
	L.length=k;
}

//04
bool Del_s_t(SqList &L,ElemType s,ElemType t){
	if(s>=t||L.length==0){
		return false;
	}
	int k=0,i;
	for(i=0;i<L.length;i++){
		if(L.data[i]>=s&&L.data[i]<=t){
			k++;
		}else{
			L.data[i-k]=L.data[i];
		}
	}
	L.length-=k;
	return true;
}

//05
bool Delete_Same(SqList &L){
	if(L.length==0){
		return false;
	}
	int i=0,j;
	for(j=1;j<L.length;j++){
		if(L.data[i]!=L.data[j]){
			L.data[++i]=L.data[j];
		}
	}
	L.length=i+1;
	return true;
}

int main(){
	SqList L;
	InitList(L);
	int n,e;
	cin>>n;
	ListInput(L,n);
	Delete_Same(L);
	ListOutput(L);
}
