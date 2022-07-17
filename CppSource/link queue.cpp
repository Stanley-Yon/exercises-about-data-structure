/**
 * @file link queue.cpp
 * @brief 队列的链式存储(具有头指针和尾指针   ----  链的头指针指向一个头结点)
 * @date 2022-03-23
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef int Elemtype;
typedef struct LinkNode
{
    Elemtype data;
    struct LinkNode *next;
}LinkNode;
typedef struct LinkQueue
{
    LinkNode *front,*rear;
}LinkQueue;

bool initQueue(LinkQueue &q);
bool queueEmpty(LinkQueue &q);
bool enterQueue(LinkQueue &q,Elemtype e);
Elemtype deleteQueue(LinkQueue &q);
Elemtype getHead(LinkQueue &q);
Elemtype getEnd(LinkQueue &q);

int main()
{
    LinkQueue q;
    initQueue(q);
    cout<<"初始循环队列是否为空："<<(queueEmpty(q)==true?"yes":"no")<<endl;
    for(int i=0;i<30;i++)
    {
        enterQueue(q,i);
    }
    cout<<"队列头部："<<getHead(q)<<",队列尾部："<<getEnd(q)<<endl;
    // deleteQueue(q);
    // cout<<"队列头部："<<getHead(q)<<endl;
    // deleteQueue(q);
    // cout<<"队列头部："<<getHead(q)<<endl;


    system("pause");
    return 0;
}

bool initQueue(LinkQueue &q)
{
    LinkNode *pHead=(LinkNode *)malloc(sizeof(LinkNode));
    assert(pHead);      
    q.front=q.rear=pHead;    //建立头结点
    q.front->next=NULL;
    return true;             
}
bool queueEmpty(LinkQueue &q)
{
    if(q.front==q.rear)
        return true;
    return false;
}
bool enterQueue(LinkQueue &q,Elemtype e)
{
    LinkNode *p=(LinkNode *)malloc(sizeof(LinkNode));
    assert(p);
    p->data=e;
    p->next=NULL;
    q.rear->next=p;
    q.rear=p;
    return true;
}
Elemtype deleteQueue(LinkQueue &q)
{
    if(queueEmpty(q))
        return false;
    LinkNode *p=q.front->next;
    Elemtype e=p->data;
    q.front->next=p->next;
    if(q.rear==p)
        q.rear=q.front;      //原队列只有一个元素时，删除就变为空
    free(p);
    return e;
}

Elemtype getHead(LinkQueue &q)
{
    if(queueEmpty(q))
        return false;
    return q.front->next->data;
}

Elemtype getEnd(LinkQueue &q)
{
    if(queueEmpty(q))
        return false;
    return q.rear->data;
}

