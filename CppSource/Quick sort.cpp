#include<bits/stdc++.h>
using namespace std;

/**
 * �������飬���ҷ���low==high��λ��
 * 
 * 
 * ע�� �����Դ���������Ѱ�ҳ��������С�����������֮�󽻻���������
 *          low��high������Ӧ�Ĳ���
 */
int partition(int array[],int low,int high){
    int pivot=array[low];      // ѡ���׸���Ϊ����
    while (low<high)        //  ��high���ƶ���ʼ�������Ͳ��Ḳ�ǵ�һ����
    {
        while (low<high && array[high]>pivot)
            high--;
        array[low]=array[high];    //  ������С�����ƶ������

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