/**
 * @file Merge_sort_ref.cpp
 * @brief  参考
 * 
 */
#include<bits/stdc++.h>
#include "common_func.h"
using namespace std;

void mergesort(int A[], int n){    //非递归实现。只开辟一个大小与待排序数组相同的存储数组，
                                   //排序过程中直接在该数组上进行操作。不反复开辟临时数组
	int step;   
	int *p, *q, *t;
	int i, j, k, len1, len2;
	int *temp;  
	step = 1;      //初始步长为1，即将单个元素作为有序子序列进行合并
	p = A;
	q = (int*)malloc(sizeof(int)*n);//q为临时开辟的空间，用来存储已排序序列，大小为待排序数组的长度
	temp = q;                       //temp与q指向同一段内存，留作最后释放内存空间时使用，
                                    //因为q指针在后面排序操作中可能会改变指向
	while (step<n)
	{
		i = 0;
		j = i + step;
		k = i;                             //k用作临时数组的下标
		len1 = i + step < n ? i + step : n;   //len1表示有序序列1的下标上限
		len2 = j + step < n ? j + step : n;   //len2表示有序序列2的下标上限
		while (i<n)
		{
			while (i<len1&&j<len2)        //两个子序列首元素做比较，小者取出置入父序列
			{
				q[k++] = p[i]<p[j] ? p[i++] : p[j++];
			}
			while (i<len1)                //将子序列1的剩余元素置入父序列
			{
				q[k++] = p[i++];
			}
			while (j<len2)                //将子序列2的剩余元素置入父序列
			{
				q[k++] = p[j++];
			}
			i = j;                        //j经过自增变为len2，然后赋值给i
			j = i + step;                 //i被赋值为len2,加上步长再赋值给j
			k = i;                        
			len1 = i + step < n ? i + step : n;
			len2 = j + step < n ? j + step : n;
		}
		step *= 2;   //步长翻倍，即将原步长2倍个数的数组元素作为有序子序列进行合并
		t = p;       //t作为临时指针变量，用于交换p和q的指针指向
		p = q;       //将p指针指向经过一轮合并排序后的临时数组
		q = t;       //将q指针指向原数组
	}
	if (A != p){     //如果最终p指针的指向改变为临时数组，则将完成排序的数组拷贝至原数组
		memcpy(A, p, sizeof(int)*n);
	}
	free(temp);
}

// 归并排序（C++-迭代版）
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