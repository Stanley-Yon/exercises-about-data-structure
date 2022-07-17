/**
 * @file double linked list.cpp
 * @author xuYongLong (xyl008654785@126.com)
 * @brief 双链表的实现
 * @version 0.1
 * @date 2022-03-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef int ElemType;

typedef struct DNode{
    ElemType data;
    DNode *prior,*next;
}DNode,*DLinklist;

//**************插入操作*******************
void insertDLinklist()
{
    DNode *p,*s;
    s=(DNode*)malloc(sizeof(DNode));
    //核心代码
    s->next=p->next;
    p->next->prior=s;
    s->prior=p;
    p->next=s;

    return;
}

//**************删除操作*******************
void deleteDLinklist()
{
    DNode *p,*q;
    //核心代码
    p->next=q->next;
    q->next->prior=p;
    free(q);

    return;
}



int main()
{

    system("pause");
    return 0;
}