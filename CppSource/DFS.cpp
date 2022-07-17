/**
 * @file DFS.cpp
 * @brief  深度优先遍历
 * 
 */
#include<bits/stdc++.h>
#include "common_func.h"
using namespace std;
#define MaxVertexNum 100        //  顶点的最大数目
typedef struct {
    char vex[MaxVertexNum];         //  顶点表
    int edge[MaxVertexNum][MaxVertexNum];      // 邻接矩阵
    int vex_num,arc_num;        //   顶点数 、 弧数
}Graph;
bool visited[MaxVertexNum];      //  标记数组

// 多个连通分量、有向图：防止一次无法访问到所有的顶点
void DFSTraverse(Graph G){      
    for(int i=0; i<G.vex_num ;i++){
        visited[i]=false;
    }
    for(int i=0; i<G.vex_num ;i++){
        if(!visited[i])
            DFS(G,i);
    }
}

// 深度优先遍历图G   ---递归
/**
 * 核心：顶点v的第一个邻接点w1,w1的第一个邻接点w2，w2的第一个邻接点w3,
 *       不断递归访问下去，直到到达最深处，之后返回上个顶点，
 *       继续深度优先访问下去
 *  其用到的就是递归的思想
 */
void DFS(Graph G,int v){
    visit(v);
    visited[v]=true;    // 已访问
    for(int w=firtNeighbor(G,v); w>=0 ;w=nextNeighbor(G,v,w))   
    {   
        if(!visited[w]){    // 未访问
            DFS(G,w);       // 深度优先，则递归调用函数，不断地向深处搜索
        }
    }
}

//  访问顶点v
void visit(int v){} 
// 得到顶点x的第一个邻接点
int firtNeighbor(Graph G,int x){}   
//  顶点y是顶点x的邻接点，返回除y外，x的下一个邻接点
int nextNeighbor(Graph G,int x,int y){}


int main()
{

    system("pause");
    return 0;
}