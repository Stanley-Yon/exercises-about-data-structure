/**
 * @file stack.cpp
 * @author xuYongLong (xyl008654785@126.com)
 * @brief 栈的顺序存储
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
    ElemType data[MaxSize];     //存放栈中元素
    int top;                    //栈顶指针
}SqStack;

void initStack(SqStack &s)    //初始化
{
    s.top=-1;
}

bool stackEmpty(SqStack &s)     //栈为空则返回true
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

bool getTop(SqStack &s,ElemType &e)         //注意传入值
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
    cout<<"栈是否为空："<<(stackEmpty(s)==true)<<endl;
    for(int i=0;i<10;i++)
        push(s,i);
    cout<<"栈中元素个数："<<s.top+1<<endl;
    cout<<"栈中各个元素："<<endl;
    for(int i=0;i<10;i++)
    {
        ElemType e;getTop(s,e);     //e的值直接修改成了top值
        cout<<e<<endl;
        pop(s,e);
    }

    // for(int i=0;i<10;i++)
    //     pop(s);
    // cout<<"栈中元素个数："<<s.top+1<<endl;

    system("pause");
    return 0;
}