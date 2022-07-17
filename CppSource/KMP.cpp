/**
 * @file KMP.cpp
 * 
 * ����ģʽƥ���㷨---KMP�㷨
 * 
 * ��next[]�����ǹؼ�!!!!
 *      ���㴮ǰ׺�ʹ���׺��ȵ���󳤶�
 * 
 */

#include<bits/stdc++.h>
using namespace std;
#define MaxSize 100

// **������һ��         next�����0��ʼ�洢
void getNext(string t,int next[])   //  ģʽ��t
{
    memset(next,0,sizeof(int)*(t.length()+1));
    int i=0,j=-1;
    next[0]=-1;
    while(i<t.length()){
        if(j==-1 || t[i]==t[j] ){
            i++;j++;
            next[i]=j;
        }
        else
            j=next[j];
            // for(int i=0;i<t.length();i++){cout<<next[i]<<" ";cout<<"i="<<i<<"   j="<<j<<endl;}           
    }
 
}

int KMP_index(string s,string t)
{
    int* next=new int[s.length()+1];
    getNext(t,next);
    //for(int i=0;i<t.length();i++){cout<<next[i]<<" ";}           

    int i=0,j=0;        // i��j�ֱ�ָ��������ģʽ��
    while(i<s.length() && j<t.length())
    {
        if(j==-1 || s[i]==t[j] )    
                //j=-1 ��ʾ ģʽ���ĵ�һ���ַ��������ĵ� i ���ַ�����ʱ��������һ���ַ��ıȽ�
            ++i,++j;
        else
            j=next[j];      //ָ��j����
    }
    if(j>=t.length())
        return i-t.length()+1;
    else
        return 0;
}

void getNext_val(string t,int next[])   // �Ż�
{

}

int main()
{
    string s="ababcabcacbab";
    string t="abcac";
    string t2="aaab" ;
    int index=KMP_index(s,t);
    cout<<"ģʽ�����������е�������"<<index<<endl;
  
    system("pause");
    return 0;
}

