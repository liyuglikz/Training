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

map<Point, ll> mps;
map<Point, ll> :: iterator it;

ll dp[MAXN];

ll lib[MAXN];


ll find(const Point &now )
{
	ll ans = 0;
	it = mps.upper_bound( now );
	//it = mps.begin();
	
	if( it != mps.end() && it->first.first == now.first )
	{
		it = mps.upper_bound( Point(now.first, 0) );
	}

	if( it != mps.end())
	{
		ans = (mps[ it->first ] + 1);
		
		//mps.insert( P(now,
		//(ans + mps[ mps.upper_bound(now)->first ]) % md));

		//mps[now] = (ans + mps[ mps.upper_bound(now)->first ]);
	}
	else
	{
		ans = 1;
		mps.insert( P(now,
		mps[now] = (1 + mps[ mps.rbegin()->first ]) ));

		//mps[now] = (1 + mps[ mps.rbegin()->first ]) % md;
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
		memset(dp, 0, sizeof(ll) * (n + 5 ));
		//dp.clear();
		for(int i = 1; i <= n; ++i)
		{
			scanf("%lld", lib + i);
		}

		//dp.insert( P(Point(lib[1], 1), 1) );
		dp[ 1 ] = 1;
		mps.insert( P(Point( lib[1], 1), 1) );

		for(int i = 2; i <= n; ++i)
		{	
			//dp.insert( P( Point(lib[i], i),
			//(find( Point(lib[i], i))))	);
			dp[i] = find( Point(lib[i], i));
		}

		ll ans = 0;

		//for(it = dp.begin(); it != dp.end(); ++it)
			//ans = (ans + it->second) % md;
		for(int i = 1; i <= n; ++i)
		{
//			printf("%d %lld\n", i, dp[i]);
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
