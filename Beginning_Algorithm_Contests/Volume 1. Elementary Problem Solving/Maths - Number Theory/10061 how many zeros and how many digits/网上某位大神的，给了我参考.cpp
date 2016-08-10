#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <cstdlib>  
using namespace std;  
  
int factor_count[1000]; //������¼С�ڵ���B�����ӵĸ���  
int N,B;  
  
int ZeroNum()  
{  
    //decompose N!  
    memset(factor_count,0,sizeof(factor_count));  
    for(int i=2; i<=N; i++)  
    {//decompose i  
        int tmp=i;  
        for(int j=2; j<=tmp && j<=B; j++) //ֻ��ҪС�ڵ���B�����ӣ���Ϊ����B������һ�������ΪB������  
        {  
            while(tmp%j==0)  
            {  
                factor_count[j]++;  
                tmp /= j;  
            }  
        }  
    }  
    int nZero=0;  
    while(1)  
    {//decompose B  
        int tmp=B;  
        for(int i=2; i<=tmp; i++)  
        {  
            while(tmp%i==0 && factor_count[i]>0)  
            {  
                factor_count[i]--;  
                tmp /= i;  
            }  
        }  
        if(tmp==1) nZero++;  
        else break;  
    }  
    return nZero;  
}  
  
int DigitNum()  
{  
    //compute logB(N!)  
    double sum=0;  
    for(int i=2; i<=N; i++)  
        sum += log10(double(i));  
    sum /= log10(double(B));  
    //comput digits num  
    return floor(sum+1e-9) + 1;  
  
}  
  
int main()  
{  
    while(cin >> N >> B)  
    {  
        cout << ZeroNum() << ' ' << DigitNum() << endl;  
    }  
    return 0;  
}  