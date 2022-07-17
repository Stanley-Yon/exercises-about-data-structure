/**
 * @file BST.cpp
 * @brief 
 *          ����������
 * 
 * 1����&���������Ͳ��������ǵ�ַ���ݣ���ʵ�λ������βεĸı���ı�
 *              (  һ��ʹ�õݹ飬��ʹ�÷ǵݹ���ܸı�ԭ��������ֵ   )
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
BSTNode *root;   // ȫ�ֱ��� �������ĸ����

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

    cout<<"==============ɾ�����ڵ�=================="<<endl;
    inorder(root);cout<<endl;
    BST_delete(root,root->data);        
    inorder(root);cout<<endl;
    cout<<"================================"<<endl;


    // cout<<endl<<endl;
    // cout<<"===========���Ҳ���_1==============="<<endl;
    // BSTNode *p1=BST_search_1(root,100);
    // BSTNode *p2=BST_search_1(root,65);
    // if(p1){
    //     cout<<p1->data<<endl;
    // }else if(p2){
    //     cout<<p2->data<<endl;
    // }


    // cout<<endl<<endl;
    // cout<<"===========���Ҳ���_2==============="<<endl;
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
 * @brief ��������������
 * 
 * @param T 
 * @param key �ؼ�������
 * @param n   ����
 * 
 * ���㿪ʼ�������������
 */
void BST_create(BSTree &T,int key[],int n){ 
    int i=0;
    while(i<n)
    {
        BST_insert(T,key[i++]);
    }
}


// ��������������
void BST_insert(BSTree &T , Elemtype key){
    BSTNode *p=(BSTNode *)malloc(sizeof(BSTNode));  // ����ڵ�
    p->data=key;
    p->lchild=p->rchild=NULL;
    if(T==NULL){
        T=p;     // ���ڵ㴴��
        return;
    }
    else if(key == T->data)     // ����ʧ��
        return;
    else if(key < T->data)
        BST_insert(T->lchild,key);
    else
        BST_insert(T->rchild,key);
}

/**
 * ��������������
 *      ���������������ͷָ���ַ   �ؼ���
 */
BSTNode* BST_search_1(BSTree &T,Elemtype key){    // �ݹ�
    if(T==NULL)
        return NULL;

    if(key==T->data)
        return T;
    else if(key < T->data ){      //  С��������
        BST_search_1(T->lchild,key);   
    }   
    else if(key > T->data){    //  ����������
        BST_search_1(T->rchild,key);
    }  
    return NULL;
}

BSTNode* BST_search_2(BSTree T,Elemtype key){    //�ǵݹ�
    while (T!=NULL)
    {
        if(T->data==key)    return T;
        T=(key < T->data) ? T->lchild : T->rchild;
    }
    return NULL;
}


// ����������ɾ��
/**
 * 1������Ҷ�ӽ�㣬ֱ��ɾ��
 * 2�������zֻ��һ����������������������ֱ����z��������Ϊz����������(����ʱ������һ�����������)
 * 3�������z������������������������������С�ĵĽ�������z������ת��Ϊ1��2�����
 *              (���������С�Ľ��Ҫô��Ҷ�ӽ�㣬Ҫôֻ��һ������)
 */
void BST_delete(BSTree T,Elemtype key){
    if(T==NULL) return;
    BSTNode *parent=NULL;     //  ָ���ɾ�����Z�ĸ����
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

    if(T->lchild==NULL && T->rchild==NULL){ // Ҷ�ӽ��
        if(parent->lchild==T)   // �ж�T�Ǹ��������ӻ����Һ���
            parent->lchild=NULL;
        else
            parent->rchild=NULL;
        free(T);
    }
    else if(T->lchild && !T->rchild){  // ֻ��������
        if(parent->lchild==T)   // �ж�T�Ǹ��������ӻ����Һ���
            parent->lchild=T->lchild;
        else
            parent->rchild=T->lchild;
        free(T);
    }
    else if(!T->lchild && T->rchild){  // ֻ��������
        if(parent->lchild==T)
            parent->lchild=T->rchild;
        else
            parent->rchild=T->rchild;
        free(T);
    }
    else{   //  ���Ҷ���
        BSTNode *min=find_min(T->rchild);   // �ҵ�����������С�Ľ��***(һ���������)
        swap(T->data,min->data);       //  ����ֵ
        BST_delete(T->rchild,key);       //  ע�������T��������
    }
}

// �ҵ����м�ֵ��С�Ľ��
BSTNode * find_min(BSTree T){  // ���ڵ�ָ�� 
    if(T==NULL)
        return NULL;
    while (T->lchild)   // ����С
    {
        T=T->lchild;
    }
    return T;
}
// �ҵ����м�ֵ���Ľ��
BSTNode * find_max(BSTree T){
    if(T==NULL)
        return NULL;
    while (T->rchild)   // �Һ��Ӵ�
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