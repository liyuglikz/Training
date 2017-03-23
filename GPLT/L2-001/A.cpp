#include <bits/stdc++.h>

using namespace std;

const int MAXN = 505;
const int INF = 0x7fffffff;

class node
{
	public:
		int index, distance, val;
		bool operator < (const node &k) const
		{
			if( this->distance != k.distance )
				return this->distance < k.distance;
			return this->val > k.val;
		}
};

int n, m;
int source, destination;
int lib[MAXN];
int mps[MAXN][MAXN];

int path[MAXN];
int weight[MAXN];

bool flags[MAXN];

priority_queue< node > que;

void dij()
{
	for(int i = 0; i < n; ++i)
		path[i] = INF;
//	flags[ source ] = true;
	path[ source ] = 0;
	node now;
	node next;

	now.index = source;
	now.distance = 0;
	now.val = lib[ source ];

	que.push( now );

	int u;

	for(int i = 0; i < n; ++i)
	{
		now = que.top();
		que.pop();

		u = now.index;
		if( flags[ u ])
			continue;
//		printf("> %d : %d\n", i, u);

		for(int j = 0; j < n; ++j)
		{
			if( !flags[j] && j != u)
			{
				if( path[j] > path[j] + mps[j][u])
				{
					path[j] = path[u] + mps[j][u];
					weight[j] = now.val + lib[j];

					next.index = j;
					next.distance = path[j];
					next.val = now.val + lib[j];
					que.push( next );
				}
			}
		}
	}
}

void solve()
{
	memset( mps, -1, sizeof( mps ));

	int a, b, c;
	scanf("%d%d", &n, &m);
	scanf("%d%d", &source, &destination);

	for(int i = 0; i < n; ++i)
		scanf("%d", lib + i);

	for(int i = 0; i < m; ++i)
	{
		scanf("%d%d%d", &a, &b, &c);
		mps[a][b] = mps[b][a] = c;
	}

	dij();

	printf("%d %d\n", path[ destination ], weight[ destination ]);
}

int main()
{
	solve();
	return 0;
}
