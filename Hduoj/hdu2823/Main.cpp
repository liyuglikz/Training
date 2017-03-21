#include <iostream>
#include <algorithm>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <stack>

#define P2(a) (a * a)
#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)

using namespace std;
const int INF = 0x7fffffff;
const int MAXN = 1e4 + 5;
const double eps = 1e-8;
class Point{
public:
	double x, y;
	Point(){}
	Point(const double &a, const double &b) : x(a), y(b){}
	Point operator -(const Point &k)
	{	return Point(this->x - k.x, this->y - k.y);}
	double operator * (const Point &k)
	{	return this->x * k.x + this->y * k.y;}
	double operator ^ (const Point &k)
	{	return this->x * k.y - this->y * k.x;}
	double dis2(Point &k)
	{	
		return  (this->x - k.x) * (this->x - k.x) + (this->y - k.y) * (this->y - k.y);
	}
	double dis(Point &k)
	{	
		return sqrt( this->dis2( k ) );
	}
	bool operator < (const Point &k)
	{
		if(this->x == k.x)
			return this->y < k.y;
		return this->x < k.x;
	}
	
	void input()
	{	scanf("%lf%lf", &x, &y);}

	bool isOnSegment(Point &p1, Point &p2)
	{
		return ((*this - p1) * (p2 - p1) > 0) && ((*this - p2) * (p1 - p2) > 0);
	}
};

Point p0;
Point a[MAXN], b[MAXN];
Point ah[MAXN], bh[MAXN];

bool cmp(Point &a, Point &b)
{
	if(((p0 - a) ^ (p0 - b)) == 0)
		return ((p0 - a) * (p0 - b)) >= 0;
	return ((a - p0) ^ (b - p0)) >= 0;
}

stack<Point> sta;

void getHux(int n, Point a[], int &len, Point ans[])
{
	while(!sta.empty())
		sta.pop();
	int mini = 0;

	for(int i = 0; i < n; ++i)
		if( a[i] < a[mini])
			mini = i;

	p0 = a[mini];
	a[mini] = a[0];
	a[0] = a[mini];

	sort(a, a + n, cmp);

	sta.push(a[0]);
	sta.push(a[1]);

	Point t1, t2;

	for(int i = 2; i < n; ++i)
	{
		t1 = sta.top();
		sta.pop();
		t2 = sta.top();

		while(sta.size() > 1 && ((a[i] - t1) ^ (a[i] - t2)) >= 0)
		{
			t1 = t2;
			sta.pop();
			t2 = sta.top();
		}

		sta.push(t1);
		sta.push( a[i] );
	}

	len = 0;

	while(!sta.empty())
	{
		ans[len++] = sta.top();
		sta.pop();
	}
}

// get Point & Segment distance
double getDis(Point p, Point s, Point e)
{
	if( (( p - s ) * (e - s) > 0) && ((p - e) * (s - e) > 0))
	{
		double s1 = fabs((p - s) ^ (p - e));
		double len = s.dis(e);
		//printf("===>%g\n", s1 / len);
		return s1 / len;
	}

	double l1 = p.dis(s);
	double l2 = p.dis(e);

//	printf("==>%g %g\n", l1, l2);

	return MIN(l1, l2);
}

bool isCross(Point &p1, Point &p2, Point &q1, Point &q2)
{
	return (((p1 - q1) ^ (p1 - q2) )*( (p2 - q1) ^ (p2 - q2)) <= 0 ) && (((q1 - p1) ^ (q1 - p2) )*( (q2 - p1) ^ (q2 - p2)) <= 0);
}

bool isSegmentCross( Point &s1, Point &e1, Point &s2, Point &e2)
{
	return 
	(MAX(s1.x, e1.x) >= MIN(s2.x, e2.x)) &&
	(MAX(s1.y, e1.y) >= MIN(s2.y, e2.y)) &&
	(MIN(s1.x, e1.x) <= MAX(s2.x, e2.x)) &&
	(MIN(s1.y, e1.y) <= MAX(s2.y, e2.y)) &&
	isCross(s1, e1, s2, e2);
}


bool isHuxCross(int n, Point a[], int m, Point b[])
{
	for(register int i = 0; i < n; ++i)
	{
		for(register int j = 0; j < m; ++j)
		{
			if( isSegmentCross( a[i], a[(i + 1) & n], b[i], b[(i + 1) % m]) )
				return true;
		}
	}
	return false;
}

double getAns(int n, Point a[], int m, Point b[])
{
	if(isHuxCross(n, a, m, b))
		return 0;

	double ans = INF;
	double s1, s2;
	int mid = 0, right, left;

	for(int mid = 0; mid < m - 1; ++mid)
	{
		s1 = fabs( (b[mid] - a[0]) ^ (b[mid] - a[1]));
		s2 = fabs( (b[mid + 1] - a[0]) ^ (b[mid + 1] - a[1]));
		if(s2 < s1)
			break;
	}

	double d1, d2, d3;
	int q, p;

	for(int i = 0; i < n; ++i)
	{
		p = i;
		q = (i + 1) % n;
		left = (mid + m - 1) % m;
		right = (mid + 1) % m;

		if( isCross(b[left], b[mid], a[p], a[q]) || 
			isCross(b[mid], b[right], a[q], a[q]))
			return 0.00;

		d1 = getDis( b[left], a[p], a[q]);
		d2 = getDis( b[mid], a[p], a[q]);
		d3 = getDis( b[right], a[p], a[q]);

		//printf("%d %d -> %g %g %g\n", i, mid, d1, d2, d3);
		//printf("(%g, %g) (%g, %g)\n", a[i].x, a[i].y, b[mid].x, b[mid].y);
	
		if((d2 < d1) && (d2 < d3))
		{
			ans = MIN(ans, d2);
		}			
		else if(d3 < d1)
		{
			mid = (mid + 1) % m;
			ans = MIN(ans, d3);
		}
		else if(d1 < d3)
		{
			mid = (mid + m - 1) % m;
			ans = MIN(ans, d1);
		}
	}

	return ans;
}

double ForceAns(int n, Point a[], int m, Point b[])
{
	if( isHuxCross(n, a, m, b))
		return 0;

	double ans = INF;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			ans = MIN( a[i].dis(b[j]), ans);
		}
	}
	return ans;
}

void solve()
{
	int n, m;
	while(scanf("%d%d", &n, &m) == 2)
	{
		int la = 0, lb = 0;

		for(int i = 0; i < n; ++i)
			a[i].input();
		for(int i = 0; i < m; ++i)
			b[i].input();

		getHux(n, a, la, ah);
		getHux(m, b, lb, bh);

		//printf("%.4lf\n", getAns(la, ah, lb, bh));	
		printf("%.4lf\n", ForceAns(la, ah, lb, bh));
	}
}

int main()
{
	solve();
	return 0;
}
