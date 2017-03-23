#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
typedef long long int LL;

double X, Y;
double X1, Y1, X0, Y0;

bool get(double a, double b, double c)
{
	double cost = (c * c + a * a - b * b) / (2.0 * a * c);
	double sint = sqrt(1.0 - cost * cost);


	double d = cost * a;
	double D = (LL) d;
	double e = sint * a;
	double E = (LL) e;
	X = d;
	Y = e;

	X0 = c;
	Y0 = 0;

	for(double i = c; i > 0; --i)
	{
		double k = sqrt( c * c - i * i);
		if(k - (int)k < eps)
		{
			double t = atan( k / i );
			X = d * cos(t) - e * sin(t);
			Y = d * sin(t) + e * cos(t);
			if( X - (int)X < eps && Y - (int) Y < eps)
			{
				X1 = X0 * cos(t) - Y0 * sin(t);
				Y1 = X0 * sin(t) + Y0 * cos(t);
				printf("%g\n", t / pi);
				return true;
			}
		}
	}

	double t = pi / 2;
	X = d * cos(t) - e * sin(t);
	Y = d * sin(t) + e * cos(t);
	X1 = 0; Y1 = c;
	if( X - (int)X < eps && Y - (int) Y < eps)
		return true;

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
			printf("%.0lf %.0lf\n", X1, Y1);
			printf("%.0lf %.0lf\n", X, Y);
		}
		else if(get(b, a, c))
		{
			puts("0 0");
			printf("%.0lf %.0lf\n", X1, Y1);
			printf("%.0lf %.0lf\n", X, Y);
		}
		else if(get(a, c, b))
		{
			puts("0 0");
			printf("%.0lf %.0lf\n", X1, Y1);
			printf("%.0lf %.0lf\n", X, Y);
		}
		else if(get(c, a, b))
		{
			puts("0 0");
			printf("%.0lf %.0lf\n", X1, Y1);
			printf("%.0lf %.0lf\n", X, Y);
		}
		else if(get(c, b, a))
		{
			puts("0 0");
			printf("%.0lf %.0lf\n", X1, Y1);
			printf("%.0lf %.0lf\n", X, Y);
		}
		else if(get(b, c, a))
		{
			puts("0 0");
			printf("%.0lf %.0lf\n", X1, Y1);
			printf("%.0lf %.0lf\n", X, Y);
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
