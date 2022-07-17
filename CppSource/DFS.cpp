/**
 * @file DFS.cpp
 * @brief  ������ȱ���
 * 
 */
#include<bits/stdc++.h>
#include "common_func.h"
using namespace std;
#define MaxVertexNum 100        //  ����������Ŀ
typedef struct {
    char vex[MaxVertexNum];         //  �����
    int edge[MaxVertexNum][MaxVertexNum];      // �ڽӾ���
    int vex_num,arc_num;        //   ������ �� ����
}Graph;
bool visited[MaxVertexNum];      //  �������

// �����ͨ����������ͼ����ֹһ���޷����ʵ����еĶ���
void DFSTraverse(Graph G){      
    for(int i=0; i<G.vex_num ;i++){
        visited[i]=false;
    }
    for(int i=0; i<G.vex_num ;i++){
        if(!visited[i])
            DFS(G,i);
    }
}

// ������ȱ���ͼG   ---�ݹ�
/**
 * ���ģ�����v�ĵ�һ���ڽӵ�w1,w1�ĵ�һ���ڽӵ�w2��w2�ĵ�һ���ڽӵ�w3,
 *       ���ϵݹ������ȥ��ֱ�����������֮�󷵻��ϸ����㣬
 *       ����������ȷ�����ȥ
 *  ���õ��ľ��ǵݹ��˼��
 */
void DFS(Graph G,int v){
    visit(v);
    visited[v]=true;    // �ѷ���
    for(int w=firtNeighbor(G,v); w>=0 ;w=nextNeighbor(G,v,w))   
    {   
        if(!visited[w]){    // δ����
            DFS(G,w);       // ������ȣ���ݹ���ú��������ϵ��������
        }
    }
}

//  ���ʶ���v
void visit(int v){} 
// �õ�����x�ĵ�һ���ڽӵ�
int firtNeighbor(Graph G,int x){}   
//  ����y�Ƕ���x���ڽӵ㣬���س�y�⣬x����һ���ڽӵ�
int nextNeighbor(Graph G,int x,int y){}


int main()
{

    system("pause");
    return 0;
}