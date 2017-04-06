#include <iostream>
#include <algorithm>
#include <string>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <vector>
#include <stack>
#include <set>
#include <map>

#include <unistd.h>

using namespace std;
const int MAXN = 1e4 + 5;

set<int> lib[MAXN];
bool flags[MAXN];

int n, k;

void dfs( int x )
{
	int t = 0;
	set<int> :: iterator it;
	for( it = lib[x].begin(); it != lib[x].end(); ++it)
	{
		if( false == flags[ *it ])
		{
			flags[*it] = true;
			dfs( *it );
		}
	}
}

void input1()
{
	int m, a, b;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i)
	{
		scanf("%d%d", &a, &b);
		lib[a].insert( b );
		lib[b].insert( a );
	}
}

void input2()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &k);
		lib[i].insert( k );
		lib[k].insert( i );
	}

}

void solve()
{
	input1();
	int ans = 0;
	for(int i = 1; i <= n; ++i)
	{
		if( false == flags[ i ] )
		{
			++ans;
			flags[i] = true;
			dfs( i );
		}
	}
	printf("%d\n", ans );
}

int main()
{
	solve();
	return 0;
}
