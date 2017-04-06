#include <iostream>
#include <string>
#include <algorithm>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include <map>
#include <set>

using namespace std;
typedef long long int ll;

const int MAXN = 1e5 + 5;
const ll md = 1e9 + 7;

class Point
{
public:
	ll first;
	int second;

	Point(){}
	Point(const ll &a, const int &b) : first(a), second(b) {}
	Point( const Point &now) {first = now.first; second = now.second;}

	bool friend operator < (const Point &a, const Point &b)
	{
		if(a.first != b.first)
			return a.first > b.first;
		return a.second > b.second;
	}
};
typedef pair<Point, ll> P;

set<Point> mps;
set<Point> :: iterator it;

ll sum[MAXN];
ll dp[MAXN];

ll lib[MAXN];


ll find(const Point &now )
{
	ll ans = 0;
	it = mps.upper_bound( now );
	
	if( it != mps.end() && it->first == now.first )
	{
		it = mps.upper_bound( Point(now.first, 0) );
	}

	if( it != mps.end())
	{
		ans = (sum[ it->second ] + 1);
		sum[ now.second ] = (ans + sum[ mps.upper_bound(now) -> second]) % md;
	}
	else
	{
		ans = 1;
		sum[ now.second ] = (1 + sum[ mps.rbegin()->second]);
	}

	if( ans >= md)
		ans -= md;

	return ans;
}

void solve()
{
	int n;
	while(scanf("%d", &n) == 1)
	{
		mps.clear();
		memset(sum, 0, sizeof(sum));
		memset(dp, 0, sizeof(ll) * (n + 5 ));
		//dp.clear();
		for(int i = 1; i <= n; ++i)
		{
			scanf("%lld", lib + i);
		}

		dp[ 1 ] = 1;
		sum[ 1 ] = 1;
		mps.insert( Point( lib[1], 1) );

		for(int i = 2; i <= n; ++i)
		{	
			dp[i] = find( Point(lib[i], i));
			mps.insert( Point(lib[i], i) );
		}

		ll ans = 0;

		for(int i = 1; i <= n; ++i)
		{
			ans = (ans + dp[i]) % md;
		}

		printf("%lld\n", ans);
	}
}

int main()
{
	solve();
	return 0;
}
