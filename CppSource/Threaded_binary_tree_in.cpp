/**
 * @file Threaded_binary_tree_in.cpp
 * @brief 
 *          ��������������
 */
#include<bits/stdc++.h>
using namespace std;
#define ElemType int

typedef struct ThreadNode{
    ElemType data;
    ThreadNode *lchild,*rchild;
    int ltag=0,rtag=0;      //  0��ʾָ����(Ĭ��)��1��ʾǰ������
}ThreadNode, *ThreadTree;

ThreadNode *pre=NULL;   //  ָ��ǰ�ڵ��ǰ��

//  ������������������
void createInThread(ThreadTree T){
    if(T!=NULL){
        inThread(T);
        if(pre!=NULL){  // ���һ���ڵ�ĺ��Ϊnull
            pre->rchild=NULL;
            pre->rtag=1;
        }
    }
}

//  ���������������һ�߱�����һ��������
void inThread(ThreadTree T){
    if(T!=NULL){
        inThread(T->lchild);    //  ����������
        visit(T);               //  ���ʸ��ڵ㣬��������
        inThread(T->rchild);    //  ����������
    }
}

void visit(ThreadNode *p){  // ע�⽨���Ľڵ�ָ��
    if(p->lchild==NULL){    //  ǰ������ -- p
        p->lchild=pre;
        p->ltag=1;
    }
    if(pre!=NULL && pre->rchild==NULL){   //  ������� --pre
        pre->rchild=p;
        pre->rtag=1;
    }
    pre=p;
}

//============================================================

//  �ҵ���pΪ�������һ�������ʵĽڵ�
ThreadNode* find_last_node(ThreadNode *p){
    while(p->rtag=0){   //���������½ǽڵ�
        p=p->rchild;
    }
    return p;
}

ThreadNode* pre_node(ThreadNode *p){
    if(p->ltag=1)
        return p->lchild;
    else  //  �������������½�
        return find_last_node(p->lchild);
}

//  ͨ�������������������������
void rev_inorder(ThreadTree T){ // ������ڵ�
    for(ThreadNode* p=find_last_node(T);p!=NULL;p=pre_node(p)){
        /**
         * �������p�ڵ�
         */
    }
}

//=================================================================

// �ҵ���pΪ�������У����ȱ����ʵĽڵ�
ThreadNode* first_node(ThreadNode *p){
    while (p->ltag=0)
        p=p->lchild;
    return p;
}

//  ��������
ThreadNode* next_node(ThreadNode *p){
    if(p->rtag=1) //  ��ָ��Ϊ��������ָ��ֱ�Ӻ��
        return  p->rchild;
    else
        return first_node(p->rchild);
}

// �������������н����������
void inorder(ThreadTree T){
    //  ���ҵ������������·�������һ�������Ľڵ�
    for(ThreadNode *p=first_node(T); p!=NULL ; p=next_node(p)){   
        /**
         * ����ýڵ�
         */
    }
}

int main()
{

    system("pause");
    return 0;
}