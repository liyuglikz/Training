#include <bits/stdc++.h>
#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)
using namespace std;
const int MAXN = 1e6 + 5;
const int MAXM = MAXN << 2; const double go[][2] = {1.0, 0.0, 0.0, 1.0, -1.0, 0.0, 0.0, -1.0};
const double eps = 1e-8;
const double q2 = sqrt(2.00);

class Point{
public:
	double x, y;
	Point(){}
	Point(const double &a, const double &b) : x(a), y(b){}
	
	bool operator == (const Point &k) const 
	{	return (fabs(this->x - k.x) < eps) && (fabs(this->y - k.y) < eps);}

	bool operator != (const Point &k) const 
	{	return !(*this == k);}

	Point operator - (const Point &k)
	{	return Point(this->x - k.x, this->y - k.y);}

	double operator * (const Point &k)
	{	return this->x * k.x + this->y * k.y;}
	
	double operator ^ (const Point &k)
	{	return this->x * k.y - this->y * k.x;}

	double dis2(const Point &k)
	{	return (this->x - k.x) * (this->x - k.x) + (this->y - k.y) * (this->y - k.y);}

	double dis (Point &k)
	{	return sqrt( dis2( k ) );}

	double man_dis(const Point &k)
	{
		double a = fabs(this->x - k.x), b = fabs(this->y - k.y);
		if(a < b)
			return a * q2 + (b - a);
		else if(a > b)
			return b * q2 + (a - b);
		else
			return a * q2;
	}

	bool operator < (const Point &k) const
	{
		if(fabs(this->x - k.x) < eps)
			return (this->y - k.y) < eps;
		return (this->x - k.x) < eps;
	}
};

set<Point> flags;
Point lib[MAXM], p0, ans[MAXM], s[MAXN];

bool cmp(Point &a, Point &b)
{
	if(fabs((p0 - a) ^ (p0 - b)) < eps)
	{
		return p0.dis2(a) <= p0.dis2(b);
		//return ((p0 - a) * (b - a)) < 0;
	}
	return ((p0 - a) ^ (p0 - b)) >= 0;
}

stack<Point> sta;

int getHux(int n, Point ans[])
{
	while(!sta.empty())
		sta.pop();

	int length = 0;
	Point a, b;

	sta.push( lib[0] );
	sta.push( lib[1] );

	for(int i = 2; i < n; ++i)
	{
		b = sta.top();
		sta.pop();
		a = sta.top();

		while(sta.size() > 1 && (((lib[i] - b) ^ (b - a)) >= 0))
		{
			b = a;
			sta.pop();
			a = sta.top();
		}
		sta.push(b);
		sta.push(lib[i]);
	}

	while(!sta.empty())
	{
		ans[length++] = sta.top();
		sta.pop();
	}
	return length;
}

void solve()
{
	int n;
	while(scanf("%d", &n) == 1)
	{
		flags.clear();

		int len = 0, mini = 0, now = 0;
		for(int i = 0; i < n; ++i)
		{
			scanf("%lf%lf", &s[i].x, &s[i].y);
		}

		len = 0;

		for(int i = 0; i < n; ++i)
		{	
			for(int j = 0; j < 4; ++j)
			{
				lib[len].x = s[i].x + go[j][0];
				lib[len].y = s[i].y + go[j][1];
				
				if( flags.find( lib[len] ) == flags.end())
				{
					flags.insert( lib[len] );
					++len;
				}
			}
		}

		for(int i = 0; i < len; ++i)
		{
			if( lib[i] < lib[mini])
				mini = i;
		}

		p0 = lib[mini];
		lib[mini] = lib[0];
		lib[0] = p0;		

		sort(lib + 1, lib + len, cmp);

		int alen = getHux(len, ans);
		double answer_length = 0;
	
		//printf("%d\n", alen);

		for(int i = 0; i < alen - 1; ++i)
		{
			answer_length += (ans[i].man_dis( ans[i + 1]));
		}
		answer_length += (ans[alen - 1].man_dis( ans[0] ));

		printf("%.6lf\n", answer_length);
	}
}

int main()
{
	solve();
	return 0;
}
