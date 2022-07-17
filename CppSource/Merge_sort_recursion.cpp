/**
 * @file Merge_sort.cpp
 * @brief �鲢����   -------�ݹ�
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
 * @brief �ȶ��֣��ٺϲ�
 * 
 */
void merge_sort(int left,int right){
    if(left>=right)
        return;
    int mid=(left+right)/2;
    merge_sort(left,mid);   //  �����
    merge_sort(mid+1,right);    //  �Ұ���
    merge(left,mid,right);
}

// �ϲ�����-----�����������кϲ�
void merge(int left,int mid,int right){
    int tmp[right-left+1];
    int i=left,j=mid+1;     //  �ֱ�ָ�����������е���λԪ��
    int k=0;    //  ָ��tmp�Ŀ�λ
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

    //  ����tmp���ǵ�arr�Ķ�Ӧλ��
    for(i=0;i<k;i++)
        arr[left+i]=tmp[i];
}


