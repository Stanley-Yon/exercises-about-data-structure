/**
 * @file stack used in bracket.cpp
 * @brief ջ�������е�Ӧ��
 * @date 2022-03-30
 * 
 * �㷨��
 *      (1)��ʼջΪ�գ�˳������ַ�
 *      (2)����������ţ���ջ���ķ��ų�ջ�������⣬���ֲ��Ϸ���������˳�����
 *      (3)���������ţ���ѹ��ջ�У���Ϊ��������ķ��š��㷨����ʱ��ջΪ�գ������������в�ƥ��
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
            printf("����ƥ��ɹ�\n");
        else
           printf("����ƥ��ʧ��\n");
    }   

    system("pause");
    return 0;
}