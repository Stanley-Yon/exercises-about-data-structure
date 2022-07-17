/**
 * @file Tree_Forest.cpp
 * @brief 
 *          树和森林
 */
#include<bits/stdc++.h>
#include "common_func.h"
using namespace std;
#define MAX_TREE_SIZE 100
#define Elemtype int

//===========================================================
// 双亲表示法
typedef struct{     // 树的节点定义
    Elemtype data;  //  数据元素
    int parent;     //  双亲位置域
}PTNode;
typedef struct{     //  树
    PTNode nodes[MAX_TREE_SIZE];  
    int n;                         //  节点数
}PTree;

//===========================================================

//===========================================================
//  孩子表示法
typedef struct CNode{
    int child;    //    孩子结点在数组中的位置
    struct CNode *next;    // 下一个孩子
}CNode;
typedef struct CBox{
    Elemtype data;
    CNode *firstchild;  // 第一个孩子
}CBox;
typedef struct CTree{
    CBox nodes[MAX_TREE_SIZE];
    int n;      //  结点数
    int r;      //  根结点位置
}CTree;

//===========================================================

//===========================================================
// 孩子兄弟表示法
typedef struct CSNode{
    Elemtype data;      // 数据域
    struct CSNode *firstchild,*nextsibling;     //  第一个孩子(左孩子)   (当前结点的)右兄弟指针
}CSNode, *CSTree;

//===========================================================

/**
 * 树、森林的遍历具体见typora笔记
 */

int main()
{

    system("pause");
    return 0;
}