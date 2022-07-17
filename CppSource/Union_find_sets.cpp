/**
 * @file Union_find_sets.cpp
 * @brief 并查集
 *     
 *      具体可查看洛谷题目 P1551
 */
#include<bits/stdc++.h>
#include "common_func.h"
using namespace std;
#define  MAXSIZE 200
int fa[MAXSIZE];    //  结点 i 指向自己的根节点 fa[i]

//  初始化--每个结点开始时指向自己
void initial(int * fa,int n){
    for(int i=0; i<n ;i++)
        fa[i]=i;
}


//  进行了路径压缩
//  找到结点所在集合的根节点(通俗讲就是代表人)
int find(int *fa, int x){
    if(fa[x]==x)
        return x;
    return fa[x]=find(fa,fa[x]);   //  每个结点直接指向代表人，避免逻辑上的树过深
}

int find_comm(int x){   //  未进行路径压缩
    if(fa[x]==x)
        return x;
    else
        return find_comm(fa[x]);
}
int find_inter(int x){  // 非递归
    while(fa[x]!=x)
        x=fa[x];
    return x;
}

//  合并操作---两个集合不相交则合并起来(代表人之间建立联系即可)
void merge(int *fa,int x,int y){
    int fa_x=find(fa,x);
    int fa_y=find(fa,y);
    if(fa_x != fa_y)
        fa[fa_x]=fa_y;
}
