#include <bits/stdc++.h>
#define sq(a) (a * a)

using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
typedef long double ldouble;

typedef pair<double, double> Point;

double dis(const Point &a, const Point &b)
{	return sqrt( sq( (a.first - b.first) ) + sq( (a.second - b.second) ));
}

double r1, r2;
Point A, B;

double getS( double t, double r)
{
	return r * r * t / 2.0;
}
#define k1  2.0 * r1 * d
#define k2  2.0 * r2 * d

int main()
{
	cin >> A.first >> A.second >> r1;
	cin >> B.first >> B.second >> r2;

	double d = dis(A, B);
	if(d >= r1 + r2)
	{
		printf("%.10lf\n", 0.0);
	}
	else if(d > fabs(r1 - r2) )
	{
		//double k1 = 2.0 * r1 * d;
		//double cost1 = (sq(r1) + sq(d) - sq(r2)) / (2.0 * r1 * d );
		double cost1 = (r1 / k1) * r1 + (d / k1) * d - (r2 / k1) * r2;
		double t1 = acos( cost1 );

		//double k2 = 2.0 * r2 * d;
		//double cost2 = (sq(r2) + sq(d) - sq(r1)) / (2.0 * r2 * d );
		double cost2 = (r2 / k2) * r2 + (d / k2) * d - (r1 / k2) * r1;
		double t2 = acos( cost2 );
		
		double ans = getS(2 * t1, r1) + getS(2 * t2, r2) - (d * r1 * sin( t1 ) );
		printf("%.7lf\n", ans);
	}
	else
	{
		printf("%.10lf\n", sq(min(r1, r2)) * pi );
	}

	return 0;
}
