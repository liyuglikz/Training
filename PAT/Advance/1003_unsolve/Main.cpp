#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> Node;

const int MAXN = 505;

int mps[MAXN][MAXN];
int lib[MAXN];
int dis[MAXN];

int n, m, st, ed;

stack<int> sta;

void dfs( int st, int ed )
{
	int now = 0;
	sta.push( st );	

	while( !sta.empty() )
	{
		now = sta.top();
		sta.pop();

		if( now == ed )
			return;

		for(int i = 0; i <= n; ++i)
		{
			if( mps[now][i] >= 0)
			{
				sta.push( now );	
			}
		}
	}
}

int main()
{
	int a, b, c;
	memset( mps, -1, sizeof( mps ) );
	memset( dis, -1, sizeof( dis ) );
	scanf("%d%d%d%d", &n, &m, &st, &ed);

	for(int i = 0; i < n; ++i)
		scanf("%d", lib + i);

	for(int i = 0; i < m; ++i)
	{
		scanf("%d%d%d", &a, &b, &c);
		mps[a][b] = mps[b][a] = c;
	}

	return 0;
}
