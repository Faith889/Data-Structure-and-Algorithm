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

void ListInput(SqList &L, int n) //˳������ݵ�����
{
	int i = 0;
	for (i=0; i<n; i++){
		cout<<"�������"<<i+1<<"������:";
		cin>>L.data[i];
	}
	L.length = i;

}

void ListOutput(SqList &L) //���List
{
	cout<<"˳���Ϊ:";
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
	L.length--;                      //�ճ���λ�������һ��Ԫ��� 
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

/*
//06
bool Merge(SeqList A,SeqList B,SeqList &C){
	if(A.length+B.length>C.MaxSize){
		return false;
	}
	int i=0,j=0,k=0;
	while(i<A.length&&j<B.length){
		if(A.data[i]<=B.data[j]){
			C.data[k++]=A.data[i++];
		}else{
			C.data[k++]=B.data[j++];
		}
	}
	while(i<A.length){
		C.data[k++]=A.data[i++];
	}
	while(j<B.length){
		C.data[k++]=B.data[j++];
	}
	C.length=k;
	return true;
}
*/

//07
void Reverse(ElemType A[],int left,int right,int arraySize){
	if(left>=right||right>=arraySize){
		return;
	}
	int mid=(left+right)/2;
	for(int i=0;i<=mid-left;i++){
		ElemType temp=A[left+i];
		A[left+i]=A[right-i];
		A[right-i]=temp;
	}
}
void Exchange(ElemType A[],int m,int n,int arraySize){
	Reverse(A,0,m+n-1,arraySize);
	Reverse(A,0,n-1,arraySize);
	Reverse(A,n,m+n-1,arraySize);
}

/*
//08
void SearchExchangeInsert(ElemType A[],ElemType x){
	int low=0,high=n-1,mid;
	while(low<=high){
		mid=(low+high)/2;
		if(x==A[mid]){
			break;
		}else if(x<A[mid]){
			high=mid-1;
		}else{
			low=mid+1;
		}
	}
	if(x==A[mid]&&mid!=n-1){
		ElemType temp=A[mid];
		A[mid]=A[mid+1];
		A[mid+1]=temp;
	}
	if(low>high){
		for(int i=n-1;i>high;i--){
			A[i+1]=A[i];
		}
		A[i+1]=x;
	}
}
*/

//09
void SameElem(int A[],int B[],int C[],int n){
	int i=0,j=0,k=0;
	while(i<n&&j<n&&k<n){
		if(A[i]==B[j]&&B[j]==C[k]){
			cout<<A[i];
			i++;j++;k++;
		}else{
			int maxNum=max(A[i],max(B[j],C[k]));
			if(A[i]<maxNum) i++;
			if(B[j]<maxNum) j++;
			if(C[k]<maxNum) k++;
		}
	}
}

//10
void Reverse(int R[],int left,int right){
	if(left>=right){
		return;
	}
	for(int i=0;i<=(right-left)/2;i++){
		int temp=R[left+i];
		R[left+i]=R[right-i];
		R[right-i]=temp;
	}
}
void LeftShift(int R[],int n,int p){
	Reverse(R,0,p-1);
	Reverse(R,p,n-1);
	Reverse(R,0,n-1);
}

//11
int Median(int A[],int B[],int n){
	int l1=0,r1=n-1,m1;
	int l2=0,r2=n-1,m2;
	while(l1<r1&&l2<r2){
		m1=(l1+r1)/2;
		m2=(l2+r2)/2;
		if(A[m1]==B[m2]){
			return A[m1];
		}else if(A[m1]<B[m2]){
			if((l1+r1)%2==0){
				l1=m1;
				r2=m2;
			}else{
				l1=m1+1;
				r2=m2;
			}
		}else{
			if((l1+r1)%2==0){
				r1=m1;
				l2=m2;
			}else{
				r1=m1;
				l2=m2+1;
			}
		}
	}
	return min(A[l1],B[l2]);
} 

//12
int Majority(int A[],int n){
	int i,m=A[0],cnt=1;
	for(i=1;i<n;i++){
		if(A[i]==m){
			cnt++;
		}else{
			if(cnt>0){
				cnt--;
			}else{
				m=A[i];
				cnt=1;
			}
		}
	}
	if(cnt>0){
		for(i=cnt=0;i<n;i++){
			if(A[i]==m){
				cnt++;
			}
		}
	}
	if(cnt>n/2){
		return m;
	}else{
		return -1;
	}
}

//13
int MinPosInt(int A[],int n){
	int i,I[n]={0};
	for(i=0;i<n;i++){
		if(A[i]>=1&&A[i]<=n){
			I[A[i]-1]=1;
		}
	}
	for(i=0;i<n;i++){
		if(I[i]==0){
			break;
		}
	}
	return i+1;
}

//14
//#define INT_MAX 0x7fffffff
int abs_(int a){
	if(a<0){
		return -a;
	}else{
		return a;
	}
}
bool xls_min(int a,int b,int c){
	if(a<=b&&a<=c){
		return true;
	}else{
		return false;
	}
}
int findMinofTrip(int A[],int n,int B[],int m,int C[],int p){
	int i=0,j=0,k=0,D,D_min=INT_MAX;
	while(i<n&&j<m&&k<p&&D_min>0){
		D=abs_(A[i]-B[j])+abs_(B[j]-C[k])+abs_(C[k]-A[i]);
		if(D<D_min){
			D_min=D;
		}
		if(xls_min(A[i],B[j],C[k])) i++;
		else if(xls_min(B[j],C[k],A[i])) j++;
		else k++;
	}
	return D_min;
}

int main(){
	/*05
	SqList L;
	InitList(L);
	int n,e;
	cin>>n;
	ListInput(L,n);
	Delete_Same(L);
	ListOutput(L);
	*/
	/*09
	int A[]={1,2,3},B[]={2,3,4},C[]={-1,0,2};
	SameElem(A,B,C,3); 
	*/
	/*10
	int R[]={1,2,3,4,5,6,7,8};
	LeftShift(R,8,3);
	for(int i=0;i<8;i++){
		cout<<R[i]<<" ";
	}
	*/
	/*11
	int S1[]={11,13,15,17,19},S2[]={2,4,6,8,20};
	cout<<Median(S1,S2,5);
	*/
	/*12
	int A1[]={0,5,5,3,5,7,5,5},A2[]={0,5,5,3,5,1,5,7};
	cout<<Majority(A1,8)<<endl<<Majority(A2,8);
	*/
	/*13
	int A1[]={-5,3,2,3},A2[]={1,2,3};
	cout<<MinPosInt(A1,4)<<endl<<MinPosInt(A2,3);
	*/
	/*14
	int S1[]={-1,0,9},S2[]={-25,-10,10,11},S3[]={2,9,17,30,41};
	cout<<findMinofTrip(S1,3,S2,4,S3,5);
	*/
}
