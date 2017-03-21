#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
typedef long long int LL;

LL X, Y;

bool get(double a, double b, double c)
{
	double cost = (c * c + a * a - b * b) / (2.0 * a * c);
	double sint = sqrt(1.0 - cost * cost);


	double d = cost * a;
	double D = (LL) d;
	double e = sint * a;
	double E = (LL) e;
	if( (d - D) < eps && (e - E) < eps)
	{
		X = D; Y = E;
		return true;
	}


	cost = (c * c + b * b - a * a) / (2.0 * b * c);
	sint = sqrt(1.0 - cost * cost);

	d = cost * b;
	D = (LL) d;
	e = sint * b;
	E = (LL) e;
	if( (d - D) < eps && (e - E) < eps)
	{
		X = D; Y = E;
		return true;
	}

	return false;
}

void solve()
{
	double a, b, c;
	while(scanf("%lf%lf%lf", &a, &b, &c) == 3)
	{
		if(get(a, b, c))
		{
			puts("0 0");
			printf("%lld 0\n", (LL)c);
			printf("%lld %lld\n", X, Y);
		}
		else if(get(a, c, b))
		{
			puts("0 0");
			printf("%d 0\n", (LL)b);
			printf("%d %d\n", X, Y);
		}
		else if(get(b, c, a))
		{
			puts("0 0");
			printf("%lld 0\n", (LL)a);
			printf("%lld %lld\n", X, Y);
		}
		else
			puts("-1");
	}
}

int main()
{
	solve();
	return 0;
}
