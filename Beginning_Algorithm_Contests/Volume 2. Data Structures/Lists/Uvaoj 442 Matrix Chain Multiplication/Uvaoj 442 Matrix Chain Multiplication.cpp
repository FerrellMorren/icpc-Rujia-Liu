/*
//accepted�Ĵ���
//�����е��ҡ�����
//��Ϊ��̵�ʱ��û����������˺ܳ�ʱ��debug����
//�����ԭ��һ��һ��ʼ�߼��ṹ���ԣ����Ǹı��˳�ʼ�ľ����ֵ�����Դ�һ�¾ͺ��ˡ�����
//���������Ǳ�ڵ�bug����
//����Ĵ�����Ǻõģ���

#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;

int n;
int first[30];
int second[30];
int f[30];
int se[30];
char ex[1000];
bool ok;
int sum;
int cases = 0;
stack<char> s;

void make();

int main()
{
    //freopen("data.in","r",stdin);
    cin>>n;
    getchar();
    for(int i=0;i<n;i++)
    {
        char hold[100];
        fgets(hold,sizeof(hold),stdin);
        char h = hold[0];
        char hh;
        sscanf(hold,"%c %d %d",&hh,&f[h-'A'],&se[h-'A']);
    }
    while(fgets(ex,sizeof(ex),stdin)!=NULL)
    {
        for(int i=0;i<30;i++)
        {
            first[i] =  f[i];
            second[i] = se[i];
        }
        cases++;
        for(int i=0;i<s.size();i++)
            s.pop();
        ok = true;
        sum = 0;
        int d = strlen(ex);
        if(d==1)
        {
            cout<<0<<endl;
            continue;
        }
        for(int i=0;i<d;i++)
        {
            if(s.empty())
                s.push(ex[i]);
            else
            {
                if(ex[i]==')')
                {
                    char h = s.top();
                    s.pop();
                    s.pop();
                    s.push(h);
                    make();
                    if(!ok)
                        break;
                }
                if(ex[i]=='(')
                    s.push(ex[i]);
                if(ex[i]>='A'&&ex[i]<='Z')
                {
                    s.push(ex[i]);
                    make();
                    if(!ok)
                        break;

                    //if(s.top()=='(')
                  //      s.push(ex[i]);
                 //   if(s.top()>='A'&&s.top()<='Z')
                 //   {
                 //       char h = s.top();
                //        s.pop();
                 //       if(second[h-'A']!=first[ex[i]-'A'])
                  //      {
                  //          cout<<"error"<<endl;
                  //          ok = false;
                  //          break;
                   //     }
                   //     else
                   //     {
                   //         sum += first[h-'A']*first[ex[i]-'A']*second[ex[i]-'A'];
                  //          second[h-'A'] = second[ex[i]-'A'];
                 //           s.push(h);
                 //           make();
                 //       }
                 //   }

                }
            }
        }
        if(!ok)
            continue;
        cout<<sum<<endl;
    }
    return 0;
}

void make()
{
    char a = s.top();
    if(a>='A'&&a<='Z')
    {
        s.pop();
        if(!s.empty())
        {
            char b = s.top();
            if(b>='A'&&b<='Z')
            {
                if(first[a-'A']!=second[b-'A'])
                {
                    cout<<"error"<<endl;
                    ok = false;
                    return;
                }
                s.pop();
                sum += first[b-'A']*first[a-'A']*second[a-'A'];
                //cout<<cases<<" "<<first[b-'A']<<" "<<first[a-'A']<<" "<<second[a-'A']<<endl;
                //cout<<cases<<" "<<sum<<endl;
                first[a-'A'] = first[b-'A'];
            }
        }
        s.push(a);
    }
}
*/








#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;

int n;
int first[30];
int second[30];
int f[30];
int se[30];
char ex[1000];
bool ok;
int sum;
stack<char> s;

void make();

int main()
{
    //freopen("data.in","r",stdin);
    cin>>n;
    getchar();
    for(int i=0;i<n;i++)
    {
        char hold[100];
        fgets(hold,sizeof(hold),stdin);
        char h = hold[0];
        sscanf(hold,"%c %d %d",&h,&f[h-'A'],&se[h-'A']);
    }
    while(fgets(ex,sizeof(ex),stdin)!=NULL)
    {
        for(int i=0;i<30;i++)
        {
            first[i] =  f[i];
            second[i] = se[i];
        }
        for(int i=0;i<s.size();i++)
            s.pop();
        ok = true;
        sum = 0;
        int d = strlen(ex);
        if(ex[d-1]=='\n')//fgets���յ��˻��У��ѻ����ӵ�����
            d--;
        if(d==1)
        {
            cout<<0<<endl;
            continue;
        }
        for(int i=0;i<d;i++)
        {
            if(s.empty())
                s.push(ex[i]);
            else
            {
                if(ex[i]==')')
                {
                    char h = s.top();
                    s.pop();
                    s.pop();
                    s.push(h);
                    make();
                    if(!ok)
                        break;
                }
                else
                {
                    s.push(ex[i]);
                    make();
                    if(!ok)
                        break;
                }
            }
        }
        if(!ok)
            continue;
        cout<<sum<<endl;
    }
    return 0;
}

void make()
{
    char a = s.top();
    if(a>='A'&&a<='Z')
    {
        s.pop();
        if(!s.empty())
        {
            char b = s.top();
            if(b>='A'&&b<='Z')
            {
                if(first[a-'A']!=second[b-'A'])
                {
                    cout<<"error"<<endl;
                    ok = false;
                    return;
                }
                s.pop();
                sum += first[b-'A']*first[a-'A']*second[a-'A'];
                first[a-'A'] = first[b-'A'];
            }
        }
        s.push(a);
    }
}






