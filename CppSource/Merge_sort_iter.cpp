/**
 * @file Merge_sort.cpp
 * @brief �鲢���� -----����
 * 
 */
#include<bits/stdc++.h>
#include "common_func.h"
using namespace std;
int arr[]={2,1,5,11,24,4,22,55,1,66,33,47,77};
int n=sizeof(arr)/sizeof(arr[0]);

void merge_sort(int *arr ,int n){
    int l_start; //   �ϲ����е���
    int seg;   //  ����(�����б�׼����)---1 2 4 8 ��������
    int *tmp=new int[n];    //  �������飬���ڴ�����ź�����

    for( seg=1 ; seg<n; seg*=2 ){
        for(l_start=0 ; l_start<n ; l_start+=seg*2){
            int left=l_start;
            int mid=min(l_start+seg,n-1);
            int right=(l_start+seg*2,n-1);  // ��ֹ����ԭʼ����߽�
            int k=left;     //  ʹ����tmp����
            int i=left,j=mid;
            while(i<=mid-1 && j<=right)    //  ���������� left-(mid-1)  mid-right
                tmp[k++]=arr[i]<=arr[j] ? arr[i++] : arr[j++];

            //  ������ʣ����tmp
            while(i<=mid-1)
                tmp[k++]=arr[i++];
            while (j<=right){
                tmp[k++]=arr[j++];
            }
        }

        //  tmp���ǵ�arr����
        for(int i=0;i<n;i++)
            arr[i]=tmp[i];
    }

}

int main()
{
    merge_sort(arr,n);
    print_arr(arr,n);
    system("pause");
    return 0;
}

