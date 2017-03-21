#include <iostream>
#include <algorithm>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long int ll;

const double eps = 1e-5;
const double pi = acos(-1);
const int MAXM = 1e5 + 5;
const int MAXN = MAXM << 1;

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
		k = k >> 1;
		ans = ans << 1;
	}
	return ans;
}

void longer( Virt T[], int len1, int len2)
{
	for(int i = len1; i <= len2; ++i)
		T[i].r = T[i].v = 0;
}

ll GetC(ll k)
{
	return (k * (k - 1) ) / 2;
}


Virt A[MAXN], B[MAXN];
ll lib[MAXN];
int cnt[MAXN], a[MAXN], len1;

double solve(Virt A[], Virt B[], int n, int len)
{
	longer( A, len1, len);
	longer( B, len1, len);
	Convex( A, B, len);

	int k = 0;
	double sum = 0, ans = 0;
	lib[0] = 0;

	for(int i = 1; i <= len; ++i)
	{
		lib[i] = (ll) (A[i].r + eps);

		if (i & 1)
			lib[i] >>= 1;
		else
			lib[i] = ((lib[i] - (ll)cnt[ i >> 1] * cnt[i >> 1]) >> 1) + GetC( cnt[i >> 1]);

		lib[i] += lib[i - 1];
	}

	sort( a, a + n);

	int left, right;
	double tmp;
	for(int i = n - 1; i >= 0; --i)
	{
		left = a[i];
		right = a[i] << 1;

		tmp = lib[ right ] - lib[ left ];

		tmp -= ( n - 1.0 );
		tmp -= ( n - i - 1.0) * (i - 1.0);

		printf("%g\n", tmp);
		sum += tmp;
	}

	ans = ((double)n * (n - 1) * (n - 2)) / 6.0;
	printf("%g %g\n", ans, sum);

	ans = sum / ans;

	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		int n, len = 0;
		scanf("%d", &n);

		lib[0] = 0;
		memset(cnt, 0, sizeof(cnt));

		for(int i = 0; i < n; ++i)
		{
			scanf("%d", a + i);
			++cnt[ a[i] ];
			len = max(len, a[i]);
		}

		A[0].r = A[0].v = B[0].r = B[0].v = 0;

		for(int i = 1; i <= len; ++i)
		{
			A[i].r = B[i].r = cnt[i];
			A[i].v = B[i].v = 0;
		}

		++len;
		len1 = len;
		len = getM( (len << 1) - 1);
		//len = len1 << 1;

		printf("%7lf\n", solve( A, B, n, len));
	}

	return 0;
}
