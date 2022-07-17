/**
 * @file stack used in bracket.cpp
 * @brief 栈在括号中的应用
 * @date 2022-03-30
 * 
 * 算法：
 *      (1)初始栈为空，顺序读入字符
 *      (2)如果是右括号，则栈顶的符号出栈进行消解，出现不合法的情况则退出程序
 *      (3)若是左括号，则压入栈中，作为急迫消解的符号。算法结束时，栈为空，否则括号序列不匹配
 */
#include<bits/stdc++.h>
using namespace std;
stack<char> s;
void initStack()
{
    if(s.size()==0)
        return;
    for(int i=0;i<s.size();i++)
        s.pop();
}
bool bracketMatch(const char *str,int size)
{
    for(int i=0;i<size;i++)
    {
        char ch=str[i];
        char ch2=' ';
        switch (ch)
        {
            case '(':
            case '[':
            case '{':
                s.push(ch);
                break;
            case ')':
                if(s.empty())
                    return false;
                ch2=s.top();
                s.pop();
                if(ch2 != '(')
                    return false;
                break;
            case ']':
                if(s.empty())
                    return false;
                ch2=s.top();
                s.pop();
                if(ch2 != '[')
                    return false;
                break;
            case '}':
                if(s.empty())
                    return false;
                ch2=s.top();
                s.pop();
                if(ch2 != '{')
                    return false;
                break;
        }       
    }
    if(!s.empty())     
        return false;
    return true;

}

int main()
{
    const char *seq[]={
		"(())abc{[(])}",
		"(()))abc{[]}",
		"(()()abc{[]}",
		"(())abc{[]()}",
        "(((((((())))))))abc{[{([])}]()}"
	};
	
    for(int i=0;i<5;i++)
    {
        initStack();
        if( bracketMatch(seq[i],strlen(seq[i])) )
            printf("括号匹配成功\n");
        else
           printf("括号匹配失败\n");
    }   

    system("pause");
    return 0;
}