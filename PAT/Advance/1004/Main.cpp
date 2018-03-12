#include <bits/stdc++.h>

using namespace std;
const int MAXN = 101;

int n, m;

bool flags[MAXN];
vector<int> mps[MAXN];
vector<int> ans;

queue<int> que;
void bfs(int root)	//改进BFS，要记录每层节点数，逐层遍历
{
	que.push( root );

	int cnt = 0;
	int flag = flags[root];	//flag表示当前层非叶子节点个数，根节点有孩子时，第一次个数为1
	int k = 0;

	if( !flags[ root ])	//特例，根节点无孩子
		++cnt;
	ans.push_back( cnt );

	while( !que.empty() && flag)
	{
		k = 0;
		cnt = 0;

		for(; flag > 0; --flag)	//对当前层所有节点进行BFS
		{
			root = que.front();
			que.pop();

			for( vector<int> :: iterator it = mps[root].begin(); it != mps[root].end(); ++it)
			{
				if( !flags[ *it ])
					++cnt;	//统计叶子
				else
				{
					que.push( *it );
					++k;	//统计每层的非叶子
				}
			}
		}
		ans.push_back( cnt );
		flag = k;
	}
}

int main()
{
	int id, k, t;
	scanf("%d%d", &n, &m);

	for(int i = 0; i < m; ++i)
	{
		scanf("%d%d", &id, &k);
		flags[ id ] = true;

		for(int j = 0; j < k; ++j)
		{
			scanf("%d", &t);
			mps[id].push_back( t );
		}
	}

	bfs( 1 );

	for( vector<int> :: iterator it = ans.begin(); it != ans.end(); ++it)
	{
		if( it != ans.begin() )
			printf(" ");
		printf("%d", *it);
	}
	printf("\n");

	return 0;
}
