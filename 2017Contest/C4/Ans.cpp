#include <iostream>
#include <algorithm>
#include <string>

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <cmath>
#include <set>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> Point;

const int MAXN = 505;
Point lib[MAXN];

set<Point> s;

bool operator < (const Point &a, const Point &b)
{
	if(a.first != b.first)
		return a.first < b.first;
	return a.second < b.second;
}

Point operator - (const Point &a, const Point &b)
{
	return Point( a.first - b.first, a.second - b.second);
}

Point operator + (const Point &a, const Point &b)
{
	return Point( a.first + b.first, a.second + b.second);
}

Point mirr( Point &a, Point &b, Point &c)
{
	Point v1 = b - a;
	Point v2 = c - a;
	Point v = v1 + v2;
	return v + a;
}

void input( Point &k)
{
	scanf("%lld%lld", &k.first, &k.second);
}

Point buff[4];

void solve()
{
	int n;
	while( scanf("%d", &n) == 1)
	{
		int ans = 0;

		s.clear();

		for(int i = 0; i < n; ++i)
		{
			input( lib[i]);
			s.insert( lib[i] );
		}

		for(int i = 0; i < n - 2; ++i)
		{
			for(int j = i + 1; j < n - 1; ++j)
			{
				for(int k = j + 1; k < n; ++k)
				{
					buff[0] = mirr( lib[i], lib[j], lib[k]);
					buff[1] = mirr( lib[j], lib[i], lib[k]);
					buff[2] = mirr( lib[k], lib[j], lib[i]);

					for(int t = 0; t < 3; ++t)
					{
						if( s.end() != s.find( buff[t] ) )
						{
							++ans;
						}
					}
				}
			}
		}
		printf("%d\n", ans / 4);
	}
}

int main()
{
	solve();
	return 0;
}
