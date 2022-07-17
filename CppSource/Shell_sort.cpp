/**
 * @file Shell_sort.cpp
 * @brief ϣ������
 * 
 */
#include<bits/stdc++.h>
using namespace std;

// �������
void print_arr(int *arr,int n){ //  ����   ����
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// ϣ������
void shell_sort(int *arr,int n){
    int i,j,key,inc;
    for(inc = n/2 ; inc>0 ; inc/=2 ){     //   ���� inc ,ÿһ��֮�����2
        for(i=inc; i<n ; i++){  //  ��ͬ�ӱ�֮���л����в�������
            key=arr[i];     //  �ݴ浱ǰ��Ҫ�����ֵ
            for(j=i ; j>=inc && key<arr[j-inc] ; j-=inc){   
                arr[j]=arr[j-inc];
            }
            arr[j]=key;
        }
        // print_arr(arr,n);
    }
}

//  һ������ɶ������еĲ������򣬶��������л�
void shell_sort_2(int *arr ,int n){
    int inc,i,j;
    for( inc=n/2 ; inc>0 ; inc/=2 ){   //  ���Ʋ���
        for( i=0 ; i<inc ; i++ ){     // ��ÿһ��������в���

            for( j=i+inc ; j<n ; j+=inc ){   //  ���������������
                int tmp=arr[j]; //  ������Ԫ��tmp
                int prev=j-inc;
                while(prev>=0 && arr[prev]>tmp){  //������ֱ�Ӳ�������ĺ��Ĳ���
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