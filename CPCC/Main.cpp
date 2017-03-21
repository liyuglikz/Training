#include <iostream>
#include <algorithm>
#include <string>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <set>

using namespace std;
const int MAXN = 202;
const double eps = 1e-8;

double iabs(const double &k)
{
	return k < 0 ? -k : k;
}

class Point{
public:
	double x, y, z;
	Point(){}
	Point(const double &a, const double &b, const double &c) : x(a), y(b), z(c){}

	Point(const Point &k)
	{	this->x = k.x; this->y = k.y; this->z = k.z;}

	void operator = (const Point &k)
	{	this->x = k.x; this->y = k.y; this->z = k.z;}

	Point operator - (const Point &k)
	{	return Point(this->x - k.x, this->y - k.y, this->z - k.z);}

	double operator * (const Point &k)
	{	return this->x * k.x + this->y * k.y + this->z * k.z;}

	double dis2 (const Point &k)
	{	return (this->x - k.x) * (this->x - k.x) + (this->y - k.y) * (this->y - k.y) + (this->z - k.z) * (this->z - k.z);}

	double dis (Point &k)
	{	return sqrt( dis2(k) );}

	bool operator < (const Point &k) const
	{
		if(this->x == k.x)
		{
			if(this->y == k.y)
				return this->z < k.z;
			return this->y < k.y;
		}
		return this->x < k.x;
	}
	bool operator == (const Point &k) const
	{
		return iabs(this->x - k.x) < eps && iabs(this->y - k.y) < eps && iabs(this->z - k.z) < eps;
	}
};

class Segment{
public:
	Point s, e;
	Segment(){}
	Segment(const Segment &k)
	{
		s = k.s; e = k.e;
	}

	void operator = (const Segment &k)
	{
		s = k.s; e = k.e;
	}

	void init(const Point &a, const Point &b)
	{
		s = a; e = b;
	}

	bool operator < (const Segment &b) const
	{
		if(this->s == b.s)
			return this->e < b.e;
		return this->s < b.s;
	}

	bool operator == (const Segment &k) const 
	{	return this->s == k.s && this->e == k.e;}

	
};

bool cmp(Segment &a, Segment &b)
{
	if(a.s == b.s)
		return a.e < b.e;
	return a.s < b.s;
}

class Th{
public:
	Segment a, b;

	Th(){}
		
	Th(const Point &a1, const Point &a2, const Point &a3, const Point &a4)
	{
		a.s = a1;
		a.e = a2;
		b.s = a3;
		b.e = a4;
	}

	Th(const Segment n, const Segment m)
	{
		a = n;
		b = m;
	}

	bool operator < (const Th &k) const
	{
		if(this->a == k.a)
			return this->b < k.b;
		return this->a < k.a;
	}
};

Point lib[MAXN], s2[5];
Segment segs[MAXN * MAXN];

set<Th> s;

int main()
{
	int T, n;
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t)
	{
		s.clear();

		int len = 0;
		scanf("%d", &n);

		for(int i = 0; i < n; ++i)
			scanf("%lf%lf%lf", &lib[i].x, &lib[i].y, &lib[i].z);

		for(int i = 0; i < n; ++i)
		{
			for(int j = i + 1; j < n; ++j)
			{
				segs[len++].init(lib[i], lib[j]);
			}
		}

		sort(segs, segs + len, cmp);

		int ans(0), cnt(0);
		for(int i = 0; i < len; ++i)
		{
			for(int j = i; j < len; ++j)
			{
				if(iabs((segs[i].s - segs[i].e) * (segs[j].s - segs[j].e)) < eps)
				{
					double a = segs[i].s.dis2 (segs[j].s);
					double b = segs[i].s.dis2 (segs[j].e);
					double c = segs[i].e.dis2 (segs[j].s);
					double d = segs[i].e.dis2 (segs[j].e);
					double e = segs[i].s.dis2 (segs[i].e);
					double f = segs[j].s.dis2 (segs[j].e);
					if( iabs(a - b) < eps && iabs(c - d) < eps && iabs(b - c) < eps && a > eps)
					{
						s2[0] = segs[i].s;
						s2[1] = segs[i].e;
						s2[2] = segs[j].s;
						s2[3] = segs[j].e;
						sort(s2, s2 + 4);

						if(s.find( Th(s2[0], s2[1], s2[2], s2[3]) ) == s.end())
						{
							printf("%g %g %g %g %g %g\n", a,b ,c ,d, e, f);
							for(int k = 0; k < 4; ++k)
								printf("(%g, %g, %g) ", s2[k].x, s2[k].y, s2[k].z);
							++ans;
							s.insert( Th(s2[0], s2[1], s2[2], s2[3]) );
							cout << endl;
						}
					}
				}
			}
		}
		printf("Case %d: %d\n", t, ans);
	}
	return 0;
}
