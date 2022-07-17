/**
 * @file circular queue.cpp
 * @brief  循环队列(逻辑上像环一样)     与顺序队列相比更能充分地利用空间     
 * @date 2022-03-23
 * 
 */
#include<bits/stdc++.h>
using namespace std;
#define MaxSize 50
typedef int Elemtype;
typedef struct
{
    Elemtype data[MaxSize];
    int front,rear;       //首指针和尾指针
}CQueue;

bool initQueue(CQueue &q);
bool queueEmpty(CQueue &q);
bool queueFull(CQueue &q);
bool enterQueue(CQueue &q,Elemtype &e);
Elemtype deleteQueue(CQueue &q);
Elemtype getHead(CQueue &q);

int main()
{
    CQueue q;
    initQueue(q);
    cout<<"初始队列是否为空:"<<(queueEmpty(q)==true?"yes":"no")<<endl;
    for(int i=0;i<10;i++)
        enterQueue(q,i);
    cout<<"队列头:"<<getHead(q)<<endl;
    for(int i=0;i<9;i++)
        deleteQueue(q);
    cout<<"队列头:"<<getHead(q)<<endl<<endl;

    // cout<<"====================="<<endl<<endl;
    // for(int i=0;i<50;i++)
    //     enterQueue(q,i);
    // cout<<"队列是否已经满：:"<<(queueFull(q)==true?"yes":"no")<<endl;


    system("pause");
    return 0;
}

bool initQueue(CQueue &q)
{
    q.front=q.rear=0;
    return true;
}

bool queueEmpty(CQueue &q)
{
    if(q.front==q.rear)
        return true;
    else    
        return false;
}

bool queueFull(CQueue &q)     //假溢出
{
    if((q.rear+1)%MaxSize==q.front)
        return true;
    return false;
}

bool enterQueue(CQueue &q,Elemtype &e)
{
    if(queueFull(q))   //队列已满
        return false;   
    q.data[q.rear]=e;
    q.rear=(q.rear+1)%MaxSize;
    return true;
}

Elemtype deleteQueue(CQueue &q)
{
    if(queueEmpty(q))
        return false;
    Elemtype e;
    e=q.data[q.front];
    q.front=(q.front+1)%MaxSize;
    return e;
}

Elemtype getHead(CQueue &q)
{
    if(queueEmpty(q))
        return false;
    Elemtype e;
    return q.data[q.front];
}

