/**
 * @file Threaded_binary_tree_in.cpp
 * @brief 
 *          中序线索二叉树
 */
#include<bits/stdc++.h>
using namespace std;
#define ElemType int

typedef struct ThreadNode{
    ElemType data;
    ThreadNode *lchild,*rchild;
    int ltag=0,rtag=0;      //  0表示指向孩子(默认)，1表示前驱或后继
}ThreadNode, *ThreadTree;

ThreadNode *pre=NULL;   //  指向当前节点的前驱

//  建立中序线索二叉树
void createInThread(ThreadTree T){
    if(T!=NULL){
        inThread(T);
        if(pre!=NULL){  // 最后一个节点的后继为null
            pre->rchild=NULL;
            pre->rtag=1;
        }
    }
}

//  中序遍历二叉树，一边遍历、一边线索化
void inThread(ThreadTree T){
    if(T!=NULL){
        inThread(T->lchild);    //  访问左子树
        visit(T);               //  访问根节点，建立线索
        inThread(T->rchild);    //  访问右子树
    }
}

void visit(ThreadNode *p){  // 注意建立的节点指针
    if(p->lchild==NULL){    //  前驱线索 -- p
        p->lchild=pre;
        p->ltag=1;
    }
    if(pre!=NULL && pre->rchild==NULL){   //  后继线索 --pre
        pre->rchild=p;
        pre->rtag=1;
    }
    pre=p;
}

//============================================================

//  找到以p为根，最后一个被访问的节点
ThreadNode* find_last_node(ThreadNode *p){
    while(p->rtag=0){   //树的最右下角节点
        p=p->rchild;
    }
    return p;
}

ThreadNode* pre_node(ThreadNode *p){
    if(p->ltag=1)
        return p->lchild;
    else  //  左子树的最右下角
        return find_last_node(p->lchild);
}

//  通过线索二叉树进行中序逆遍历
void rev_inorder(ThreadTree T){ // 传入根节点
    for(ThreadNode* p=find_last_node(T);p!=NULL;p=pre_node(p)){
        /**
         * 具体访问p节点
         */
    }
}

//=================================================================

// 找到以p为根的树中，最先被访问的节点
ThreadNode* first_node(ThreadNode *p){
    while (p->ltag=0)
        p=p->lchild;
    return p;
}

//  找中序后继
ThreadNode* next_node(ThreadNode *p){
    if(p->rtag=1) //  右指针为线索，即指向直接后继
        return  p->rchild;
    else
        return first_node(p->rchild);
}

// 在中序线索树中进行中序遍历
void inorder(ThreadTree T){
    //  先找到整个树的左下方，即第一个遍历的节点
    for(ThreadNode *p=first_node(T); p!=NULL ; p=next_node(p)){   
        /**
         * 具体该节点
         */
    }
}

int main()
{

    system("pause");
    return 0;
}