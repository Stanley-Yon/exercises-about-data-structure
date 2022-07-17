/**
 * @file stack used in expression.cpp
 * @brief ջ�ڱ��ʽ��ֵ�е�Ӧ��
 * @date 2022-03-30
 * 
 * ��׺ת��׺���ʽ�㷨��
 *  ���ȹ�������ջ:�洢�м���ջs1�������ջs2
 * (1)��������ɨ��������׺���ʽ
 * (2)���ǲ�����ֱ��ѹ��s1����
 * (3)������������Ƚ�s2��ջ������������ȼ�
 *      3.1  ��s2Ϊ�գ����߷���Ϊ '('����ֱ��ѹ��ջs2
 *      3.2  ������������ȼ�����ջ�����ţ���ѹ��ջs2   (�����򲻰�����ͬ�����)
 *      3.3  ����s2ջ�������������ѹ��s1���У�֮��㽫��ǰ�����ѹ�뵽s2��
 * (4)����������
 *      4.1  ����������ţ�ֱ��ѹ�뵽s2��
 *      4.2  ����������ţ�����s2���������ѹ�뵽s1�У��ظ�����ֱ�����������ţ��������������Ҫɾ��
 * (5)�ظ�����1->4��ֱ�����ʽ���ұ�
 * (6)���ε���s2��ʣ���������ѹ����s1��
 * 
 * 
 * ��׺���ʽ�����㣺
 * (1)��������ɨ��Ԫ�أ���ȫ������Ϊֹ
 * (2)��Ϊ����������ѹ�������ջ�лص� <1>�������� <3>
 * (3)ɨ�赽��������Ӳ�����ջ�е�������Ԫ�أ�����ִ����Ӧ�����������������ѹ��ջ�С� ת<1>��
 * 
 */
#include<bits/stdc++.h>
using namespace std;
stack<char> s1;  //�洢�м���
stack<char> s2;  //�����ջ
char lev1[]={'+','-'};
char lev2[]={'*','/'};    //lev2��lev1�����ȼ���

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
 * @param ch1 ɨ�赽�ĵ�ǰ�����
 * @param ch2 ջs2�е������
 *   ���ȼ���ch1>ch2 return true
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

//��׺���ʽת��׺���ʽ
void postfixExpression(string expression)
{
    initStack(s1);
    initStack(s2);
    for(int i=0;i<expression.length();i++)
    {
        char ch=expression[i];      //��ǰɨ�赽�������
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
    }//���ʽ�������
    //s2ջ��ȫ������
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
    return;
}

//��׺���ʽ�ļ�����ֵ
int calculate(string postEx)
{
    stack<int> s;
    for(int i=0;i<postEx.length();i++)
    {
        char ch=postEx[i];
        if( ch>='0' && ch<='9')
            s.push((ch-'0'));   //�����ַ�ת����
        else{
            int op2=s.top();s.pop();    //�ұ���
            int op1=s.top();s.pop();    //�����        ˳���λ�ɵ���- /�������
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
        cout<< "��׺���ʽ��"+expression[i]<<" --------��׺���ʽ��"<<postEx<<" ----------- ��׺���ʽ����������"<<res<<endl;
    }
    system("pause");
    return 0;
}