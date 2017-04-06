#include <iostream>
#include <algorithm>
#include <string>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <vector>
#include <queue>
#include <stack>

using namespace std;

const double eps = 1e-8;
const double pi = acos(-1);
const int MAXN = 105;

typedef long long int ll;

int T, n, len, now;
bool flags[MAXN], flag;

vector<int> mps[MAXN];
vector<int> in[MAXN];
stack<int> ans;

inline void dfs( int x)
{
	++now;
	flags[x] = true;

	if(!flag && now == n)
	{
//		printf("%d\n", x);
		ans.push(x);
		flag = true;
		return;
	}

	vector<int> :: iterator it;
	for( it = mps[x].begin(); !flag && it != mps[x].end(); ++it)
	{
		if( !flags[*it])
		{
//			printf("-----------%d %d\n", x, *it);
			dfs( *it );
		}
	}

	if( flag )
	{
		ans.push( x );
	}
	flags[x] = false;
	--now;
}

inline void output()
{
	if(!flag)
	{
		puts("Impossible");
		return;
	}
	while( ans.size() > 1)
	{
		printf("%d ", ans.top());
		ans.pop();
	}
	printf("%d\n", ans.top());
	ans.pop();
}

void solve()
{
	scanf("%d", &T);
	while(T--)
	{
		int a, b, st;
		int cnt = 0;
		flag = false;

		memset(flags, 0, sizeof(flags));
		while(!ans.empty())
			ans.pop();

		scanf("%d", &n);
		for(int i = 1; i <= n; ++i)
		{
			mps[i].clear();
			in[i].clear();
		}
		len = (n * (n - 1)) >> 1;

		if(n == 1)
		{
			puts("1");
			continue;
		}

		for(int i = 0; i < len; ++i)
		{
			scanf("%d%d", &a, &b);
			mps[a].push_back( b );
			in[b].push_back( a );
		}

		for(int i = 1; i <= n; ++i)
		{
			if( in[i].empty())
			{
				st = i;
				++cnt;
			}
		}

		if( cnt > 1)
		{
			puts("Impossible");
		}
		else if(cnt == 1)
		{
			now = 0;
			dfs( st );

			output();
		}
		else
		{
			for(int i = 1; !flag && i <= n; ++i)
			{
				now = 0;
				dfs(i);
			}

			output();
		}
	}
}

int main()
{
	solve();
	return 0;
}
