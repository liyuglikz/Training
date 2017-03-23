#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5 + 5;

class Point{
public:
	double x, y;
	Point(){}
	Point(const double &a, const double &b) : x(a), y(b){}
	Point(const Point&k) {	this->x = k.x; this->y = k.y;}
	bool operator == (const Point &k) const
	{	return (this->x == k.x) && (this->y == k.y);}

	bool operator < (const Point &k) const
	{
		if( this->x == k.x)
			return this->y < k.y;
		return this->x < k.x;
	}

	Point operator - (const Point &k)
	{	return Point(this->x - k.x, this->y - k.y);}

	double operator * (const Point &k)
	{	return this->x * k.x + this->y * k.y;}

	double operator ^ (const Point &k)
	{	return this->x * k.y - this->y * k.x;}
}lib[MAXN];

Point p0, now;

bool cmp1(const Point &a, const Point &b)
{
	return ((p0 - a) ^ (p0 - b)) > 0;
}

map<Point, vector<Point> > mps;
vector<Point> vec;

void getSurface(int p, int e)
{
	int z = 0;
	for(int i = 0; i < p; ++i)
	{
		if(lib[i] < lib[z])
			z = i;
	}	

	p0 = lib[z];
	lib[z] = lib[0];
	lib[0] = p0;

	sort(mps[ lib[0] ].begin(), mps[ lib[0] ].end(), cmp1);

	now = mps[ lib[0] ][0];
	while(now != lib[0])
	{
		p0 = now;
		sort(mps[now].begin(), mps[now].end(), cmp1);
		now = mps[now][0];
	}
}

void solve()
{
	int p, e, a, b;
	while(scanf("%d%d", &p, &e) == 2)
	{
		mps.clear();
		vec.clear();

		for(int i = 0; i < p; ++i)
		{
			scanf("%lf%lf", &lib[i].x, &lib[i].y);
			mps.insert( pair<Point, vector<Point> > (lib[i], vec));
		}

		for(int i = 0; i < e; ++i)
		{
			scanf("%d%d", &a, &b);
			mps[lib[a]].push_back( lib[b] );
			mps[lib[b]].push_back( lib[a] );
		}

		for(int i = 0; i < p; ++i)
		{
			
		}
	}
}

int main()
{
	solve();
	return 0;
}
