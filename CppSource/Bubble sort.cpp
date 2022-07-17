/**
 * @file Bubble sort.cpp
 * @author your name (you@domain.com)
 * @brief ð������
 */
#include<bits/stdc++.h>
using namespace std;
#define maxSize 100

/**
 *   i ���ƱȽϴ���
 *   j ���ƱȽϵ�������
 *   array  ����
 *   n ���鳤��
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
 *  ����Ĵ�����ڵ����⣺���ǰ������Ѿ��������(�����ͨ���Ƚ���Ȼ�������)������bubbleSort���Ǿ���ҵҵ�ıȽ���ȥ��
 *                      ��Ȼ���˷�ʱ��
 * 
 * С�Ż���
 *      ��isSorted������һ�������Ƿ���й�Ԫ�ؽ��������δ���н�������˵������
 *      ������ģ�ֱ��������ѭ����
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
 * ð��������ڵ��������޷�׼ȷֱ����벿�ֵ����������ֻ��ͨ��һ����һ�εıȽ�
 * ���δ�Ԫ�ذ�������ĩβ�����������ֱ�����򲿷ֵı߽磬������ɴ����С�Ƚϵ�
 * ��Χ���ȣ��Ӷ����Ч�ʡ�
 * 
 * ����취��
 *      ��¼����󽻻�Ԫ�ص�λ�ã��������ȷ���������ı߽�
 * 
 */
void bubbleSort_3(int array[],int n){
    int sortBorder=n-1;   // Ĭ���������߽�Ϊ���һ��
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
 * C/C++�����һ����������һ��������Ϊ��������ô���齫�ᱻ�˻�Ϊָ��
        ���ʵ������sizeof(array)/sizeof(array[0])�㳤�ȣ��벻Ҫ��������Ϊ������
        ������main���������length���ٽ����뺯���С�
 */