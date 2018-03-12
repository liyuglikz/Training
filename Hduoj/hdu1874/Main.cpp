#include <bits/stdc++.h>

using namespace std;

const int MAXN = 205;
const int INF = 0x7fffffff;

int mps[MAXN][MAXN];
int vec[MAXN];
bool flags[MAXN];

#define MIN(a, b) (a < b ? a : b)


int dijkstra(int a, int b, int n, int m)
{
	memset( vec, -1, sizeof( vec ) );
	memset( flags, 0, sizeof(flags) );
	vec[a] = 0;
	flags[a] = true;

	for(int i = 0; i < n; ++i)
	{
		if( mps[a][i] != -1)
		{
			vec[i] = mps[a][i];
		}
	}

	while( 1 )
	{
		int now = -1;
		int next = INF;

		for(int i = 0; i < n; ++i)
		{
			if(i != a && !flags[ i ] && vec[i] != -1)
			{
				if( ( now == -1) || ( now != -1 && vec[i] < vec[now] ) )
					now = i;
			}
		}

		if(now == -1 )
			return vec[b];
		flags[now] = true;

		for(int i = 0; i < n; ++i)
		{
			if( i != a && i != now  && !flags[i] && mps[now][i] != -1)
//			if( !flags[i] && mps[now][i] != -1)
			{
				if(( vec[i] == -1) || ( vec[i] != -1 && vec[now] + mps[now][i] < vec[i]))
					vec[i] = vec[now] + mps[now][i];
			}
		}

	}
}

int main()
{
	int n, m, a, b, c;
	int t;

	while( scanf("%d%d", &n, &m) == 2)	// n points with m roads
	{
		memset( mps, -1, sizeof(mps));
		for(int i = 0; i < m; ++i)
		{
			scanf("%d%d%d", &a, &b, &c);
			//有重边，则去除重边
			if( mps[a][b] == -1)
		   	     mps[a][b] = mps[b][a] = c;
			else
				mps[a][b] = mps[b][a] = MIN( mps[a][b], c);
		}

		scanf("%d%d", &a, &b);
		printf("%d\n", dijkstra(a, b, n, m) );
	}

	return 0;
}
