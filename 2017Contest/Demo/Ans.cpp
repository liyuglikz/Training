#include <iostream>
#include <string>
#include <algorithm>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long int ll;

const double eps = 1e-5;
const double pi = acos(-1);
const int MAXN = 1e5 + 5;

class Virt
{
public:
	double r, v;

	Virt(){}
	Virt(const double &a, const double &b) : r(a), v(b){}

	Virt operator + (const Virt &k)
	{	return Virt( r + k.r, v + k.v);}

	Virt operator - (const Virt &k)
	{	return Virt( r - k.r, v - k.v);}

	Virt operator * (const Virt &k)
	{	return Virt( r * k.r - v * k.v, r * k.v + v * k.r);}
};

void bit_reverse(Virt x[], int n)
{
	for(int i = 0, j = 0; i != n; ++i)
	{
		if(i > j) swap(x[i], x[j]);
		for(int l = n >> 1; (j ^= l) < l; l >>= 1);
	}
}

void transform(Virt x[], int n, int on)
{
	bit_reverse(x, n);

	for(int i = 2; i <= n; i <<= 1)
	{
		int m = i >> 1;

		Virt w( cos( on * -2.0 * pi / i), sin( on * -2.0 * pi / i) );

		for(int j = 0; j < n; j += i)
		{
			Virt wn(1, 0);
			for(int k = 0; k < m; ++k)
			{
				Virt z = x[j + m + k] * wn;

				x[j + m + k] = x[j + k] - z;
				x[j + k] = x[j + k] + z;

				wn = wn * w;
			}
		}
	}

	if(on == -1)
	{
		for(int i = 0; i < n; ++i)
			x[i].r /= (double)n;
	}//逆向变换
}

void Convex( Virt x[], Virt y[], int len)
{
	transform(x, len, 1);
	transform(y, len, 1);
	for(int i = 0; i < len; ++i)
		x[i] = x[i] * y[i];
	transform(x, len, -1);
}

int getM(int k)
{
	int ans = 1;
	while( k )
	{
		k >>= 1;
		ans <<= 1;
	}
	return ans;
}

void longer( Virt T[], int len1, int len2)
{
	for(int i = len1; i < len2; ++i)
		T[i].r = T[i].v = 0;
}

void move( Virt T[], int len, int dis)
{
	for(int i = 0; i < len; ++i)
	{
		swap( T[i], T[i * dis]);
	}
}

int fun1(Virt x[], int len1, Virt y[], int len2)
{
	int len = getM(len1 + len2 - 1);

	longer(x, len1, len);
	longer(y, len2, len);

	Convex(x, y, len);
	return len;
}

int fun2(Virt x[], Virt y[], Virt z[], int len)
{
/*
	int len1 = getM( (len << 1) - 1);	

	transform(x, len1, 1);
	transform(y, len1, 1);

	for(int i = 0; i < len1; ++i)
		x[i] = x[i] * y[i];

//	int len2 = getM( len + len1 - 1);

	for(int i = 0; i < len1; ++i)
		x[i] = x[i] * y[i];

	transform(x, len1, -1);
	return len1;
*/
	int len1 = fun1(x, len, y, len);
	longer( z, len, len1);
	Convex(x, z, len1);
}


Virt A[MAXN], B[MAXN], C[MAXN], D[MAXN], E[MAXN], F[MAXN];
int lib[MAXN], cnt[MAXN];

int solve(int len, int n, int s)
{
	int len1 = fun1(D, len << 1, C, len);
	int len2 = fun2(A, B, F, len);
	
	printf("%d : %d : %d\n",
	(int)(A[s].r + eps) ,
	(int)(D[s].r + eps) , 
	(int)(E[s].r + eps) );

	return
	(
	(int)(A[s].r + eps) -
	(int)(D[s].r + eps) + 
	(int)(E[s].r + eps) * 2
	) / 6;
}

int input( int n , int s)
{
	int len = 0;

	memset(lib, 0, sizeof(lib));
	memset(cnt, 0, sizeof(cnt));

	//scanf("%d%d", &n, &s);
	for(int i = 0; i <MAXN; ++i)
		A[i].r = B[i].r = C[i].r = D[i].r = E[i].r = F[i].r = 0;

	for(int i = 0; i < n; ++i)
	{
		scanf("%d", lib + i);
		len = max(len, lib[i]);
		++cnt[ lib[i] ];
	}

	for(int i = 1; i <= len; ++i)
	{
		F [i].r = A [i].r = B[i].r = C[i].r = cnt [i];
		D [i * 2].r = cnt [i];
		E [i * 3].r = cnt [i];
	}

	return solve( len, n, s);
}

int main()
{
	int n, s;
	while(scanf("%d%d", &n, &s) == 2)
	{
		printf("%d\n", input(n, s));
	}
	return 0;

}
