/**
 * @file Tree_Forest.cpp
 * @brief 
 *          ����ɭ��
 */
#include<bits/stdc++.h>
#include "common_func.h"
using namespace std;
#define MAX_TREE_SIZE 100
#define Elemtype int

//===========================================================
// ˫�ױ�ʾ��
typedef struct{     // ���Ľڵ㶨��
    Elemtype data;  //  ����Ԫ��
    int parent;     //  ˫��λ����
}PTNode;
typedef struct{     //  ��
    PTNode nodes[MAX_TREE_SIZE];  
    int n;                         //  �ڵ���
}PTree;

//===========================================================

//===========================================================
//  ���ӱ�ʾ��
typedef struct CNode{
    int child;    //    ���ӽ���������е�λ��
    struct CNode *next;    // ��һ������
}CNode;
typedef struct CBox{
    Elemtype data;
    CNode *firstchild;  // ��һ������
}CBox;
typedef struct CTree{
    CBox nodes[MAX_TREE_SIZE];
    int n;      //  �����
    int r;      //  �����λ��
}CTree;

//===========================================================

//===========================================================
// �����ֵܱ�ʾ��
typedef struct CSNode{
    Elemtype data;      // ������
    struct CSNode *firstchild,*nextsibling;     //  ��һ������(����)   (��ǰ����)���ֵ�ָ��
}CSNode, *CSTree;

//===========================================================

/**
 * ����ɭ�ֵı��������typora�ʼ�
 */

int main()
{

    system("pause");
    return 0;
}