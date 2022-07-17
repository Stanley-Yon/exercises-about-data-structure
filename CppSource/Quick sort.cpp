#include<bits/stdc++.h>
using namespace std;

/**
 * 划分数组，并且返回low==high的位置
 * 
 * 
 * 注意 ：可以从左右两端寻找出与枢轴大小不相符的数，之后交换两个数，
 *          low、high作出相应的操作
 */
int partition(int array[],int low,int high){
    int pivot=array[low];      // 选择首个作为枢轴
    while (low<high)        //  从high的移动开始，这样就不会覆盖掉一个数
    {
        while (low<high && array[high]>pivot)
            high--;
        array[low]=array[high];    //  比枢轴小的数移动到左端

        while (low<high && array[low]<=pivot)   
            low++;
        array[high]=array[low];
    }
    array[low]=pivot;
    return low;
}

void quick_sort(int array[],int low,int high){
    if(low<high){
        int pivot_pos=partition(array,low,high);
        quick_sort(array,low,pivot_pos-1);
        quick_sort(array,pivot_pos+1,high);
    }
}

int main()
{
    int array[]={2,1,5,11,24,4,22,55,1,66,33,47,77};
    int low=0;
    int high=sizeof(array)/sizeof(int)-1;
    quick_sort(array,low,high);

    for (int i = 0; i <= high; i++)
    {
        cout<<array[i]<<" ";
    }
    system("pause");
    return 0;
}