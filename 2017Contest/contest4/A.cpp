#include<cstdio>
#include<cmath>
#include<iostream>
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

		Point operator ^ (const Point &k)
		{
			return Point(
			y * k.z - z * k.y,
			z * k.x - x * k.z,
			x * k.y - y * k.x
			);
		}

		double len2()
		{
			return x * x + y * y + z * z;
		}

		double getS( Point a, Point b)
		{	return ((*this - a) ^ (*this - b)).len2();}

		double dis2( const Point &k)
		{	return (x - k.x) * (x - k.x) +
		(y - k.y) * (y - k.y) +
		(z - k.z) * (z - k.z);
		}
};


Point A, C[2];
Point s[9];
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

Point lib[3][4][2];
double ln[3];

double getDis( Point &P, int cnt)
{
	double buff = INF;
	//printf("cnt: %d\n", cnt);

	if( cnt == 1)
		cnt = 2; //z
	else if(cnt == 2)
		cnt = 1; //y
	else if(cnt == 4)
		cnt = 0; //x
	
	for(int i = 0; i < 4; ++i)
	{
		buff = min(buff, ((P.getS(lib[cnt][i][0], lib[cnt][i][1]) / (ln[ cnt ] * ln[cnt]))));
//		printf("Buff: %g\n", buff);
	}
	return buff;
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

	ln[0] = C[1].x - C[0].x;
	ln[1] = C[1].y - C[0].y;
	ln[2] = C[1].z - C[0].z;

	for(int i = 0; i < 2; ++i)
	{
		sDis[3] = min( sDis[3], iabs( A.x - C[i].x ));
		sDis[5] = min( sDis[5], iabs( A.y - C[i].y ));
		sDis[6] = min( sDis[6], iabs( A.z - C[i].z ));
	}

	sDis[3] = sDis[3] * sDis[3];
	sDis[5] = sDis[5] * sDis[5];
	sDis[6] = sDis[6] * sDis[6];
	
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

	// y
	lib[1][0][0] = s[5 - 1];
	lib[1][0][1] = s[7 - 1];

	lib[1][1][0] = s[6 - 1];
	lib[1][1][1] = s[8 - 1];

	lib[1][2][0] = s[1 - 1];
	lib[1][2][1] = s[3 - 1];

	lib[1][3][0] = s[2 - 1];
	lib[1][3][1] = s[4 - 1];


	//x
	lib[0][0][0] = s[1 - 1];
	lib[0][0][1] = s[5 - 1];

	lib[0][1][0] = s[2 - 1];
	lib[0][1][1] = s[6 - 1];

	lib[0][2][0] = s[3 - 1];
	lib[0][2][1] = s[7 - 1];

	lib[0][3][0] = s[4 - 1];
	lib[0][3][1] = s[8 - 1];


	//z
	lib[2][0][0] = s[5 - 1];
	lib[2][0][1] = s[6 - 1];

	lib[2][1][0] = s[7 - 1];
	lib[2][1][1] = s[8 - 1];

	lib[2][2][0] = s[1 - 1];
	lib[2][2][1] = s[2 - 1];

	lib[2][3][0] = s[3 - 1];
	lib[2][3][1] = s[4 - 1];

	int cnt = count(A);

	if( cnt == 7)
		ans = 0;
	else if( cnt == 3)
		ans = min( ans, sDis[3]) ;
	else if( cnt == 5)
		ans = min( ans, sDis[5]) ;
	else if( cnt == 6)
		ans = min( ans, sDis[6]) ;
	else if( cnt != 0)
	{
		ans = min( ans, getDis( A, cnt ) );
	}

	printf("%.0f\n", ans);
}

int main()
{
	solve();
	return 0;
}
