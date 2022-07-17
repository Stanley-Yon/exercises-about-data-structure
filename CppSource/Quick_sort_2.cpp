/**
 * @file quick_sort.cpp
 * @brief 快速排序
 * 
 */
#include<bits/stdc++.h>
using namespace std;

// 交换值
void swap(int *l,int *r){
    int *temp=l;
    l=r;
    r=temp;
}
int partition(int *array,int low,int high){
    int pivot=low;
    while(low<high){
        // 找出不符合大小规范的一对low high     注意 ：右边先走！！！
        while (low<high && array[high]>=array[pivot])   high--;
        while (low<high && array[low]<array[pivot])   low++;

        swap(array[low],array[high]);
    }
    swap(array[pivot],array[low]);
    return low;
}

// 优化_2   随机选择枢轴，避免快排退化
int partition_2(int *array,int low,int high){
    int rand_num=rand()%(high-low+1)+low;
    swap(array[rand_num],array[low]);
    int pivot=low;
    while(low<high){
        // 找出不符合大小规范的一对low high     注意 ：右边先走！！！
        while (low<high && array[high]>=array[pivot])   high--;
        while (low<high && array[low]<array[pivot])   low++;
        swap(array[low],array[high]);
    }
    swap(array[pivot],array[low]);
    return low;
}

void quick_sort(int *array,int low,int high){
    if(low<high){
        // int pivot_pos=partition(array,low,high);
        int pivot_pos=partition_2(array,low,high);
        quick_sort(array,low,pivot_pos-1);
        quick_sort(array,pivot_pos+1,high);
    }
}

int main()
{
    int array[]={2,1,5,11,24,4,22,55,1,66,33,47,77};
    // int array[]={10,1,16,5,17,3,10,20};
    int low=0;
    int high=sizeof(array)/sizeof(array[0])-1;
    quick_sort(array,low,high);

    for (int i = 0; i <= high; i++)
    {
        cout<<array[i]<<" ";
    }
    system("pause");
    return 0;
}