/**
 * @file double linked list.cpp
 * @author xuYongLong (xyl008654785@126.com)
 * @brief ˫�����ʵ��
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

//**************�������*******************
void insertDLinklist()
{
    DNode *p,*s;
    s=(DNode*)malloc(sizeof(DNode));
    //���Ĵ���
    s->next=p->next;
    p->next->prior=s;
    s->prior=p;
    p->next=s;

    return;
}

//**************ɾ������*******************
void deleteDLinklist()
{
    DNode *p,*q;
    //���Ĵ���
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