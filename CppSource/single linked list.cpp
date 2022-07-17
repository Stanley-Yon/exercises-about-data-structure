#include<bits/stdc++.h>
using namespace std;
typedef int ElemType;

//单链表的定义
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;         //LNode强调结点------LinkList强调链表这个概念

//初始化头结点
void initList(LinkList &L)
{
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
}

int getLength(LinkList &L)
{
    int length=0;
    LinkList s=L;
    while(s->next!=NULL)
    {
        s=s->next;
        length++;
    }
    return length;
}

//**********************带有头结点的单链表的头插法************************
LinkList List_HeadInsert(LinkList &L)
{
    LNode *s;
    int e;
    scanf("%d",&e);
    while(e!=99999)
    {
        s=(LNode*)malloc(sizeof(LNode));
        // s->next=NULL;       
        s->data=e;
        s->next=L->next;
        L->next=s;
        scanf("%d",&e);
    }
    return L;
}

//**************尾插法************************
LinkList List_TailInsert(LinkList &L)
{
    int e;
    LNode *s,*r=L;          //  r指针为尾指针  指向最后一个元素
    while(scanf("%d",&e) != EOF)   
    {
        s=(LNode *)malloc(sizeof(LNode));
        s->data=e;
        r->next=s;
        r=s;
    }
    r->next=NULL;
    return L;
}

//**********按照序号查找结点***************
LNode* getElem(LinkList &L,int index)
{
    int j=1;
    LNode *p=L->next;
    if(index==0)
        return L;           //等于0返回头结点
    if(index<1)
        return NULL;
    while(p && j<index)
    {
        p=p->next;
        j++;
    }
    return p;           //大于表长返回NULL
}

//**********按值查找结点***************
LNode* locateElem(LinkList &L,int v)
{
    LNode *p=L->next;
    while(p!=NULL && p->data!=v)
    {
        p=p->next;
    }
    return p;
}

//***************插入操作(前插)******************
void commonInsert(LinkList &L,int index)    //插入位置
{
    LNode *s=(LNode*)malloc(sizeof(LNode));
    printf("插入新的结点，请输入数据:");
    scanf("%d",&(s->data));
    LNode *p=getElem(L,index-1); //插入位置的前驱结点
    s->next=p->next;
    p->next=s;
    return;
}

//***************删除操作***************
void deleteNode(LinkList &L,int index)
{
    LNode *p,*q;
    p=getElem(L,index-1);
    q=p->next;      //q指向被删除结点
    p->next=q->next;
    free(q);
    return;
}

int main()
{
    LinkList L;
    initList(L);
    cout<<"初始单链表的长度为："<<getLength(L)<<endl;       //得到初始的长度

    // L=List_HeadInsert(L);
    // cout<<"带头结点的单链表的长度为(头插法)："<<getLength(L)<<endl;  
    
    L=List_TailInsert(L);
    cout<<"带头结点的单链表的长度为(尾插法)："<<getLength(L)<<endl;  
    cout<<"================================="<<endl<<endl;

    // LNode *p=getElem(L,2);
    // cout<<"序号为2的结点值："<<p->data<<endl;

    // LNode *p=locateElem(L,5);
    // cout<<"按值查找结点："<<p->data<<endl;


    //******测试插入是否成功***********
    // int index=2;
    // commonInsert(L,index);
    // cout<<"新的单链表的长度："<<getLength(L)<<endl;
    // LNode *p=getElem(L,2);
    // cout<<"序号为2的结点值："<<p->data<<endl;  

    //******测试删除操作是否成功***********
    // int index=2;
    // deleteNode(L,index);
    // LNode *p=getElem(L,index);
    // cout<<"序号为index的结点值："<<p->data<<endl;


    system("pause");
    return 0;
}