#include<iostream>
using namespace std;
#define Elemtype int

void print_arr(int *arr,int n){ //  ����   ����
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void swap(Elemtype *x,Elemtype *y){
    Elemtype tmp=*x;
    x=y;
    *y=tmp;
}