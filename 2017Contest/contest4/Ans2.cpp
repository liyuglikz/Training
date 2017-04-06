#include<cstdio>
#include<cmath>
#include<iostream>

#define t2(N) ( (N) * (N) )

using namespace std;
const double eps = 1e-8;
const int INF = 0x7fffffff;

bool cmpB(const double &a, const double &b)
{
	return b - a > eps;
}

double iabs( const double &k)
{
	return (k < 0 ? -k : k);
}

class Point
{
	public:
		double x, y, z;
		Point(){}
		Point(const double &a, const double &b, const double &c) : x(a), y(b), z(c){}
		Point operator - (const Point &k)
		{	return Point(x - k.x, y - k.y, z - k.z);}

		Point(const Point &k)
		{	x = k.x; y = k.y; z = k.z;}

		void init(const double &a, const double &b, const double &c)
		{	x = a; y = b; z = c;}
		void input()
		{	scanf("%lf%lf%lf", &x, &y, &z);}

		double operator * (const Point &k)
		{	return x * k.x + y * k.y + z * k.z;}

		double dis2( const Point &k)
		{	return (x - k.x) * (x - k.x) +
		(y - k.y) * (y - k.y) +
		(z - k.z) * (z - k.z);
		}

		bool onSeg( Point a, Point b)
		{
			return
			(( a - *this) * (a - b)) >= 0 &&
			(( b - *this) * (b - a)) >= 0;
		}

		double dis2Seg( Point &a, Point &b)
		{
			double now = min(this->dis2(a), this->dis2(b));
			if( this->onSeg(a, b) )
				now = min( now, t2(iabs((*this - a) * (*this - b)) ));
			
			return now;
		}
};


Point A, C[2];
Point s[9];
Point lib[13][2];
int len;

int count(const Point &P)
{
	int cnt = 0;

	if( C[0].x <= P.x && P.x <= C[1].x)
		cnt = cnt | 4;

	if( C[0].y <= P.y && P.y <= C[1].y)
		cnt = cnt | 2;

	if( C[0].z <= P.z && P.z <= C[1].z)
		cnt = cnt | 1;

	return cnt;
}

void solve()
{
	double ans = INF;
	double sDis[16];

	for(int i = 0; i < 16; ++i)
		sDis[i] = INF;

	len = 0;
	A.input();
	C[0].input();	
	C[1].input();

	for(int i = 0; i < 2; ++i)
	{
		sDis[3] = min( sDis[3], iabs( A.x - C[i].x ));
		sDis[5] = min( sDis[5], iabs( A.y - C[i].y ));
		sDis[6] = min( sDis[6], iabs( A.z - C[i].z ));
	}
	
	for(int i = 0; i < 2; ++i)
	{
		for(int j = 0; j < 2; ++j)
		{
			for(int k = 0; k < 2; ++k)
			{
				s[len].init( C[i].x, C[j].y, C[k].z);
				ans = min(ans, A.dis2( s[len] ));
				++len;
			}
		}
	}

	for(int i = 0; i < 3; ++i)
		lib[i][0] = s[0];

		lib[0][1] = s[3 - 1];
		lib[1][1] = s[2 - 1];
		lib[2][1] = s[5 - 1];

	for(int i = 3; i < 6; ++i)
		lib[i][0] = s[7];

		lib[3][1] = s[3 - 1];
		lib[4][1] = s[8 - 1];
		lib[5][1] = s[5 - 1];

	for(int i = 6; i < 9; ++i)
		lib[i][0] = s[6];

		lib[6][1] = s[8 - 1];
		lib[7][1] = s[2 - 1];
		lib[8][1] = s[5 - 1];

	for(int i = 9; i < 12; ++i)
		lib[i][0] = s[4];

		lib[9][1] = s[3 - 1];
		lib[10][1] = s[2 - 1];
		lib[11][1] = s[8 - 1];

	for(int i = 0; i < 12; ++i)
	{
		ans = min(ans, A.dis2Seg( lib[i][0], lib[i][1]) );
	}

	int cnt = count( A );

	if( cnt == 7)
		ans = 0;
	else if( cnt == 3)
		ans = min( ans, sDis[3]) ;
	else if( cnt == 5)
		ans = min( ans, sDis[5]) ;
	else if( cnt == 6)
		ans = min( ans, sDis[6]) ;

	printf("%.0f\n", ans);
}

int main()
{
	solve();
	return 0;
}
