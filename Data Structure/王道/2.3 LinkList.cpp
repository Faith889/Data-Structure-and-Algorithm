#include<bits/stdc++.h>
using namespace std;


#define ElemType int
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

typedef struct DNode{
	ElemType data;
	struct DNode *prior,*next;
}DNode,*DLinkList;

bool InitList(LinkList &L){
	L=new LNode;
	L->next=NULL;
	return true;
}

int Length(LinkList L){
	int len=0;
	LNode *p=L;
	while(p->next!=NULL){
		p=p->next;
		len++;
	}
	return len;
}

LNode *GetElem(LinkList L,int i){
	LNode *p=L;
	int j=0;
	while(p!=NULL&&j<i){
		p=p->next;
		j++;
	}
	return p;
}

LNode *LocateElem(LinkList L,ElemType e){
	LNode *p=L;
	while(p!=NULL&&p->data!=e){
		p=p->next;
	}
	return p;
}

bool ListInsert(LinkList &L,int i,ElemType e){
	LNode *p=L;
	int j=0;
	while(p!=NULL&&j<i-1){
		p=p->next;
		j++;
	}
	if(p==NULL){
		return false;
	}
	LNode *s=new LNode;
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true;
}

bool ListDelete(LinkList &L,int i,ElemType &e){
	LNode *p=L;
	int j=0;
	while(p->next!=NULL&&j<i-1){//找到被删节点的前驱 
		p=p->next;
		j++;
	}
	if(p==NULL||j>i-1){
		return false;
	}
	LNode *q=p->next;
	e=q->data;
	p->next=q->next;
	free(q);					//释放结点的存储空间 
	return true;
} 

LinkList List_HeadInsert(LinkList &L){
	InitList(L);
	LNode *s;	int x;
	cin>>x;
	while(x!=9999){
		s=new LNode;
		s->data=x;
		s->next=L->next;
		L->next=s;
		cin>>x;
	}
	return L;
}

LinkList List_TailInsert(LinkList &L){
	InitList(L);
	LNode *s,*r=L;	int x;
	cin>>x;
	while(x!=9999){
		s=new LNode;
		s->data=x;
		r->next=s;
		r=s;
		cin>>x;
	}
	r->next=NULL;
	return L;
}

//01
void Del_X_1(LinkList &L,ElemType x){
	LNode *p=L->next,*pre=L,*q;
	while(p!=NULL){
		if(p->data==x){
			q=p;
			p=p->next;
			pre->next=p;
			free(q);
		}else{
			pre=p;
			p=p->next;
		}
	}
}

void Del_X_2(LinkList &L,ElemType x){
	LNode *p=L->next,*r=L,*q;
	while(p!=NULL){
		if(p->data!=x){
			r->next=p;
			r=p;
			p=p->next;
		}else{
			q=p;
			p=p->next;
			free(q);
		}
	}
	r->next=NULL;
}

//02
LinkList Delete_Min(LinkList &L){
	LNode *pre=L,*p=pre->next;
	LNode *minpre=pre,*minp=p;
	while(p!=NULL){
		if(p->data<minp->data){
			minp=p;
			minpre=pre;
		}
		pre=p;
		p=p->next;
	}
	minpre->next=minp->next;
	free(minp);
	return L;
}

//03
LinkList Reverse_1(LinkList L){
	LNode *p,*r;
	p=L->next;
	L->next=NULL;
	while(p!=NULL){
		r=p->next;
		p->next=L->next;
		L->next=p;
		p=r;
	}
	return L;
}

LinkList Reverse_2(LinkList L){
	LNode *pre,*p=L->next,*r=p->next;
	p->next=NULL;
	while(r!=NULL){
		pre=p;
		p=r;
		r=r->next;
		p->next=pre;
	}
	L->next=p;
	return L;
}

//04
void RangeDelete(LinkList &L,int min,int max){
	LNode *p=L->next,*pre=L;
	while(p!=NULL){
		if(p->data>min&&p->data<max){
			pre->next=p->next;
			free(p);
			p=pre->next;
		}else{
			pre=p;
			p=p->next;
		}
	}
}

//06
LinkList DisCreat_2(LinkList &A){
	LinkList B=new LNode;
	B->next=NULL;
	LNode *p=A->next,*q;
	LNode *r=A;
	while(p!=NULL){
		r->next=p;r=p;
		p=p->next;
		if(p!=NULL){
			q=p->next;
			p->next=B->next;
			B->next=p;
			p=q;
		}
	}
	r->next=NULL;
	return B;
}

//07
void Del_Same(LinkList &L){
	LNode *p=L->next,*q;
	if(p==NULL) return;
	while(p->next!=NULL){
		q=p->next;
		if(p->data==q->data){
			p->next=q->next;
			free(q);
		}else{
			p=p->next;
		}
	}
}

//08
void Get_Common(LinkList A,LinkList B){
	LNode *p=A->next,*q=B->next,*r,*s;
	LinkList C=new LNode;
	r=C;
	while(p!=NULL&&q!=NULL){
		if(p->data<q->data) p=p->next;
		else if(p->data>q->data) q=q->next;
		else{
			s=new LNode;
			s->data=p->data;
			r->next=s;
			r=s;
			p=p->next;
			q=q->next;
		}
	}
	r->next=NULL;
}

//09
LinkList Union(LinkList &A,LinkList &B){
	LNode *pa=A->next,*pb=B->next,*pc=A,*u;
	while(pa&&pb){
		if(pa->data==pb->data){
			pc->next=pa;
			pc=pa;
			pa=pa->next;
			u=pb;
			pb=pb->next;
			free(u);
		}else if(pa->data<pb->data){
			u=pa;
			pa=pa->next;
			free(u);
		}else{
			u=pb;
			pb=pb->next;
			free(u);
		}
	}
	while(pa){
		u=pa;
		pa=pa->next;
		free(u);
	}
	while(pb){
		u=pb;
		pb=pb->next;
		free(u);
	}
	pc->next=NULL;
	free(B);
	return A;
}

//10
bool Pattern(LinkList A,LinkList B){
	LNode *p=A,*pr=p,*q=B;
	while(p&&q){
		if(p->data==q->data){
			p=p->next;
			q=q->next;
		}else{
			pr=pr->next;
			p=pr;
			q=B;
		}
	}
	if(q==NULL) return 1;
	else return 0;
}

//11
bool Symmetry(DLinkList L){
	DNode *p=L->next,*q=L->prior;
	while(p!=q&&p->next!=q){
		if(p->data==q->data){
			p=p->next;
			q=q->prior;
		}else return 0;
	}
	return 1;
}

//12
LinkList Link(LinkList &h1,LinkList &h2){
	LNode *p=h1,*q=h2;
	while(p->next!=h1) p=p->next;
	while(q->next!=h2) q=q->next;
	p->next=h2;
	q->next=h1;
	return h1;
}

//13
DLinkList Locate(DLinkList &L,ElemType x){
	DNode *p=L->next,*q;
	while(p&&p->data!=x) p=p->next;
	if(!p) exit(0);
	else{
		p->freq++;
		if(p->pre=L||p->pre->freq>p->pre) return p;
		if(p->next!=NULL) p->next->pre=p->pre;
		p->pre->next=p->next;
		q=p->pre;
		while(q!=L&&q->freq<=p->freq) q=q->pre;
		p->next=q->next;
		if(q->next!=NULL) q->next->pre=p;
		p->pre=q;
		q->next=p;
	}
	return p;
}

//14
LNode *Converse(LNode *L,int k){
	int n=1;
	LNode *p=L;
	while(p->next!=NULL){
		p=p->next;
		n++;
	}
	p->next=L;
	for(int i=0;i<n-k;i++) p=p->next;
	L=p->next;
	p->next=NULL;
	return L; 
}

//15
LNode *FindLoopStart(LNode *head){
	LNode *fast=head,*slow=head;
	while(fast!=NULL&&fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast) break;
	}
	if(fast==NULL||fast->next==NULL) return NULL;
	LNode *p=head,*q=slow;
	while(p!=q){
		p=p->next;
		q=q->next;
	}
	return p;
}

//16
int PairSum(LinkList L){
	LNode *fast=L->next,*slow=L;
	while(fast!=NULL&&fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}
	LNode *h=NULL,*p=slow->next,*t;
	while(p!=NULL){
		t=p->next;
		p->next=h;
		h=p;
		p=t;
	}
	int m=0;
	p=L;
	LNode *q=h;
	while(q!=NULL){
		if(p->data+q->data>m) m=p->data+q->data;
		p=p->next;
		q=q->next;
	}
	return m;
}

//17
typedef int ElemType;
typedef struct Lnode{
	ElemType data;
	struct Lnode *link;
}Lnode,*Linklist;
bool Search_k(Linklist list,int k){
	Lnode *p=list->link,*q=list->link;
	int c=0;
	while(q!=NULL){
		if(c<k) c++;
		else p=p->link;
		q=q->link;
	}
	if(c<k) return 0;
	else{
		cout<<p->data;
		return 1;
	}
}

//18
typedef struct Node{
	char data;
	struct Node *next;
}SNode;
int listlen(SNode *h){
	int l=0;
	while(h->next!=NULL){
		l++;
		h=h->next;
	}
	return l;
}
SNode *find_list(SNode *str1,SNode *str2){
	int m,n;
	SNode *p,*q;
	m=listlen(str1);
	n=listlen(str2);
	for(p=str1;m>n;m--) p=p->next;
	for(q=str2;m<n;n--) q=q->next;
	while(p->next!=NULL&&p->next!=q->next){
		p=p->next;
		q=q->next;
	}
	return p->next;
}

//19
typedef struct node{
	int data;
	struct node *link;
}NODE,*PNODE;
void func(PNODE h,int n){
	PNODE p=h,r;
	int f[n+1]={0};
	while(p->link!=NULL){
		int m=p->link->data>0?p->link->data:-p->link->data;
		if(f[m]==0){
			p=p->link;
			f[m]=1;
		}else{
			r=p->link;
			p->link=r->link;
			free(r);
		}
	}
}

//20
typedef struct node{
	int data;
	struct node *next;
}NODE;
void change_list(NODE *L){
	NODE *p,*q,*r,*s;
	p=q=L;
	while(q->next!=NULL){
		p=p->next;
		q=q->next;
		if(q->next!=NULL) q=q->next;
	}
	q=p->next;
	p->next=NULL;
	while(q!=NULL){
		r=q->next;
		q->next=p->next;
		p->next=q;
		q=r;
	}
	s=L->next;
	q=p->next;
	p->next=NULL;
	while(q!=NULL){
		r=q->next;
		q->next=s->next;
		s->next=q;
		s=q->next;
		q=r;
	}
}
