#include <iostream>
#include <algorithm>
#include <string>

#include <vector>
#include <set>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
const int MAXN = 1e5 + 5;
vector<int> mps[MAXN];
set<int> s;
int father[MAXN];

int n, m;
int a, b;

int getfather( int x )
{
	if( x != father[x])
		father[x] = getfather( father[x] );
	return father[x];
}

void merge( int x, int y)
{
	int x_r = getfather(x);
	int y_r = getfather(y);

	if( x_r != y_r)
		father[y_r] = x_r;
}

void solve()
{
	while(scanf("%d", &n) == 1 && n)
	{
		s.clear();
		for(int i = 1; i <= n; ++i)
		{
			mps[i].clear();
			father[i] = i;
		}

		scanf("%d", &m);

		for(int i = 0; i < m; ++i)
		{
			scanf("%d%d", &a, &b);
			mps[a].push_back( b );
			mps[b].push_back( a );
			merge(a, b);
		}

		for(int i = 1; i <= n; ++i)
		{
			getfather( i );
			s.insert( father[i] );
		}

		int ans = 0;

		if( s.size() == 1)
		{
			for(int i = 1; i <= n && !ans; ++i)
				ans = (ans | (mps[i].size() & 1));
		}
		else
			ans = 1;
		printf("%d\n", !ans);
	}
}

int main()
{
	solve();
	return 0;
}
