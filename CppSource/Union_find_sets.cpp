/**
 * @file Union_find_sets.cpp
 * @brief ���鼯
 *     
 *      ����ɲ鿴�����Ŀ P1551
 */
#include<bits/stdc++.h>
#include "common_func.h"
using namespace std;
#define  MAXSIZE 200
int fa[MAXSIZE];    //  ��� i ָ���Լ��ĸ��ڵ� fa[i]

//  ��ʼ��--ÿ����㿪ʼʱָ���Լ�
void initial(int * fa,int n){
    for(int i=0; i<n ;i++)
        fa[i]=i;
}


//  ������·��ѹ��
//  �ҵ�������ڼ��ϵĸ��ڵ�(ͨ�׽����Ǵ�����)
int find(int *fa, int x){
    if(fa[x]==x)
        return x;
    return fa[x]=find(fa,fa[x]);   //  ÿ�����ֱ��ָ������ˣ������߼��ϵ�������
}

int find_comm(int x){   //  δ����·��ѹ��
    if(fa[x]==x)
        return x;
    else
        return find_comm(fa[x]);
}
int find_inter(int x){  // �ǵݹ�
    while(fa[x]!=x)
        x=fa[x];
    return x;
}

//  �ϲ�����---�������ϲ��ཻ��ϲ�����(������֮�佨����ϵ����)
void merge(int *fa,int x,int y){
    int fa_x=find(fa,x);
    int fa_y=find(fa,y);
    if(fa_x != fa_y)
        fa[fa_x]=fa_y;
}
