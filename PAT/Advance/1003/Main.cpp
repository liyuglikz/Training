#include <bits/stdc++.h>
#define MIN(a, b) (a < b ? a : b)

using namespace std;
typedef pair<int, int> Node;

const int MAXN = 505;

int mps[MAXN][MAXN];	//边权重（路径距离）
int lib[MAXN];	//节点权重（救援队个数）
int vec[MAXN];	//起点到各个节点的边权重（路径距离）

int ans[MAXN];	//起点到各个节点可以累加的(救援队) 最大数量
bool flags[MAXN];


int dijkstra(int a, int b, int n, int m)
{
	memset( flags, 0, sizeof(flags));
	memset( vec, -1 ,sizeof( vec) );
	memset( ans, 0, sizeof(ans));

	vec[a] = 0;
	ans[a] = lib[a];
	flags[a] = true;

	for(int i = 0; i < n; ++i)
	{
		if( mps[a][i] != -1 && i != a)
		{
			vec[i] = mps[a][i];
			ans[i] = lib[a] + lib[i];
		}
	}

	while(1)
	{
		int now = -1;

		for(int i = 0; i < n; ++i)
		{
			if( !flags[i] && vec[i] != -1)
			{
				if( now == -1 || (vec[i] < vec[now]))	
					now = i;
			}
		}

		if( now == -1)
			return vec[b];
		flags[ now ] = true;

		for(int i = 0; i < n; ++i)
		{
			if( !flags[i] && mps[now][i] != -1)
			{
				if( vec[i] == -1 || vec[i] > vec[now] + mps[now][i])
				{
					vec[i] = vec[now] + mps[now][i];
					ans[i] = ans[now] + lib[i];
				}
				else if( vec[i] == vec[now] + mps[now][i])
				{
					if( ans[i] < ans[now] + lib[i])
					{
						ans[i] = ans[now] + lib[i];
					}
				}
			}
		}
	}
}

void dfs2( int now, int dis, int dis_max, int ed, int n);
int dfs( int st, int ed, int n, int m)
{
	int cnt = 0;
	int dis = dijkstra( st, ed, n, m);	//Dij获得最短距离，以及最短路径所能获得的最多的救援队个数。

	memset( flags, 0, sizeof(flags));	//此处表示是否深搜是否访问过
	memset( vec, 0 ,sizeof( vec) );	//暂存最短路径个数 vec[ed]

	dfs2( st, 0, dis, ed, n);	//深搜统计最短路径个数。

	return vec[ed];
}

void dfs2( int now, int dis, int dis_max, int ed, int n)
{
//	printf("%d %d\n", now, dis);
	if( now == ed && dis <= dis_max)
	{
		vec[ed]++;
		return;
	}

	flags[now] = true;

	for(int i = 0; i < n; ++i)
	{
		if( !flags[i] && mps[now][i] != -1 && dis + mps[now][i] <= dis_max)
		{
			dfs2( i, dis + mps[now][i], dis_max, ed, n);
		}
	}

	flags[now] = false;
}

int main()
{
	int n, m, st, ed;
	int a, b, c;
	memset( mps, -1, sizeof( mps ) );
	memset( dis, -1, sizeof( dis ) );
	scanf("%d%d%d%d", &n, &m, &st, &ed);

	for(int i = 0; i < n; ++i)
		scanf("%d", lib + i);

	for(int i = 0; i < m; ++i)
	{
		scanf("%d%d%d", &a, &b, &c);
		if( mps[a][b] == -1)
			mps[a][b] = mps[b][a] = c;
		else
			mps[a][b] = mps[b][a] = MIN(mps[a][b], c);
	}

	a = dfs( st, ed, n, m);
	b = ans[ed];

	printf("%d %d\n", a, b);

	return 0;
}
