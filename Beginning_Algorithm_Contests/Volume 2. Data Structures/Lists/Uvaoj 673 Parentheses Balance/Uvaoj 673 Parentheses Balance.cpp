#include<cstring>
#include<stack>
#include<cstdio>
#include<iostream>
using namespace std;


char s[200];
char r(char a);

int main()
{
    //freopen("data.in","r",stdin);
    int n;
    cin>>n;
    getchar();
    for(int cc=0;cc<n;cc++)
    {
        s[0] = '\0';//������ַ���������d������ǰ��d
       // scanf("%s",s);//scanf�ǲ��еģ����Զ����м�Ŀ���ʡ�Ե��ˡ���������ʶ�ˡ�������
        gets(s);//��fgets����
        int d = strlen(s);
        stack<char> a;
        for(int i=0;i<d;i++)
        {
            if(s[i]=='('||s[i]==')'||s[i]=='['||s[i]==']')
            {
                if(a.empty())
                    a.push(s[i]);
                else
                {
                    if(a.top()==r(s[i]))
                        a.pop();
                    else
                        a.push(s[i]);
                }
            }
        }
        if(a.empty())
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}



char r(char a)
{
    if(a==']')
        return '[';
    if(a==')')
        return '(';
    return '\0';
}
