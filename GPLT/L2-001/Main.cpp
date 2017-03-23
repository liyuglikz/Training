#include <bits/stdc++.h>

using namespace std;
#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)

const int MAXN = 505;
const int INF = 0x7fffffff;

int mps[MAXN][MAXN];
int path[MAXN];
int lib[MAXN];
int val[MAXN];

int n, m;
int source, destination;

bool flags[MAXN];

int dij()
{
	for(int i = 0; i < n; ++i)
	{
		path[i] = mps[source][i];
		if( mps[source][i] != -1)
			val[i] = lib[source] + lib[i];
	}

	flags[ source ] = true;
	val[ source ] = lib[ source ];

	for(int i = 0; i < n; ++i)
	{
		int tmp = INF, val_now = 0;
		int now = 0;

		for(int j = 0; j < n; ++j)
		{
			if( !flags[j] && path[j] != -1 && tmp >= path[j])
			{
				if( tmp == path[j] && val_now > val[ tmp ])
					;
				else
				{
					tmp = path[j];
					val_now = val[j];
					now = j;
				}
			}
		}

		flags[ now ] = true;

		for(int j = 0; j < n; ++j)
		{
			if( !flags[j] && path[j] != -1 && mps[now][j] != -1)
			{
//				path[j] = MIN( path[j], path[now] + mps[now][j]);

				if( tmp + mps[now][j] >= path[j] )
				{
					if( tmp + mps[now][j] == path[j] && val_now < val[j])
						;
					path[j]  = tmp + mps[now][j];
					val[j] = val_now + lib[j];
				}

			}
			else if( !flags[j] && path[j] == -1 && mps[now][j] != -1)
			{
				path[j] = path[now] + mps[now][j];
				val[j] = val_now + lib[j];
			}
		}
	}

	return path[ destination ];
}


int ans;
/*
void dfs(int now, int t, int sum)
{
//	printf("%d %d %d\n", now, t, sum);
	if( flags[now] || t < 0)
		return;
	if( now == destination)
	{
		ans = MAX(ans, sum);
		return;
	}

	flags[now] = true;
	for(int i = 0; i < n; ++i)
	{
		if( !flags[i] && mps[now][i] != -1)
		{
			dfs( i, t - mps[now][i], sum + lib[i]);
		}
	}
	flags[now] = false;
}
*/

void solve()
{

	memset( mps, -1, sizeof(mps) );
	memset( path, -1, sizeof(path));

	int a, b, c;
	scanf("%d%d", &n, &m);
	scanf("%d%d", &source, &destination);

	for(int i = 0; i < n; ++i)
		scanf("%d", lib + i);

	for(int i = 0 ; i < m; ++i)
	{
		scanf("%d%d%d", &a, &b, &c);
		mps[a][b] = mps[b][a] = c;
	}

	int mini_dis = dij();		

	printf("%d %d\n", mini_dis, val[destination]);
}

int main()
{
	solve();
	return 0;
}
