#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
const double eps = 1e-8;
int m,n;
double patient[1005];
int sig(double k)
{
    if(fabs(k)<eps) return 0;
    return k>0?1:-1;
}
int main()
{
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        double sum = 0,maxx = 0;
        for(int i=0; i<n; i++)
        {
            scanf("%lf",&patient[i]);
            sum+=patient[i];
        }
        double l = 0,r = sum;
        double ans = 0;
        while(sig(r-l))
        {
            double user = 0;
            double mid = (l+r)/2;
            for(int i=0; i<n; i++)
            {
                user+=min(patient[i],mid);
            }
            if(sig(user-mid*m)<0)
                r=mid;
            else
            {
                l = mid;
            }
        }
        printf("%.4lf\n",sum-r*(m-1));
    }
}
