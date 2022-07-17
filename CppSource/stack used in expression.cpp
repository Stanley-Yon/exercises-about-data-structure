/**
 * @file stack used in expression.cpp
 * @brief 栈在表达式求值中的应用
 * @date 2022-03-30
 * 
 * 中缀转后缀表达式算法：
 *  首先构造两个栈:存储中间结果栈s1、运算符栈s2
 * (1)从左至右扫描整个中缀表达式
 * (2)若是操作数直接压入s1当中
 * (3)若是运算符，比较s2中栈顶运算符的优先级
 *      3.1  若s2为空，或者符号为 '('，则直接压入栈s2
 *      3.2  否则运算符优先级高于栈顶符号，则压入栈s2   (这里则不包括相同的情况)
 *      3.3  否则将s2栈顶运算符弹出，压入s1当中，之后便将当前运算符压入到s2中
 * (4)若遇到括号
 *      4.1  如果是左括号，直接压入到s2中
 *      4.2  如果是右括号，弹出s2运算符并且压入到s1中，重复操作直至遇到左括号，另外这对括号需要删除
 * (5)重复步骤1->4，直到表达式最右边
 * (6)依次弹出s2的剩余运算符，压入至s1中
 * 
 * 
 * 后缀表达式的运算：
 * (1)从左向右扫描元素，至全部处理为止
 * (2)若为操作数，则压入操作数栈中回到 <1>，否则至 <3>
 * (3)扫描到运算符，从操作数栈中弹出两个元素，并且执行相应的运算结果，进而结果压入栈中。 转<1>。
 * 
 */
#include<bits/stdc++.h>
using namespace std;
stack<char> s1;  //存储中间结果
stack<char> s2;  //运算符栈
char lev1[]={'+','-'};
char lev2[]={'*','/'};    //lev2比lev1的优先级高

bool initStack(stack<char> s)
{   
    if(!s.empty())
    {
        for(int i=0;i<s.size();i++)
            s.pop();
    }
    return true;
}
bool isDigit(const char ch)
{
    if( ch>='0' && ch<='9' )
        return true;
    return false;
}
bool isOP(const char op)
{
    if(op=='+' || op=='-' || op=='*' || op=='/' )
        return true;
    return false;
}
/**
 * @param ch1 扫描到的当前运算符
 * @param ch2 栈s2中的运算符
 *   优先级：ch1>ch2 return true
 *          else return false;
 */
bool comparePriority(const char ch1,const char ch2)
{
    int c1,c2;
    c1=c2=1;
    if( ch1=='*' || ch1=='/' )
        c1=2;
    if( ch2=='*' || ch2=='/' )
        c2=2;
    return c1>c2?true:false;
}

//中缀表达式转后缀表达式
void postfixExpression(string expression)
{
    initStack(s1);
    initStack(s2);
    for(int i=0;i<expression.length();i++)
    {
        char ch=expression[i];      //当前扫描到的运算符
        if( isDigit(ch) ){
            s1.push(ch);
            continue;
        }
        else if(isOP(ch)){
            if(s2.empty() || s2.top()=='(')
                s2.push(ch);
            else{
                bool isPrior=comparePriority(ch,s2.top());
                switch (isPrior)
                {
                case true:
                    s2.push(ch);
                    break;   
                case false:
                    char ch2=s2.top();
                    s2.pop();
                    s1.push(ch2);
                    s2.push(ch);
                    break;
                }
            }
            // continue;
        }else if( ch=='(' ){
            s2.push(ch);
        }
        else if(ch==')'){
            char ch2=' ';
            while (1)
            {
                ch2=s2.top();
                s2.pop();
                if(ch2=='(')
                    break;
                s1.push(ch2);
            }
        }
    }//表达式处理完毕
    //s2栈中全部弹出
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
    return;
}

//后缀表达式的计算结果值
int calculate(string postEx)
{
    stack<int> s;
    for(int i=0;i<postEx.length();i++)
    {
        char ch=postEx[i];
        if( ch>='0' && ch<='9')
            s.push((ch-'0'));   //数字字符转数字
        else{
            int op2=s.top();s.pop();    //右边数
            int op1=s.top();s.pop();    //左边数        顺序错位可导致- /运算出错
            int res;
            switch (ch)  
            {
            case '+':
                res=op1+op2;
                break;
            case '-':
                res=op1-op2;
                break;
            case '*':
                res=op1*op2;
                break;
            case '/':
                res=op1/op2;
                break;
            default:
                break;
            }
            s.push(res);
        }
    }
    return s.top();
}

int main()
{
    //"((10 * (6 / ((9 + 3) * 7-11))) + 17) + 5"
    string expression[]={"1+((2+3)*4)-5","1 + 2 * 3 + 4",
                        "(1 + 2 * 3 + 4)"};
    int count=3;
    for(int i=0;i<count;i++)
    {
        postfixExpression(expression[i]);
        string postEx;
        while(!s1.empty()){
            postEx=s1.top()+postEx;
            s1.pop();
        }
        int res=calculate(postEx);
        cout<< "中缀表达式："+expression[i]<<" --------后缀表达式："<<postEx<<" ----------- 后缀表达式的运算结果："<<res<<endl;
    }
    system("pause");
    return 0;
}