#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#define INF 1<<25
using namespace std;

int n;
int L,C;
int tl[1010];//tl[i]: ��i��topicռ�õ�ʱ��
int noL;
int dp[1010][1010];//dp[i][j]:ǰi��lecture cover j��topic����СDI
int m[1010];//m[i]: ǰi��lecture���cover��topic����
int DP(int l, int t);
int DI(int di);

int main()
{
    int cases = 0;
    bool okay = false;
    //freopen("data.in","r",stdin);
    while(1)
    {
        for(int i=0;i<1010;i++)
            for(int j=0;j<1010;j++)
                dp[i][j] = -INF;
        cin>>n;
        if(!n)
            break;
        if(okay)//һ��Ҫ��break֮�󰡣����������һ�����С�����
            cout<<endl;//����Ϊ����������Ҷ���һ��WA�������ˡ�������Ϊ�㷨�������ˡ�����
        okay = true;
        cin>>L>>C;
        for(int i=1;i<=n;i++)
            cin>>tl[i];
        noL = 1;
        m[0] = 0;
        int h = L;
        for(int i=1;i<=n;i++)
        {
            if(h-tl[i]>=0)
                h -= tl[i];
            else
            {
                m[noL] = i-1;
                noL++;
                h = L - tl[i];
            }
        }
        m[noL] = n;
        dp[0][0] = 0;
        for(int i=0;i<=noL;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i>j)
                    dp[i][j] = INF;
                if(j>m[i])
                    dp[i][j] = INF;
            }
        }
        //for(int i=0;i<=noL;i++)
        //{
        //    cout<<m[i]<<endl;
       // }
        printf("Case %d:\nMinimum number of lectures: %d\n",++cases,noL);
        printf("Total dissatisfaction index: %d\n",DP(noL,n));
    }
    return 0;
}


int DP(int l, int t)
{
    if(dp[l][t]!=-INF)
        return dp[l][t];
    int h = L;
    int minn = INF;
    for(int i=t;i>=1;i--)
    {
        h -= tl[i];
        if(h<0)
            break;
        minn = min(minn,DP(l-1,i-1)+DI(h));
    }
    return dp[l][t] = minn;
}

int DI(int di)
{
    if(di==0)
        return 0;
    if(1<=di&&di<=10)
        return -C;
    return (di-10)*(di-10);
}

















