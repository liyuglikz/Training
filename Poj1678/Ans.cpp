//#include <bits/stdc++.h>

#include <iostream>
#include <algorithm>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)

using namespace std;
const int MAXN = 1e5 + 5;
const int INF = 0x7FFF;

int n, a, b;
int lib[MAXN];
int dp[MAXN];

int dfs(int k)
{
	if(dp[k] != -1)
		return dp[k];

	int ans = INF;

	for(int i = k + 1; i < n; ++i)
	{
		if( lib[i] - lib[k] >= a && lib[i] - lib[k] <= b)
		{
			ans = MIN(ans, lib[k] - dfs(i));
			// 使对方得到分差越小越好
		}
	}

	if(ans == INF)
		ans = lib[k];

	if( dp[k] == -1)
	{
		dp[k] = ans;	
	}
	else
		dp[k] = ans;

	return dp[k];
}

int getAnswer()
{
	int ans = -INF;
	for(int i = 0; i < n; ++i)
	{
		if(lib[i] >= a && lib[i] <= b)
			ans = MAX(ans, dfs( i ) );
	}

	return ans == -INF ? 0 : ans;
}

void solve()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		memset(dp, -1, sizeof(dp));
		scanf("%d%d%d", &n, &a, &b);
		for(int i = 0; i < n; ++i)
			scanf("%d", lib + i );

		sort(lib, lib + n);
		
		printf("%d\n", getAnswer());
	}
}

int main()
{
	solve();
	return 0;
}
