/**
 * @file link stack.cpp
 * @author your name (you@domain.com)
 * @brief ��ʽջ��ʵ��          ����ͷ���
 * @version 0.1
 * @date 2022-03-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef int ElemType;
#define MaxSize 50
typedef struct LinkNode
{
    ElemType data;
    LinkNode *next;
}LinkNode,*LinkStack;

bool initStack(LinkStack &s);
bool stackEmpty(LinkStack &s);
bool push(LinkStack &s,ElemType &e);
ElemType pop(LinkStack &s);
bool getTop(LinkStack &s,ElemType &e);
bool destroyStack(LinkStack &s);
int getLength(LinkStack &s);

int main()
{
    LinkStack s;
    initStack(s);
    cout<<"��ʼջ�Ƿ�Ϊ��:"<<((stackEmpty(s)==true)?"Yes":"No")<<endl;

    for(int i=0;i<10;i++)
        push(s,i);
    cout<<"�����ջ�ĳ��ȣ�"<<getLength(s)<<endl;
    // for(int i=0;i<10;i++)
    //     pop(s);
    // cout<<"ȫ����ջ��ջ�ĳ��ȣ�"<<getLength(s)<<endl;

    // ElemType e;
    // getTop(s,e);
    // cout<<"ջ��Ԫ�أ�"<<e<<endl;

    // destroyStack(s);
    // cout<<"���ٺ���ջ�ĳ��ȣ�"<<getLength(s)<<endl;

    system("pause");
    return 0;
}

bool initStack(LinkStack &s)
{
    s=NULL;
    return true;
}

bool stackEmpty(LinkStack &s)
{
    if(s==NULL)
        return true;
    return false;
}

//ͷ�巨
bool push(LinkStack &s,ElemType &e)
{
    LinkNode *p=(LinkNode *)malloc(sizeof(LinkNode));
    if(p==NULL)
        return false;   //�ڴ����ʧ��
    p->data=e;
    p->next=s;
    s=p;
    return true;
}

ElemType pop(LinkStack &s)
{
    if(s==NULL)
        return false;
    ElemType e;
    LinkNode *p=s;
    e=s->data;
    s=p->next;
    free(p);
    return e;
}

bool getTop(LinkStack &s,ElemType &e)
{
    if(s==NULL)
        return false;
    e=s->data;
    return true;
}

bool destroyStack(LinkStack &s)
{
    LinkNode *p;
    while(s!=NULL)
    {
        p=s;
        s=p->next;
        free(p);
    }
    return true;
}


int getLength(LinkStack &s)
{
    int length=0;
    LinkNode *p=s;
    while(p)
    {
        length++;
        p=p->next;
    }
    return length;
}