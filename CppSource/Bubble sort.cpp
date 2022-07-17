/**
 * @file Bubble sort.cpp
 * @author your name (you@domain.com)
 * @brief 冒泡排序
 */
#include<bits/stdc++.h>
using namespace std;
#define maxSize 100

/**
 *   i 控制比较次数
 *   j 控制比较的两个数
 *   array  数组
 *   n 数组长度
 */
void bubbleSort(int array[],int n)
{  
    for(int i=0;i<n-1;i++){ 
        for(int j=0;j<n-i-1;j++){   
            if(array[j]>array[j+1]){
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
}

/**
 *  上面的代码存在的问题：如果前面的数已经是有序的(后面的通过比较自然是有序的)，可是bubbleSort还是兢兢业业的比较下去，
 *                      显然是浪费时间
 * 
 * 小优化：
 *      用isSorted代表这一轮排序是否进行过元素交换，如果未进行交换，则说明数组
 *      是有序的，直接跳出大循环。
 */
void bubbleSort_2(int array[],int n){
    for(int i=0;i<n-1;i++){ 
        bool isSorted=true;
        for(int j=0;j<n-i-1;j++){   
            if(array[j]>array[j+1]){
                isSorted=false;
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
        if(isSorted)
            break;
    }
}

/**
 * 冒泡排序存在的问题是无法准确直到后半部分的有序情况，只能通过一次又一次的比较
 * 将次大元素挨个放在末尾。但是如果能直到无序部分的边界，这样便可大大缩小比较的
 * 范围长度，从而提高效率。
 * 
 * 解决办法：
 *      记录下最后交换元素的位置，这个可以确定无序区的边界
 * 
 */
void bubbleSort_3(int array[],int n){
    int sortBorder=n-1;   // 默认无序区边界为最后一个
    int border=0;
    for(int i=0;i<n-1;i++){
        bool isSorted=true;
        for(int j=0;j<sortBorder;j++){
            if(array[j]>array[j+1]){
                isSorted=false;
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
                border=j;
            }
        }
        sortBorder=border;
        if(isSorted)
            break;
    }
}

int main()
{
    // int array[]={2,1,5,11,24,4,22,55,1,66,33,47,35};
    int array[]={2,1,5,11,24,4,22,55,1,66,33,47,77};
    int length=sizeof(array)/sizeof(array[0]);
    // bubbleSort(array,length);
    // bubbleSort_2(array,length);
    bubbleSort_3(array,length);


    for (int i = 0; i < length; i++)
    {
        cout<<array[i]<<" ";
    }
    system("pause");
    return 0;
}
/**
 * C/C++中如果一个函数接受一个数组作为参数，那么数组将会被退化为指针
        如果实在想用sizeof(array)/sizeof(array[0])算长度，请不要将数组作为参数，
        而是在main函数中算好length，再将传入函数中。
 */