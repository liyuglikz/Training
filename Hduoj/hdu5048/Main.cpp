#include <iostream>
#include <algorithm>
#include <string>

#include <set>
#include <queue>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

const int MAXN = 1e2 + 5;
const double eps = 1e-8;
const double pi = acos(-1);

using namespace std;


double ans[10];

double iabs( const double &k)
{
	return k < 0 ? -k : k;
}

class Color
{
	public:
		int R, G, B;
	Color( char col = 0)
	{
		this->init(col);
	}

	Color(const int &a, const int &b, const int &c) : R(a), G(b), B(c){}

	void init(char col)
	{
		switch(col)
		{
			case 'R' : R = 4; break;
			case 'G' : G = 2; break;
			case 'B' : B = 1; break;
		}
	}
	
	Color operator + (const Color &k)
	{
		return Color( this->R + k.R, this->G + k.G, this->B + k.B);
	}

	Color operator - (const Color &k)
	{
		return Color( this->R - k.R, this->G - k.G, this->B - k.B);
	}
};

class Point
{
public:
	double x, y, z;
	Point(){}
	Point(const double &a, const double &b, const double &c) : x(a), y(b), z(c){}

	Point(const Point &b)
	{
		this->x = b.x;
		this->y = b.y;
		this->z = b.z;
	}

	Point operator + (const Point &b)
	{
		return Point(this->x  + b.x, this->y + b.y, this->z + b.z);
	}

	Point operator - (const Point &b)
	{
		return Point( this->x - b.x, this->y - b.y, this->z - b.z);
	}

	Point operator ^ (const Point &k)
	{
		return Point(this->y * k.z - this->z * k.y, 
					this->z * k.x - this->x * k.z,
					this->x * k.y - this->y * k.x);	
	}

	double operator * ( const Point &k)
	{
		return this->x * k.x + this->y * k.y + this->z * k.z;
	}

	double dis2( const Point &k)
	{
		return
		(this->x - k.x) * (this->x - k.x) +
		(this->x - k.x) * (this->x - k.x) +
		(this->x - k.x) * (this->x - k.x);
	}

	double dis( Point &k)
	{
		return sqrt( this->dis( k ) );
	}

	bool operator == (const Point &k) const
	{
		return iabs( this->x - k.x) < eps && iabs( this->y - k.y) < eps && iabs( this->z - k.z) < eps;
	}

	bool operator < (const Point &k) const
	{
		if(this->x == k.x)
			return this->y < k.y;
		return this->x < k.x;
	}
};
typedef Point Vector;


class Segment
{
public:
	Point s, e;
	Segment(){}
	Segment( const Point &a, const Point &b) : s(a), e(b){}

	friend bool operator < (const Segment &a, const Segment &b)
	{
		if(a.s == b.s)
			return a.e < b.e;
		return a.s < b.s;	
	}

	bool isPointOn(Point &k)
	{
		return (( (k - s) * (e - s) ) * ( ( k - e) * ( s - e) )) < 0;	
	}
};

class Ellipsoid
{
public:
	Color color;
	Point p;
	double a, b, c;
	double a2, b2, c2;

	void init()
	{
		a2 = a * a;
		b2 = b * b;
		c2 = c * c;
	}

	double pDis( Point &k)
	{
		return
		(k.x - p.x) * (k.x - p.x) / a2 +
		(k.y - p.y) * (k.y - p.y) / b2 +
		(k.z - p.z) * (k.z - p.z) / c2;
	}

	bool isPoint_on_Ellipsoid( Point &k)
	{
		return (1.0 - this->pDis( k ) <= eps);
	}
};

Segment lib[MAXN];
Ellipsoid el[MAXN];

Segment* get( Segment &l, Ellipsoid &k)
{

	Vector se = l.e - l.s;
	double A = ( (se.x * se.x) / k.a2 ) + ( (se.y * se.y) / k.b2 ) + ( (se.z * se.z) / k.c2);
	double B = 2 * ( ( se.x * l.s.x / k.a2 ) + ( se.y * l.s.y / k.b2 ) + ( se.z * l.s.z / k.c2) );
	double C = ( (l.s.x * l.s.x) / k.a2 ) + ( (l.s.y * l.s.y) / k.b2 ) + ( (l.s.z * l.s.z) / k.c2);

	double delta = B * B - 4 * A * C;

	if(delta < 0)
		return NULL;
	else if(delta < eps)
		return NULL;
	else
	{
		double k1 = ( -B + sqrt(delta) )/ (2 * A);
		double k2 = ( -B - sqrt(delta) )/ (2 * A);

		double X1 = se.x * k1 + l.s.x;
		double X2 = se.x * k2 + l.s.x;

		double Y1 = se.y * k1 + l.s.y;
		double Y2 = se.y * k2 + l.s.y;

		double Z1 = se.z * k1 + l.s.z;
		double Z2 = se.z * k2 + l.s.z;

		
		Point p1(X1, Y1, Z1);
		Point p2(X2, Y2, Z2);

		if(l.isPointOn( p1 ))
		{
			//
		}
		if(l.isPointOn( p2 ))
		{
			//
		}
		return new Segment( p2, p1 );
	}
}

set<Segment> buff;
set<Segment> :: iterator it;

queue<int> t1;
queue<int> t2;

void shot(const int &k, const int &m)
{
	buff.clear();
	Segment *p = NULL;

	for(int i = 0; i < m; ++i)
	{
		p = get( lib[k], el[i]);

		if(NULL != p)
		{
			if( p->s < lib[k].s)
				p->s = lib[k].s;

			if( lib[k].e < p->e)
				p->e = lib[k].e;

			buff.insert( *p );

			free( p );
			p = NULL;
		}
	}

	for(it = buff.begin(); it != buff.end(); ++it)
	{

	}
}

void solve()
{
	int T, n, m, col_num;
	char col;
	Point pc1, pc2;
	cin >> T;
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; ++i)
		{
			scanf("%lf%lf%lf", &pc1.x, &pc1.y, &pc1.z);
			scanf("%lf%lf%lf", &pc2.x, &pc2.y, &pc2.z);
	
			if(pc2 < pc1)
				swap ( pc1, pc2 );

			lib[i].s = pc1;
			lib[i].e = pc2;

			//scanf ("%lf%lf%lf", &lib[i].s.x, &lib[i].s.y, &lib[i].s.z);
			//scanf ("%lf%lf%lf", &lib[i].e.x, &lib[i].e.y, &lib[i].e.z);
		}
		
		for(int i = 0; i < m; ++i)
		{
			scanf ("%lf%lf%lf", &el[i].p.x, &el[i].p.y, &el[i].p.z);
			scanf ("%lf%lf%lf", &el[i].a, &el[i].b, &el[i].c);
			scanf ("%c", &col);
			el[i].color.init(col);
		}

		for(int i = 0; i < n; ++i)
		{
			shot (i, m);
		}

		for(int i = 0; i < 8; ++i)
			printf ("%.5lf\n", ans[i]);
	}
}

int main()
{
	solve ();
	return 0;
}
