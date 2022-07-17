/**
 * @file Shell_sort.cpp
 * @brief 希尔排序
 * 
 */
#include<bits/stdc++.h>
using namespace std;

// 输出数组
void print_arr(int *arr,int n){ //  数组   长度
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// 希尔排序
void shell_sort(int *arr,int n){
    int i,j,key,inc;
    for(inc = n/2 ; inc>0 ; inc/=2 ){     //   增量 inc ,每一趟之后除以2
        for(i=inc; i<n ; i++){  //  不同子表之间切换进行插入排序
            key=arr[i];     //  暂存当前需要插入的值
            for(j=i ; j>=inc && key<arr[j-inc] ; j-=inc){   
                arr[j]=arr[j-inc];
            }
            arr[j]=key;
        }
        // print_arr(arr,n);
    }
}

//  一次性完成对子序列的插入排序，而不进行切换
void shell_sort_2(int *arr ,int n){
    int inc,i,j;
    for( inc=n/2 ; inc>0 ; inc/=2 ){   //  控制步长
        for( i=0 ; i<inc ; i++ ){     // 对每一个分组进行操作

            for( j=i+inc ; j<n ; j+=inc ){   //  对子数组进行排序
                int tmp=arr[j]; //  待插入元素tmp
                int prev=j-inc;
                while(prev>=0 && arr[prev]>tmp){  //这里是直接插入排序的核心步骤
                    arr[prev+inc]=arr[prev];
                    prev-=inc;
                }
                arr[prev+inc]=tmp;   
            }
        }
    }
}


int main()
{
    int arr[]={2,1,5,11,24,4,22,55,1,66,33,47,77};
    int n=sizeof(arr)/sizeof(arr[0]);
    // shell_sort(arr,n);
    shell_sort_2(arr,n);
    print_arr(arr,n);
    system("pause");
    return 0;
}