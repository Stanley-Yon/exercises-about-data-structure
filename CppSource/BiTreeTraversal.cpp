#include<bits/stdc++.h>
using namespace std;
#define ElemType int

// 二叉树的链式存储结构
typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;   
}BiTNode, BiTree;

// 前序遍历
void preOrderTraversal(BiTNode *T){
    if(T==NULL)
        return;
    visit(T);
    preOrderTraversal(T->lchild);
    preOrderTraversal(T->rchild);
}

// 中序遍历
void inOrderTraversal(BiTNode *T){
    if(T==NULL)
        return;
    inOrderTraversal(T->lchild);
    visit(T);
    inOrderTraversal(T->rchild);
}

// 后序遍历
void postOrderTraversal(BiTNode *T){
    if(T==NULL)
        return;
    postOrderTraversal(T->lchild);
    postOrderTraversal(T->rchild);
    visit(T);
}

// 输出该节点的数据，如字符等
void visit(BiTNode *node){ 
    cout<<node->data<<" ";
}

// 层序遍历
void levelOrder(BiTree *t){
    queue<BiTNode *> q;
    q.push(t);          //  头结点入队
    while (!q.empty())          // 队列不空则循环
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
 * 非递归算法的实现
 */

// 注意：右孩子先入栈，左孩子后入栈 (栈是后进先出的！)
void preOrder(BiTree *T){
    if(T==NULL)
        return;
    stack<BiTNode *> s;
    s.push(T);              // 根节点入栈

    while(!s.empty())       // 栈不为空，继续遍历
    {
        BiTNode *p=s.top();   
        visit(p);           // 访问节点
        s.pop();            // 栈顶节点出栈

        // 子节点入栈
        if(p->rchild!=NULL)
            s.push(p->rchild);
        if(p->lchild!=NULL)
            s.push(p->lchild);
    }
}

/**
 * 先序遍历的另一种算法:
 *           先遍历左子树，遍历完成过后回溯右子树 
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
        else{               // 出栈，并且转向出栈节点的右子树
            root=s.top();       // 回溯至父亲节点 
            s.pop();
            root=root->rchild;
        }
    }
}

// 访问根节点的时机 (回溯时)
void inOrderInter(BiTree *root){
    stack<BiTNode *> s;
    while ( root!=NULL || !s.empty())
    {
        if(root!=NULL){
            s.push(root);
            root=root->lchild;
        }
        else{
            root=s.top();   // 回溯
            s.pop();
            visit(root);
            root=root->rchild;
        }
    } 
}

/**
 *  单栈较为复杂！
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
            if( t->rchild!=NULL && t->rchild!=r ){// 没有右孩子 和 没有走过右孩子
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


//  双栈操作
void postOrderInter2(BiTree *root){
    if(root==NULL)
        return;
    stack<BiTNode *> s1;
    stack<BiTNode *> s2;
    s1.push(root);          //  根节点入栈
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

    //  s2的顺序输出就是 后序遍历的结果
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