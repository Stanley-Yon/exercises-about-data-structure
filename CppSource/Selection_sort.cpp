/**
 * @file Selection_sort.cpp
 * @brief   选择排序
 * 
 */
#include<bits/stdc++.h>
using namespace std;
void print_arr(int *arr,int n);
void swap(int *x,int *y);

//  选择排序     一次选择将最大、最小挑出
void selection_sort(int *arr,int n){
    int front=0,end=n-1;      //  front记录前面   end记录后面----指向已排好序列的边界
    while(front<end){
        int min=front;
        int max=end;      //  记录最大、最小值的小标
        for (int i = front; i <= end; i++)     // 扫描未排好序列
        {
            if(arr[min]>arr[i])
                min=i;
            if(arr[max]<arr[i])
                max=i;
        }
        swap(arr[min],arr[front]);
        if(max==front)  //  若起初front位置处值最大，但是被换走到了min处
            max=min;
        swap(arr[max],arr[end]);
        front++;
        end--;
    }
}

// 最简单的选择排序（C++）
template<typename T>
void selection_sort_2(T arr[], int len) {
    int i, j, min;
    for (i = 0; i < len - 1; i++) {
        min = i;
        for (j = i + 1; j < len; j++)
            if (arr[min] > arr[j])
                min = j;
        swap(arr[i], arr[min]);
    }
}

int main()
{
    int arr[]={2,1,5,11,24,4,22,55,1,66,33,47,77};
    int n=sizeof(arr)/sizeof(arr[0]);
    // selection_sort(arr,n);
    selection_sort_2(arr,n);
    print_arr(arr,n);
    system("pause");
    return 0;
}

void print_arr(int *arr,int n){ //  数组   长度
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void swap(int *x,int *y){
    int *temp=x;
    x=y;
    y=temp;
}