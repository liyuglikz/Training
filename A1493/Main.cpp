#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 262144

//const long long P=50000000001507329LL; // 190734863287 * 2 ^ 18 + 1
const int P=1004535809; // 479 * 2 ^ 21 + 1
//const int P=998244353; // 119 * 2 ^ 23 + 1
const int G=3;

long long mul(long long x,long long y)
{
    return x * y % P;
}
long long qpow(long long x,long long k)
{
    long long ret=1;
    while(k)
    {
        if(k&1) ret=mul(ret,x);
        k>>=1;
        x=mul(x,x);
    }
    return ret;
}

long long wn[25];
void getwn()
{
    for(int i=1; i<=21; ++i)
    {
        int t=1<<i;
        wn[i]=qpow(G,(P-1)/t);
    }
}

int len;
void NTT(long long y[],int op)
{
    for(int i=1,j=len>>1,k; i<len-1; ++i)
    {
        if(i<j) swap(y[i],y[j]);
        k=len>>1;
        while(j>=k)
        {
            j-=k;
            k>>=1;
        }
        if(j<k) j+=k;
    }
    int id=0;
    for(int h=2; h<=len; h<<=1)
    {
        ++id;
        for(int i=0; i<len; i+=h)
        {
            long long w=1;
            for(int j=i; j<i+(h>>1); ++j)
            {
                long long u=y[j],t=mul(y[j+h/2],w);
                y[j]=u+t;
                if(y[j]>=P) y[j]-=P;
                y[j+h/2]=u-t+P;
                if(y[j+h/2]>=P) y[j+h/2]-=P;
                w=mul(w,wn[id]);
            }
        }
    }
    if(op==-1)
    {
        for(int i=1; i<len/2; ++i) swap(y[i],y[len-i]);
        long long inv=qpow(len,P-2);
        for(int i=0; i<len; ++i) y[i]=mul(y[i],inv);
    }
}
void Convolution(long long A[],long long B[],int n)
{
    for(len=1; len<(n<<1); len<<=1);
    for(int i=n; i<len; ++i)
    {
        A[i]=B[i]=0;
    }

    NTT(A,1);
    NTT(B,1);
    for(int i=0; i<len; ++i)
    {
        A[i]=mul(A[i],B[i]);
    }
    NTT(A,-1);
}

long long A[MAXN],B[MAXN];

long long d[MAXN],f[MAXN]= {1},fact[MAXN]= {1},fact_inv[MAXN]= {1};
/*
    d[n] = f[n]-fact[n-1]*Σ(fact_inv[i-1]*d[i]*f[n-i]*fact_inv[n-i])
*/

/*
void cdq(int l,int r)
{
	if(l == r)
		return;

	int mid = (l + r) >> 1;
//	printf("%d %d %d\n", l, mid, r);
	cdq(l, mid);

	for(int i = 0; i < l; ++i)
		A[i] = 0;

	for(int i = l; i <= mid; ++i)
		A[i] = mul( fact_inv[i - 1], d[i]);

	for(int i = mid + 1; i <= r; ++i)
		A[i] = 0;

	for(int i = 0; i <= r - l; ++i)
		B[i] = mul(fact_inv[i], f[i]);

	Convolution( A, B, r + 1);

	for(int i = mid + 1; i <= r; ++i)
	{
		d[i] -= mul(fact[i - 1], A[i]);
		if( d[i] < 0 )
			d[i] += P;
	}

	cdq(mid + 1, r);
}

*/
void cdq(int l,int r){
    if(l==r) return;
    int mid=l+r>>1;
    cdq(l,mid);
    for(int i=l; i<=mid; ++i){
        A[i-l]=mul(fact_inv[i-1],d[i]);
    }
    for(int i=mid-l+1; i<=r-l; ++i) A[i]=0;
    for(int i=0; i<=r-l; ++i){
        B[i]=mul(fact_inv[i],f[i]);
    }
    Convolution(A,B,r-l+1);
    for(int i=mid+1; i<=r; ++i){
        d[i]-=mul(fact[i-1],A[i-l]);
        if(d[i]<0) d[i]+=P;
    }
    cdq(mid+1,r);
}

int main()
{
    getwn();

    for(int i=1; i<=130000; ++i)
    {
        fact[i]=mul(fact[i-1],i);
        fact_inv[i]=qpow(fact[i],P-2);
        d[i]=f[i]=qpow(2,(i-1LL)*i/2);
    }

    cdq(1,130000);
	//cdq(1, 2000);

    int n;
    while(~scanf("%d",&n))
    {
        printf("%lld\n",d[n]);
    }
    return 0;
}
