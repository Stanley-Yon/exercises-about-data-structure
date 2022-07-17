/**
 * @file Threaded_binary_tree_pre.cpp
 * @brief 
 *          先序线索二叉树
 */

#include<bits/stdc++.h>
#include "common_func.h"
using namespace std;
#define Elemtype int

typedef struct ThreadNode{
    Elemtype data;
    struct ThreadNode *lchild;
    struct ThreadNode *rchild;
    int ltag=0,rtag=0;              //默认指向孩子节点
}ThreadNode, ThreadTree;

ThreadNode *pre=NULL;     // 全局变量--用来保存当前节点的前一个节点

void create_preThread(ThreadTree *T){
    if(T!=NULL){
        preThread(T);

        //  处理最后节点的右指针
        pre->rchild=NULL;
        pre->rtag=1;
    }
}

void preThread(ThreadTree *p){
    if(p==NULL)
        return;
    // visit
    if(p->lchild==NULL){    // p的前驱
        p->lchild=pre;
        p->ltag=1;
    }
    if(pre!=NULL && pre->rchild==NULL){    // pre的后继
        pre->rchild=p;
        p->rtag=1;
    }
    pre=p;

    if(p->ltag=0)   //  防止由于线索化而造成循环访问
        preThread(p->lchild);
    preThread(p->rchild);
}

//=================================================================

//  找先序后继
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

// 先序前驱需要三叉链，一条指针指向其父节点

int main()
{

    system("pause");
    return 0;
}