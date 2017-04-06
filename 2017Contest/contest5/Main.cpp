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

typedef pair<Point, ll> P;

set<ll> mps;
set<ll> :: iterator it;

ll sum[MAXN];
ll dp[MAXN];

ll lib[MAXN];
int flag[MAXN];
int global[MAXN];
bool flags[MAXN];

class Node
{
public:
	ll a;
	int b;
};

bool cmp(const Node &x, const Node &y)
{
	return x.a < y.a;
}

Node buff[MAXN];

inline int init(int n)
{
	int k = 1;
	ll cache;
	sort(buff + 1, buff + n + 1, cmp);

	cache = buff[1].a;
	buff[1].a = k;

	for(int i = 2; i <= n; ++i)
	{
		if(buff[i].a != cache)
			++k;
		cache = buff[i].a;
		buff[i].a = k;
	}

	for(int i = 1; i <= n;++i)
		lib[ buff[i].b ] = buff[i].a;
	return k;
}

inline ll find(const Point &now, const int &now_second)
{
	ll ans = 0;
	it = mps.upper_bound( now );
//	it = mps.begin();
	
	if( it != mps.end())
	{
		ans = (sum[ flag[it->first] ] + 1);
	}
	else
	{
		ans = 1;
	}

	sum[ now_second] = (ans + sum[ now_second - 1] );
	if( sum[ now_second ] >= md)
		sum[ now_second ] %= md;
	if( !flags[ now.first ])
	{
		mps.insert( now );
		flags[ now.first ] = true;
	}
	flag[ now.first ] = now_second;

	if( ans >= md)
		ans -= md;

	return ans;
}

void solve()
{
	int n;
	Point now;
	while(scanf("%d", &n) == 1)
	{
		mps.clear();
		//memset(flags, 0, sizeof(flags));
		memset(sum, 0, sizeof(ll) * (n + 5));
		//memset(dp, 0, sizeof(ll) * (n + 5 ));

		for(int i = 1; i <= n; ++i)
		{
			scanf("%lld", lib + i);
			buff[i].a = lib[i];
			buff[i].b = i;
		}
		int len = init( n );

		for(int i = 1; i <= n; ++i)
		{
			it = mps.upper_bound( lib[i] );
			if( it != mps.end())
				global[ *it ] = max(global[*it], lib[i]);
		}

		dp[ 1 ] = 1;
		sum[ 1 ] = 1;
		mps.insert( Point( lib[1] ) );
		flag[ lib[1] ] = 1;
		flags[ lib[1] ] = true;

		for(int i = 2; i <= n; ++i)
		{	
			now.first = lib[i];
			dp[i] = find( now, i);
		}

		ll ans = 0;

		for(int i = 1; i <= n; ++i)
		{
			ans = (ans + dp[i]);
			if(ans > md)
				ans %= md;
		}
		printf("%lld\n", ans);
		memset(flags, 0, sizeof(bool) * (len + 5) );
		//for(int i = 1; i <= len; ++i)
		//	flags[i] = 0;
	}
}

int main()
{
	solve();
	return 0;
}
