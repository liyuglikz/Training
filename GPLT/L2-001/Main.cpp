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
int fath[MAXN];

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
		if( flags[now] )
			continue;

		flags[ now ] = true;

		for(int j = 0; j < n; ++j)
		{
			if( !flags[j] && j != now && path[j] != -1 && mps[now][j] != -1)
			{
				if( tmp + mps[now][j] <= path[j] )
				{
					//bug final: val_now + lib[i] < val[j]; >.<;
					if( tmp + mps[now][j] == path[j] && val_now + lib[j] < val[j])
						continue;

					path[j] = tmp + mps[now][j];
					val[j] = val_now + lib[j];

					fath[j] = now;
				}
			}
			else if( !flags[j] &&  mps[now][j] != -1)
			{
				path[j] = path[now] + mps[now][j];
				val [j] = val_now + lib[j];

				fath[j] = now;
			}
		}
	}

	return path[ destination ];
}


int ans;
stack<int> answer;

void dfs( int now, int t)
{
//	printf("%d %d\n", now, t);
	if( now == destination && t == 0)
	{
		++ans;
		return;
	}

	for(int i = 0; i < n; ++i)
	{
		if( !flags[i] && mps[now][i] != -1 && t - mps[now][i] >= 0)
		{
			flags[i] = true;	
			dfs( i, t - mps[now][i]);
			flags[i] = false;
		}
	}
}

void solve()
{

	memset( fath,-1, sizeof(fath));
	memset( path,-1, sizeof(path));
	memset( mps, -1, sizeof(mps) );

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

	memset( flags, 0, sizeof(flags));
	flags[ source ] = true;
	dfs( source, mini_dis);

	printf("%d %d\n", ans, val[destination]);

	for(int i = destination; i != -1; i = fath[i])
	{
//		printf("->%d", i);
		answer.push( i );
	}
	printf("%d", source);
	while( !answer.empty())
	{
		printf(" %d", answer.top());
		answer.pop();
	}
	printf("\n");
}

int main()
{
	solve();
	return 0;
}
