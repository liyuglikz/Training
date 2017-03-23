#include <iostream>
#include <algorithm>

#include <stdio.h>
#include <math.h>

#define X first
#define Y second

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)

using namespace std;
const double eps = 1e-8;
const double pi = acos(-1);
const int MAXN = 1e5 + 5;

typedef long long int ll;
typedef pair<double, double> Point;
typedef pair<Point, Point> Segment;

Point operator - (const Point &a, const Point &b)
{
	return Point(a.X - b.X, a.Y - b.Y);
}

double operator ^ (const Point &a, const Point &b)
{
	return a.X * b.Y - a.Y * b.X;
}

bool operator < (const Point &a, const Point &b)
{
	if(a.X == b.X)
		return a.Y < b.Y;
	return a.X < b.X;
}

Segment lib[MAXN];

bool isCross( Segment &a, Segment &b)
{
	return
	( MAX(a.X.X, a.Y.X) >= MIN(b.X.X, b.Y.X) ) &&
	( MAX(a.X.Y, a.Y.Y) >= MIN(b.X.Y, b.Y.Y) ) && 
	( MIN(a.X.X, a.Y.X) <= MAX(b.X.X, b.Y.X) ) &&
	( MIN(a.X.Y, a.Y.Y) <= MAX(b.X.Y, b.Y.Y) ) &&
	( ((a.X - b.X) ^ (a.X - b.Y)) * ((a.Y - b.X) ^ (a.Y - b.Y)) <= 0) && 
	( ((b.X - a.X) ^ (b.X - a.Y)) * ((b.Y - a.X) ^ (b.Y - a.Y)) <= 0);
}


bool cmp(const Segment &a, const Segment &b)
{
	if(a.X.X == b.X.X)
		return a.Y < b.Y;
	return a.X < b.X;
}

int main()
{
	int T = 0;
	register Point cache;
	scanf("%d", &T);
	while(T--)
	{
		ll sum = 0;
		int n;
		scanf("%d", &n);
		for(register int i = 0; i < n; ++i)
		{
			scanf("%lf%lf%lf%lf", &lib[i].X.X, &lib[i].X.Y, &lib[i].Y.X, &lib[i].Y.Y);
			if(lib[i].X.X > lib[i].Y.X)
			{
				cache = lib[i].X;
				lib[i].X = lib[i].Y;
				lib[i].Y = cache;
			}
		}

		sort(lib, lib + n, cmp);

		for(register int i = 0; i < n; ++i)
		{
			for(register int j = i + 1; j < n; ++j)
			{
				if(lib[i].Y.X < lib[j].X.X)
					break;
				if(isCross( lib[i], lib[j] ))
					++sum;
			}
		}
		printf("%lld\n", sum);
	}
	return 0;
}
