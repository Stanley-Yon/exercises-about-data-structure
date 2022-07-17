/**
 * @file sequential queue.cpp
 * @author your name (you@domain.com)
 * @brief ���е�˳��洢        ���ڼ���������������
 * @version 0.1
 * @date 2022-03-23
 * 
 * @copyright Copyright (c) 2022
 * 
 * ����:
       ����һ������ָ��front ��һ����βָ��rear ���ֱ�ָ����׺Ͷ�βԪ�ء�
    �� ��ʼ����front=rear=0��
    �� ����Ϊ�գ�front=rear��
    �� ������rear=MaxSize��
    �� ��ӣ�����Ԫ�ز���rear��ָ��λ�ã�Ȼ��rear��1��
    �� ���ӣ�ɾȥfront��ָ��Ԫ�أ�Ȼ���1�����ر�ɾԪ�ء�
    �� ȡ����Ԫ�أ�����forntָ���Ԫ��ֵ
 */

#include<bits/stdc++.h>
using namespace std;
#define MaxSize 50
typedef int Elemtype;
typedef struct
{
    Elemtype data[MaxSize];
    int front,rear;       //��ָ���βָ��
}SqQueue;

bool initQueue(SqQueue &sq);
bool queueEmpty(SqQueue &sq);
bool queueFull(SqQueue &sq);
bool enterQueue(SqQueue &sq,Elemtype &e);
Elemtype deleteQueue(SqQueue &sq);
Elemtype getHead(SqQueue &sq);

int main()
{
    SqQueue sq;
    initQueue(sq);
    cout<<"��ʼ�����Ƿ�Ϊ��:"<<(queueEmpty(sq)==true?"yes":"no")<<endl;
    for(int i=0;i<10;i++)
        enterQueue(sq,i);
    cout<<"����ͷ:"<<getHead(sq)<<endl;
    for(int i=0;i<9;i++)
        deleteQueue(sq);
    cout<<"����ͷ:"<<getHead(sq)<<endl<<endl;

    // cout<<"====================="<<endl<<endl;
    // for(int i=0;i<50;i++)
    //     enterQueue(sq,i);
    // cout<<"�����Ƿ��Ѿ�����:"<<(queueFull(sq)==true?"yes":"no")<<endl;


    system("pause");
    return 0;
}

bool initQueue(SqQueue &sq)
{
    sq.front=sq.rear=0;
    return true;
}

bool queueEmpty(SqQueue &sq)
{
    if(sq.front==0 && sq.rear==0)
        return true;
    return false;
}

bool queueFull(SqQueue &sq)     //�����
{
    if(sq.rear==MaxSize)
        return true;
    return false;
}

bool enterQueue(SqQueue &sq,Elemtype &e)
{
    if(queueFull(sq))   //��������
        return false;   
    sq.data[sq.rear++]=e;
    return true;
}

Elemtype deleteQueue(SqQueue &sq)
{
    if(queueEmpty(sq))
        return false;
    Elemtype e;
    e=sq.data[sq.front++];
    return e;
}

Elemtype getHead(SqQueue &sq)
{
    if(queueEmpty(sq))
        return false;
    Elemtype e;
    return sq.data[sq.front];
}

