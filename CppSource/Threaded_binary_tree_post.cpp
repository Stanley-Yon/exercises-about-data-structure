/**
 * @file Threaded_binary_tree_post.cpp
 * @brief 
 *          后序线索二叉树
 */

#include<bits/stdc++.h>
#include "common_func.h"
using namespace std;
#define Elemtype int

typedef struct ThreadNode{
    Elemtype data;
    struct ThreadNode *lchild;
    struct ThreadNode *rchild;
    int ltag=0,rtag=0;      
}ThreadNode, ThreadTree;

ThreadNode *pre=NULL;

void create_postThread(ThreadTree *T){
    if(T==NULL)
        return;
    
    postThread(T);
    pre->rchild=NULL;
    pre->rtag=1;
}

void postThread(ThreadNode *q){
    if(q==NULL)
        return;
    postThread(q->lchild);
    postThread(q->rchild);

    if(q->lchild==NULL){
        q->lchild=pre;
        q->ltag=1;
    }
    if(pre!=NULL && pre->rchild==NULL){
        pre->rchild=q;
        pre->rtag=1;
    }
    pre=q;
}

//============================================================

//  找后序前驱
ThreadNode* pre_node(ThreadNode *p){
    if(p==NULL)
        return;
    if(p->ltag=1)
        return p->lchild;
    else{
        if(p->rchild!=NULL)
            return p->rchild;
        else
            return p->lchild;
    }
}

// 找后序后继-----土办法：后序遍历 ； 利用三叉链表

int main()
{

    system("pause");
    return 0;
}