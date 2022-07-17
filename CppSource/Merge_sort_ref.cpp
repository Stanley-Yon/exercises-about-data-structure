/**
 * @file Merge_sort_ref.cpp
 * @brief  �ο�
 * 
 */
#include<bits/stdc++.h>
#include "common_func.h"
using namespace std;

void mergesort(int A[], int n){    //�ǵݹ�ʵ�֡�ֻ����һ����С�������������ͬ�Ĵ洢���飬
                                   //���������ֱ���ڸ������Ͻ��в�����������������ʱ����
	int step;   
	int *p, *q, *t;
	int i, j, k, len1, len2;
	int *temp;  
	step = 1;      //��ʼ����Ϊ1����������Ԫ����Ϊ���������н��кϲ�
	p = A;
	q = (int*)malloc(sizeof(int)*n);//qΪ��ʱ���ٵĿռ䣬�����洢���������У���СΪ����������ĳ���
	temp = q;                       //temp��qָ��ͬһ���ڴ棬��������ͷ��ڴ�ռ�ʱʹ�ã�
                                    //��Ϊqָ���ں�����������п��ܻ�ı�ָ��
	while (step<n)
	{
		i = 0;
		j = i + step;
		k = i;                             //k������ʱ������±�
		len1 = i + step < n ? i + step : n;   //len1��ʾ��������1���±�����
		len2 = j + step < n ? j + step : n;   //len2��ʾ��������2���±�����
		while (i<n)
		{
			while (i<len1&&j<len2)        //������������Ԫ�����Ƚϣ�С��ȡ�����븸����
			{
				q[k++] = p[i]<p[j] ? p[i++] : p[j++];
			}
			while (i<len1)                //��������1��ʣ��Ԫ�����븸����
			{
				q[k++] = p[i++];
			}
			while (j<len2)                //��������2��ʣ��Ԫ�����븸����
			{
				q[k++] = p[j++];
			}
			i = j;                        //j����������Ϊlen2��Ȼ��ֵ��i
			j = i + step;                 //i����ֵΪlen2,���ϲ����ٸ�ֵ��j
			k = i;                        
			len1 = i + step < n ? i + step : n;
			len2 = j + step < n ? j + step : n;
		}
		step *= 2;   //��������������ԭ����2������������Ԫ����Ϊ���������н��кϲ�
		t = p;       //t��Ϊ��ʱָ����������ڽ���p��q��ָ��ָ��
		p = q;       //��pָ��ָ�򾭹�һ�ֺϲ���������ʱ����
		q = t;       //��qָ��ָ��ԭ����
	}
	if (A != p){     //�������pָ���ָ��ı�Ϊ��ʱ���飬�������������鿽����ԭ����
		memcpy(A, p, sizeof(int)*n);
	}
	free(temp);
}

// �鲢����C++-�����棩
template<typename T>
void merge_sort(T arr[], int len) {
    T* a = arr;
    T* b = new T[len];
    for (int seg = 1; seg < len; seg += seg) {
        for (int start = 0; start < len; start += seg + seg) {
            int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        T* temp = a;
        a = b;
        b = temp;
    }

    if (a != arr) {
        for (int i = 0; i < len; i++)
            b[i] = a[i];
        b = a;
    }

    delete[] b;
}
    
int main()
{

    system("pause");
    return 0;
}