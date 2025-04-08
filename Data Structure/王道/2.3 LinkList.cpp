#include<bits/stdc++.h>
using namespace std;


#define ElemType int
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

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
