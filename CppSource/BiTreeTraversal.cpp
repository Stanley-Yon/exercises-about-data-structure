#include<bits/stdc++.h>
using namespace std;
#define ElemType int

// ����������ʽ�洢�ṹ
typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;   
}BiTNode, BiTree;

// ǰ�����
void preOrderTraversal(BiTNode *T){
    if(T==NULL)
        return;
    visit(T);
    preOrderTraversal(T->lchild);
    preOrderTraversal(T->rchild);
}

// �������
void inOrderTraversal(BiTNode *T){
    if(T==NULL)
        return;
    inOrderTraversal(T->lchild);
    visit(T);
    inOrderTraversal(T->rchild);
}

// �������
void postOrderTraversal(BiTNode *T){
    if(T==NULL)
        return;
    postOrderTraversal(T->lchild);
    postOrderTraversal(T->rchild);
    visit(T);
}

// ����ýڵ�����ݣ����ַ���
void visit(BiTNode *node){ 
    cout<<node->data<<" ";
}

// �������
void levelOrder(BiTree *t){
    queue<BiTNode *> q;
    q.push(t);          //  ͷ������
    while (!q.empty())          // ���в�����ѭ��
    {
        BiTNode *p=q.front();    
        q.pop();
        if(p->lchild!=NULL)
            q.push(p->lchild);
        if(p->rchild!=NULL)
            q.push(p->rchild);
    }
}

/**=================================================================== */


/**
 * �ǵݹ��㷨��ʵ��
 */

// ע�⣺�Һ�������ջ�����Ӻ���ջ (ջ�Ǻ���ȳ��ģ�)
void preOrder(BiTree *T){
    if(T==NULL)
        return;
    stack<BiTNode *> s;
    s.push(T);              // ���ڵ���ջ

    while(!s.empty())       // ջ��Ϊ�գ���������
    {
        BiTNode *p=s.top();   
        visit(p);           // ���ʽڵ�
        s.pop();            // ջ���ڵ��ջ

        // �ӽڵ���ջ
        if(p->rchild!=NULL)
            s.push(p->rchild);
        if(p->lchild!=NULL)
            s.push(p->lchild);
    }
}

/**
 * �����������һ���㷨:
 *           �ȱ�����������������ɹ������������ 
 */
void preOrderInter(BiTree *root){
    stack<BiTNode*> s;
    while( root!=NULL || !s.empty())
    {
        if(root!=NULL){
            visit(root);
            s.push(root);
            root=root->lchild;
        }
        else{               // ��ջ������ת���ջ�ڵ��������
            root=s.top();       // ���������׽ڵ� 
            s.pop();
            root=root->rchild;
        }
    }
}

// ���ʸ��ڵ��ʱ�� (����ʱ)
void inOrderInter(BiTree *root){
    stack<BiTNode *> s;
    while ( root!=NULL || !s.empty())
    {
        if(root!=NULL){
            s.push(root);
            root=root->lchild;
        }
        else{
            root=s.top();   // ����
            s.pop();
            visit(root);
            root=root->rchild;
        }
    } 
}

/**
 *  ��ջ��Ϊ���ӣ�
 */
void postOrderInter(BiTree *root){
    stack<BiTNode *> s;
    BiTNode *t=root;
    BiTNode *r=NULL;
    while( t || !s.empty())
    {
        if(t!=NULL){
            s.push(t);
            t=t->lchild;
        }else{
            t=s.top();
            if( t->rchild!=NULL && t->rchild!=r ){// û���Һ��� �� û���߹��Һ���
                t=t->rchild;
                s.push(t);
                t=t->lchild;
            }else{      
                s.pop();
                visit(t);
                r=t;
                t=NULL;
            }
        }
    }  
}


//  ˫ջ����
void postOrderInter2(BiTree *root){
    if(root==NULL)
        return;
    stack<BiTNode *> s1;
    stack<BiTNode *> s2;
    s1.push(root);          //  ���ڵ���ջ
    while(!s1.empty())
    {
        BiTNode *p=s1.top();
        s1.pop();
        s2.push(p);         //  
        if(p->lchild!=NULL)
            s1.push(p->lchild);
        if(p->rchild!=NULL)
            s1.push(p->rchild);
    }

    //  s2��˳��������� ��������Ľ��
    while (!s2.empty())
    {
        cout<<s2.top()->data<<" ";
        s2.pop();
    }  
}

int main()
{
    BiTree *T;

    
    system("pause");
    return 0;
}