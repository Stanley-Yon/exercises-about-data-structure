#include<bits/stdc++.h>
using namespace std;
#define LENGTH 4

/**
 * @brief  小区间插入排序，当区间足够小的时候，为了提高效率，
 *          小区间采用插入排序的方法
 */

void swap(int *x,int*y){
    int *temp=x;
    x=y;
    y=temp;
}

void insert_sort(int *arr,int len){
    for(int i=0 ; i<len ; i++){
        int unsorted=i;
        while(unsorted>0){
            if(arr[unsorted] < arr[unsorted-1]){
                swap(arr[unsorted],arr[unsorted-1]);
            }
            else
                break;  //  排好了序
            unsorted--;
        }
    }
}

int partition(int *arr,int low,int high){
    int rand_num=rand()%(high-low+1)+low;
    swap(arr[rand_num],arr[low]);

    int pivot_pos=low;
    while(low<high){
        while (low<high && arr[high] >= arr[pivot_pos]) high--;
        while (low<high && arr[low]  < arr[pivot_pos])  low++;
        swap(arr[low],arr[high]);
    }
    swap(arr[pivot_pos],arr[low]);
    return low;
}
void quick_sort(int *arr,int low,int high){
    if(high-low+1<LENGTH){
        insert_sort(arr,high-low+1);
        return;
    }
    int pivot_pos=partition(arr,low,high);
    quick_sort(arr,low,pivot_pos-1);
    quick_sort(arr,pivot_pos+1,high); 
}

int main()
{
    int array[]={2,1,5,11,24,4,22,55,1,66,33,47,77};
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