/**
 * @file BFS.cpp
 * @brief 广度优先搜索
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
queue<char> q;          //  辅助队列 

/**
 * 1、多个连通分量需要多次调用BFS
 * 2、有向图有时候从一个顶点无法到达所有的顶点，需要从剩余的顶点继续搜索下去         
 */
void BFSTraverse(Graph G){      
    for(int i=0; i<MaxVertexNum; i++)
        visited[i]=false;
    for(int i=0; i<G.vex_num; i++){         //  从0号顶点开始遍历     
        if(!visited[i])      
            BFS(G,i);                   //   处理每一个连通分量
    }
}

/**
 * 核心思想：
 *     使用一个辅助队列记录将当前访问的顶点v所有邻接点，(广度优先)
 * 等到v访问结束，并且邻接点全部入队，则对队列Q中元素一次进行上述操作(此时访问元素的
 * 所有邻接点都在队列末尾依次添加---队列的性质)
 */
void BFS(Graph G,int v){
    visit(v);
    q.push(v);      //  顶点v进入辅助队列
    visited[v]=true;
    while(!q.empty()){
        q.pop();    //  顶点v出队
        for(int w=firtNeighbor(G,v); w>=0 ; w=nextNeighbor(G,v,w)){     //  访问v所有的邻接点
            if(!visited[w]){    //  w未访问
                visit(w);
                visited[w]=true;
                q.push(w);           
            }
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