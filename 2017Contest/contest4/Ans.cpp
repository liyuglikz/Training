#include<string>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 200005
#define LL long long
using namespace std;

int dp[MAXN];
int main()
{
   int a,b,c;
   while(~scanf("%d%d%d",&a,&b,&c))
	{
	memset(dp, 0, sizeof(dp));

   if(a>3&&b>3&&c>3)
   {
       printf("%d\n",a+2*b+3*c);
   }
   else
    {
       int i,j,k;
       dp[0] = 1;
       for(i=0;i<=a;i++)
       {
            for(j=0;j<=b;j++)
            {
                for(k=0;k<=c;k++)
                {
                    dp[i+j*2+3*k] += dp[i+j*2+3*k -1 ] + dp[i+j*2+3*k -2 ] + dp[i+j*2+3*k - 3 ];
                }
            }
       }
       int ans = 0;
       for(i=0;i<=a+2*b+3*c;i++)
       {
           if(dp[i]!=0){ans++;}
       }
       printf("%d\n",ans-1);
    }
	}
	return 0;
}
