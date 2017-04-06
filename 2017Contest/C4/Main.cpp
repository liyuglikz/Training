#include <iostream>
#include <algorithm>
#include <string>

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <cmath>
#include <set>
#include <map>

using namespace std;

typedef long long int ll;
typedef pair<int, int> Point;

const int MAXN = 505;
const double eps = 1e-8;

void input( Point &k )
{	scanf("%d%d", &k.first, &k.second);}

bool cmp1( const Point &x, const Point &y)
{
	return x.first + x.second > y.first + y.second;
}

bool cmp2( const Point &x, const Point &y)
{
	if( x.second != y.second)
		return x.second > y.second;
	return x.first > y.first;
}

bool flags[MAXN];
Point a[MAXN], b[MAXN];

void solve()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		memset( flags, 0, sizeof(flags));
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			input( a[i] );
		for(int i = 0; i < n; ++i)
			input( b[i] );

		sort(a, a + n, cmp1);
		sort(b, b + n, cmp1);

		bool ans = true;
		for(int i = 0; i < n && ans; ++i)
		{
			int j;
			for(j = 0; j < n; ++j)
			{
				if( !flags[j] && a[j].first > b[i].second && a[j].second >= b[i].first)
				{
					flags[j] = 1;
					break;
				}
			}

			if( j == n)
				ans = false;
		}
		puts( ans ? "Yes" : "No");
	}
}

int main()
{
	solve();
	return 0;
}
