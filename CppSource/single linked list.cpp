#include<bits/stdc++.h>
using namespace std;
typedef int ElemType;

//������Ķ���
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;         //LNodeǿ�����------LinkListǿ�������������

//��ʼ��ͷ���
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

//**********************����ͷ���ĵ������ͷ�巨************************
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

//**************β�巨************************
LinkList List_TailInsert(LinkList &L)
{
    int e;
    LNode *s,*r=L;          //  rָ��Ϊβָ��  ָ�����һ��Ԫ��
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

//**********������Ų��ҽ��***************
LNode* getElem(LinkList &L,int index)
{
    int j=1;
    LNode *p=L->next;
    if(index==0)
        return L;           //����0����ͷ���
    if(index<1)
        return NULL;
    while(p && j<index)
    {
        p=p->next;
        j++;
    }
    return p;           //���ڱ�����NULL
}

//**********��ֵ���ҽ��***************
LNode* locateElem(LinkList &L,int v)
{
    LNode *p=L->next;
    while(p!=NULL && p->data!=v)
    {
        p=p->next;
    }
    return p;
}

//***************�������(ǰ��)******************
void commonInsert(LinkList &L,int index)    //����λ��
{
    LNode *s=(LNode*)malloc(sizeof(LNode));
    printf("�����µĽ�㣬����������:");
    scanf("%d",&(s->data));
    LNode *p=getElem(L,index-1); //����λ�õ�ǰ�����
    s->next=p->next;
    p->next=s;
    return;
}

//***************ɾ������***************
void deleteNode(LinkList &L,int index)
{
    LNode *p,*q;
    p=getElem(L,index-1);
    q=p->next;      //qָ��ɾ�����
    p->next=q->next;
    free(q);
    return;
}

int main()
{
    LinkList L;
    initList(L);
    cout<<"��ʼ������ĳ���Ϊ��"<<getLength(L)<<endl;       //�õ���ʼ�ĳ���

    // L=List_HeadInsert(L);
    // cout<<"��ͷ���ĵ�����ĳ���Ϊ(ͷ�巨)��"<<getLength(L)<<endl;  
    
    L=List_TailInsert(L);
    cout<<"��ͷ���ĵ�����ĳ���Ϊ(β�巨)��"<<getLength(L)<<endl;  
    cout<<"================================="<<endl<<endl;

    // LNode *p=getElem(L,2);
    // cout<<"���Ϊ2�Ľ��ֵ��"<<p->data<<endl;

    // LNode *p=locateElem(L,5);
    // cout<<"��ֵ���ҽ�㣺"<<p->data<<endl;


    //******���Բ����Ƿ�ɹ�***********
    // int index=2;
    // commonInsert(L,index);
    // cout<<"�µĵ�����ĳ��ȣ�"<<getLength(L)<<endl;
    // LNode *p=getElem(L,2);
    // cout<<"���Ϊ2�Ľ��ֵ��"<<p->data<<endl;  

    //******����ɾ�������Ƿ�ɹ�***********
    // int index=2;
    // deleteNode(L,index);
    // LNode *p=getElem(L,index);
    // cout<<"���Ϊindex�Ľ��ֵ��"<<p->data<<endl;


    system("pause");
    return 0;
}