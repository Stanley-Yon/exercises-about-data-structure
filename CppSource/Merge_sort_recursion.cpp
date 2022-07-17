/**
 * @file Merge_sort.cpp
 * @brief 归并排序   -------递归
 * 
 */
#include<bits/stdc++.h>
#include "common_func.h"
using namespace std;
int arr[]={2,1,5,11,24,4,22,55,1,66,33,47,77};
int n=sizeof(arr)/sizeof(arr[0]);

void merge_sort(int left,int right);
void merge(int left,int mid,int right);

int main()
{
    merge_sort(0,n-1);
    print_arr(arr,n);
    system("pause");
    return 0;
}

/**
 * @brief 先二分，再合并
 * 
 */
void merge_sort(int left,int right){
    if(left>=right)
        return;
    int mid=(left+right)/2;
    merge_sort(left,mid);   //  左半区
    merge_sort(mid+1,right);    //  右半区
    merge(left,mid,right);
}

// 合并操作-----将两个子序列合并
void merge(int left,int mid,int right){
    int tmp[right-left+1];
    int i=left,j=mid+1;     //  分别指向两个子序列的首位元素
    int k=0;    //  指向tmp的空位
    while (i<=mid && j<=right)
    {
        if(arr[i]<=arr[j])
            tmp[k++]=arr[i++];
        else
            tmp[k++]=arr[j++];
    }
    while(i<=mid)
        tmp[k++]=arr[i++];
    while (j<=right)
        tmp[k++]=arr[j++];

    //  数组tmp覆盖到arr的对应位置
    for(i=0;i<k;i++)
        arr[left+i]=tmp[i];
}


