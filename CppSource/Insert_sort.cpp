/**
 * @file Insert_sort.cpp
 * @brief  ≤Â»Î≈≈–Ú
 * 
 */
#include<bits/stdc++.h>
using namespace std;

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
                break;  //  ≈≈∫√¡À–Ú
            unsorted--;
        }
    }
}
int main()
{
    int arr[]={2,1,5,11,24,4,22,55,1,66,33,47,77};
    int len=sizeof(arr)/sizeof(arr[0]);
    insert_sort(arr,len);
    
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        cout<<arr[i]<<" ";
    }
    system("pause");
    return 0;
}