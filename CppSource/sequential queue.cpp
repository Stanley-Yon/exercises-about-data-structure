/**
 * @file sequential queue.cpp
 * @author your name (you@domain.com)
 * @brief 队列的顺序存储        存在假溢出的情况！！！
 * @version 0.1
 * @date 2022-03-23
 * 
 * @copyright Copyright (c) 2022
 * 
 * 详情:
       设立一个队首指针front ，一个队尾指针rear ，分别指向队首和队尾元素。
    ◆ 初始化：front=rear=0。
    ◆ 队列为空：front=rear。
    ◆ 队满：rear=MaxSize。
    ◆ 入队：将新元素插入rear所指的位置，然后rear加1。
    ◆ 出队：删去front所指的元素，然后加1并返回被删元素。
    ◆ 取队首元素：返回fornt指向的元素值
 */

#include<bits/stdc++.h>
using namespace std;
#define MaxSize 50
typedef int Elemtype;
typedef struct
{
    Elemtype data[MaxSize];
    int front,rear;       //首指针和尾指针
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
    cout<<"初始队列是否为空:"<<(queueEmpty(sq)==true?"yes":"no")<<endl;
    for(int i=0;i<10;i++)
        enterQueue(sq,i);
    cout<<"队列头:"<<getHead(sq)<<endl;
    for(int i=0;i<9;i++)
        deleteQueue(sq);
    cout<<"队列头:"<<getHead(sq)<<endl<<endl;

    // cout<<"====================="<<endl<<endl;
    // for(int i=0;i<50;i++)
    //     enterQueue(sq,i);
    // cout<<"队列是否已经满：:"<<(queueFull(sq)==true?"yes":"no")<<endl;


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

bool queueFull(SqQueue &sq)     //假溢出
{
    if(sq.rear==MaxSize)
        return true;
    return false;
}

bool enterQueue(SqQueue &sq,Elemtype &e)
{
    if(queueFull(sq))   //队列已满
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

