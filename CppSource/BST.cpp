/**
 * @file BST.cpp
 * @brief 
 *          二叉排序树
 * 
 * 1、带&的是引用型参数，它是地址传递，其实参会随着形参的改变而改变
 *              (  一般使用递归，若使用非递归可能改变原来变量的值   )
 * 
 */
#include<bits/stdc++.h>
#include "common_func.h"
using namespace std;
#define Elemtype int

typedef struct BSTNode{
    Elemtype data;
    struct BSTNode *lchild,*rchild;
}BSTNode, *BSTree;
BSTNode *root;   // 全局变量 整个树的根结点

void BST_insert(BSTree &T , Elemtype key);
void BST_create(BSTree &T,int key[],int n);
BSTNode* BST_search_1(BSTree &T,Elemtype key);
BSTNode* BST_search_2(BSTree T,Elemtype key);
void BST_delete(BSTree T,Elemtype key);

BSTNode * find_min(BSTree T);
BSTNode * find_max(BSTree T);


void inorder(BSTree &T);

int main()
{
    int key[]={19,13,11,8,50,26,21,30,66,60,70,63,61,65};
    int len=sizeof(key)/sizeof(key[0]);

    cout<<"================================"<<endl;
    BST_create(root,key,len);
    inorder(root);cout<<endl;
    BST_delete(root,50);        
    inorder(root);cout<<endl;

    cout<<"==============删除根节点=================="<<endl;
    inorder(root);cout<<endl;
    BST_delete(root,root->data);        
    inorder(root);cout<<endl;
    cout<<"================================"<<endl;


    // cout<<endl<<endl;
    // cout<<"===========查找测试_1==============="<<endl;
    // BSTNode *p1=BST_search_1(root,100);
    // BSTNode *p2=BST_search_1(root,65);
    // if(p1){
    //     cout<<p1->data<<endl;
    // }else if(p2){
    //     cout<<p2->data<<endl;
    // }


    // cout<<endl<<endl;
    // cout<<"===========查找测试_2==============="<<endl;
    // BSTNode *p3=BST_search_2(root,8);
    // BSTNode *p4=BST_search_2(root,65);
    // if(p3){
    //     cout<<p3->data<<endl;
    // }
    // if(p4){
    //     cout<<p4->data<<endl;
    // }


    system("pause");
    return 0;
}



/**
 * @brief 二叉排序树构造
 * 
 * @param T 
 * @param key 关键字序列
 * @param n   长度
 * 
 * 从零开始插入二叉排序树
 */
void BST_create(BSTree &T,int key[],int n){ 
    int i=0;
    while(i<n)
    {
        BST_insert(T,key[i++]);
    }
}


// 二叉排序树插入
void BST_insert(BSTree &T , Elemtype key){
    BSTNode *p=(BSTNode *)malloc(sizeof(BSTNode));  // 插入节点
    p->data=key;
    p->lchild=p->rchild=NULL;
    if(T==NULL){
        T=p;     // 根节点创建
        return;
    }
    else if(key == T->data)     // 插入失败
        return;
    else if(key < T->data)
        BST_insert(T->lchild,key);
    else
        BST_insert(T->rchild,key);
}

/**
 * 二叉排序树查找
 *      传入参数：二叉树头指针地址   关键字
 */
BSTNode* BST_search_1(BSTree &T,Elemtype key){    // 递归
    if(T==NULL)
        return NULL;

    if(key==T->data)
        return T;
    else if(key < T->data ){      //  小于往左走
        BST_search_1(T->lchild,key);   
    }   
    else if(key > T->data){    //  大于往右走
        BST_search_1(T->rchild,key);
    }  
    return NULL;
}

BSTNode* BST_search_2(BSTree T,Elemtype key){    //非递归
    while (T!=NULL)
    {
        if(T->data==key)    return T;
        T=(key < T->data) ? T->lchild : T->rchild;
    }
    return NULL;
}


// 二叉排序树删除
/**
 * 1、若是叶子结点，直接删除
 * 2、若结点z只有一个左子树或者右子树，则直接让z的子树成为z父结点的子树(构造时决定这一步不会出问题)
 * 3、若结点z有左、右子树，则我们以右子树中最小的的结点代替结点z，接着转化为1、2种情况
 *              (树中最大、最小的结点要么是叶子结点，要么只有一颗子树)
 */
void BST_delete(BSTree T,Elemtype key){
    if(T==NULL) return;
    BSTNode *parent=NULL;     //  指向该删除结点Z的父结点
    while (T)
    {
        if(T->data == key)  break;
        else if(T->data > key){
            parent=T;
            T=T->lchild;    
        }   
        else if(T->data < key){
            parent=T;
            T=T->rchild;
        }           
    }

    if(T->lchild==NULL && T->rchild==NULL){ // 叶子结点
        if(parent->lchild==T)   // 判断T是父结点的左孩子还是右孩子
            parent->lchild=NULL;
        else
            parent->rchild=NULL;
        free(T);
    }
    else if(T->lchild && !T->rchild){  // 只有左子树
        if(parent->lchild==T)   // 判断T是父结点的左孩子还是右孩子
            parent->lchild=T->lchild;
        else
            parent->rchild=T->lchild;
        free(T);
    }
    else if(!T->lchild && T->rchild){  // 只有右子树
        if(parent->lchild==T)
            parent->lchild=T->rchild;
        else
            parent->rchild=T->rchild;
        free(T);
    }
    else{   //  左右都有
        BSTNode *min=find_min(T->rchild);   // 找到右子树中最小的结点***(一定在相对左方)
        swap(T->data,min->data);       //  交换值
        BST_delete(T->rchild,key);       //  注意参数是T的右子树
    }
}

// 找到树中键值最小的结点
BSTNode * find_min(BSTree T){  // 根节点指针 
    if(T==NULL)
        return NULL;
    while (T->lchild)   // 左孩子小
    {
        T=T->lchild;
    }
    return T;
}
// 找到树中键值最大的结点
BSTNode * find_max(BSTree T){
    if(T==NULL)
        return NULL;
    while (T->rchild)   // 右孩子大
    {
        T=T->rchild;
    }
    return T;
}

//=========================================================
void inorder(BSTree &T){
    if(T==NULL) return;

    inorder(T->lchild);
    cout<<T->data<<" ";
    inorder(T->rchild);
}