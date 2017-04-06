#include<string>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;


int main()
{
   LL a,b,c;
   while(~scanf("%lld%lld%lld",&a,&b,&c))
	{
   LL ans;
   LL sum = a+b+c;
   if(sum==a)
   {
      ans = a;
   }
   else if(sum==b)
   {
      ans = b;
   }
   else if(sum==c)
   {
      ans = c;
   }
   else if(a==0)
   {
       if(b<=c)
       {
            if(b==1)
            {
                ans = 2LL*c+b;
            }
            else
            {
                ans = 2LL*b+3LL*c-2LL;
            }
       }
       else
       {
           if(c==1)
           {
               ans = 2LL*b;
           }
           else
           {
              ans = 2LL*b+3LL*c-2LL;
           }
       }

   }
   else if(b==0)
   {

      if(c>=a)
      {
          if(a==1)
          {
              ans = 2LL*c+1LL;
          }
          else
          {
              ans = a+2LL*b+3LL*c;
          }
      }
      else
      {
          ans = a+2LL*b+3LL*c;
      }
   }
   else if(c==0)
   {
      ans = a+2LL*b+3LL*c;
   }
   else
   {
      ans = a+2LL*b+3LL*c;
   }
   printf("%lld\n",ans);

	}
return 0;
}
/*
1000000000 1000000000 1000000000
*/

/*
0 2 6
0 3 6
0 3 1
0 3 3


2 4 6
3 5 7
8 9 10
11 12 13
15
*/
