/**
 * @file Threaded_binary_tree_pre.cpp
 * @brief 
 *          ��������������
 */

#include<bits/stdc++.h>
#include "common_func.h"
using namespace std;
#define Elemtype int

typedef struct ThreadNode{
    Elemtype data;
    struct ThreadNode *lchild;
    struct ThreadNode *rchild;
    int ltag=0,rtag=0;              //Ĭ��ָ���ӽڵ�
}ThreadNode, ThreadTree;

ThreadNode *pre=NULL;     // ȫ�ֱ���--�������浱ǰ�ڵ��ǰһ���ڵ�

void create_preThread(ThreadTree *T){
    if(T!=NULL){
        preThread(T);

        //  �������ڵ����ָ��
        pre->rchild=NULL;
        pre->rtag=1;
    }
}

void preThread(ThreadTree *p){
    if(p==NULL)
        return;
    // visit
    if(p->lchild==NULL){    // p��ǰ��
        p->lchild=pre;
        p->ltag=1;
    }
    if(pre!=NULL && pre->rchild==NULL){    // pre�ĺ��
        pre->rchild=p;
        p->rtag=1;
    }
    pre=p;

    if(p->ltag=0)   //  ��ֹ���������������ѭ������
        preThread(p->lchild);
    preThread(p->rchild);
}

//=================================================================

//  ��������
ThreadNode* next_node(ThreadNode *p){
    if(p==NULL)
        return;
    if(p->rtag=1)
        return p->rchild;
    else{
        if(p->lchild!=NULL)
            return p->lchild;
        else
            return p->rchild;
    }
}

// ����ǰ����Ҫ��������һ��ָ��ָ���丸�ڵ�

int main()
{

    system("pause");
    return 0;
}