/**
 * @file BFS.cpp
 * @brief �����������
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
queue<char> q;          //  �������� 

/**
 * 1�������ͨ������Ҫ��ε���BFS
 * 2������ͼ��ʱ���һ�������޷��������еĶ��㣬��Ҫ��ʣ��Ķ������������ȥ         
 */
void BFSTraverse(Graph G){      
    for(int i=0; i<MaxVertexNum; i++)
        visited[i]=false;
    for(int i=0; i<G.vex_num; i++){         //  ��0�Ŷ��㿪ʼ����     
        if(!visited[i])      
            BFS(G,i);                   //   ����ÿһ����ͨ����
    }
}

/**
 * ����˼�룺
 *     ʹ��һ���������м�¼����ǰ���ʵĶ���v�����ڽӵ㣬(�������)
 * �ȵ�v���ʽ����������ڽӵ�ȫ����ӣ���Զ���Q��Ԫ��һ�ν�����������(��ʱ����Ԫ�ص�
 * �����ڽӵ㶼�ڶ���ĩβ�������---���е�����)
 */
void BFS(Graph G,int v){
    visit(v);
    q.push(v);      //  ����v���븨������
    visited[v]=true;
    while(!q.empty()){
        q.pop();    //  ����v����
        for(int w=firtNeighbor(G,v); w>=0 ; w=nextNeighbor(G,v,w)){     //  ����v���е��ڽӵ�
            if(!visited[w]){    //  wδ����
                visit(w);
                visited[w]=true;
                q.push(w);           
            }
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