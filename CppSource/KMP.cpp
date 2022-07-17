/**
 * @file KMP.cpp
 * 
 * 串的模式匹配算法---KMP算法
 * 
 * 求next[]数组是关键!!!!
 *      满足串前缀和串后缀相等的最大长度
 * 
 */

#include<bits/stdc++.h>
using namespace std;
#define MaxSize 100

// **看门牌一样         next数组从0开始存储
void getNext(string t,int next[])   //  模式串t
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

    int i=0,j=0;        // i、j分别指向主串和模式串
    while(i<s.length() && j<t.length())
    {
        if(j==-1 || s[i]==t[j] )    
                //j=-1 表示 模式串的第一个字符与主串的第 i 个字符不等时，继续下一个字符的比较
            ++i,++j;
        else
            j=next[j];      //指针j回退
    }
    if(j>=t.length())
        return i-t.length()+1;
    else
        return 0;
}

void getNext_val(string t,int next[])   // 优化
{

}

int main()
{
    string s="ababcabcacbab";
    string t="abcac";
    string t2="aaab" ;
    int index=KMP_index(s,t);
    cout<<"模式串在主串当中的索引："<<index<<endl;
  
    system("pause");
    return 0;
}

