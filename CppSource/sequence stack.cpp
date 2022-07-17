/**
 * @file stack.cpp
 * @author xuYongLong (xyl008654785@126.com)
 * @brief ջ��˳��洢
 * @version 0.1
 * @date 2022-03-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef int ElemType;
#define MaxSize 50
typedef struct
{
    ElemType data[MaxSize];     //���ջ��Ԫ��
    int top;                    //ջ��ָ��
}SqStack;

void initStack(SqStack &s)    //��ʼ��
{
    s.top=-1;
}

bool stackEmpty(SqStack &s)     //ջΪ���򷵻�true
{
    if(s.top==-1)
        return true;
    return false;
}

bool push(SqStack &s,ElemType e)
{
    if(s.top==MaxSize-1)
        return false;
    s.data[++s.top]=e;      
    return true;
}

bool pop(SqStack &s,ElemType &e)
{
    if(stackEmpty(s))
        return false;
    e=s.data[s.top--];
    return true;
}

bool getTop(SqStack &s,ElemType &e)         //ע�⴫��ֵ
{
    if(stackEmpty(s))
       return false;
    e=s.data[s.top];
    return true;
}

bool destroyStack(SqStack &s)
{
    s.top=-1;
    return true;
}

int main()
{
    SqStack s;
    initStack(s);
    cout<<"ջ�Ƿ�Ϊ�գ�"<<(stackEmpty(s)==true)<<endl;
    for(int i=0;i<10;i++)
        push(s,i);
    cout<<"ջ��Ԫ�ظ�����"<<s.top+1<<endl;
    cout<<"ջ�и���Ԫ�أ�"<<endl;
    for(int i=0;i<10;i++)
    {
        ElemType e;getTop(s,e);     //e��ֱֵ���޸ĳ���topֵ
        cout<<e<<endl;
        pop(s,e);
    }

    // for(int i=0;i<10;i++)
    //     pop(s);
    // cout<<"ջ��Ԫ�ظ�����"<<s.top+1<<endl;

    system("pause");
    return 0;
}