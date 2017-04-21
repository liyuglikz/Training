#include <iostream>
#include <algorithm>
#include <string>

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>

#define twi(a) (a * a)
#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)

using namespace std;
const int MAXN = 1e5 + 5;
const int INF = 0x7fffffff;

const double eps = 1e-8;
const double pi = acos(-1.0);

typedef pair<double, double> Point;
typedef Point Vector;

double iabs( const double &k)
{	return k < 0 ? -k : k;}

Point operator - (const Point &A, const Point &B)
{	return Point( A.first - B.first, A.second - B.second);}

double dis2( Point &A, Point &B)
{	return twi( (A.first - B.first) ) + twi( (A.second - B.second) );}

double dis( Point &A, Point &B)
{	return sqrt( dis2(A, B) ); }

double operator * (const Point &A, const Point &B)
{	return A.first * B.first + A.second * B.second;}

double operator ^ (const Point &A, const Point &B)
{	return (A.first * B.second - A.second * B.first);}

double dsDis( Point &A, Point &B, Point &C) // AC & B
{
	return iabs( (A - B) ^ (A - C)) / ( dis(A, C) );
}

////////////////////////////////////////////////////////////////////////
int n;
double ans = 0;
Point lib[MAXN];
double dt[MAXN];

void init()
{
	for(int i = 0; i < n; ++i)
		dt[i] = dsDis( lib[i], lib[ (i + 1) % n], lib[ (i + 2) % n] );
}

double judge(double k)
{
	double tmp = INF;
	for(int i = 0; i < n; ++i)
		tmp = MIN(tmp,  dt[i] - 2 * k);
	return tmp;
}


void input()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%lf%lf", &lib[i].first, &lib[i].second);
}

void solve()
{
	init();

	double l = 0;
	double r = (dis( lib[0], lib[1] ) / 2.0);
	double m = 0;
	double tmp = 0;
	ans = 0;

	while( r - l > eps)
	{
		m = (r + l) / 2.0;
		tmp = judge( m );	
		if( tmp < 0)
			r = m;
		else
		{
			ans = MAX( ans, m );
			l = m;
		}
	}

}

void output()
{
	printf("%lf\n", ans);
}

int main()
{
	input();
	solve();
	output();

	return 0;
}
