#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int MAXN = 1e3 + 5;
vector<int> mps[MAXN];
vector<int> :: iterator it;

bool cities[MAXN];
bool flags[MAXN];

template<class T>
class Queue
{
public:
	const static int MAXQ = 1e5 + 5;
	T que[MAXQ];
	int f, r;

	explicit Queue() : f(0), r(0)
	{}

	bool empty()
	{		return f == r;}

	bool full()
	{
		return (r - f + MAXQ) % MAXQ == MAXQ - 1;
	}

	void push( T k )
	{
		que[ r++ ] = k;
		r %= MAXQ;
	}

	T front()
	{	return que[f];}

	void pop()
	{	f = (f + 1) % MAXQ;}

};//手写队列（卡时间）

Queue<int> que;
void bfs( int root )
{
	que.push(root);
	while( !que.empty())
	{
		root = que.front();		
		que.pop();
		flags[ root ] = true;
		for( it = mps[ root ].begin(); it != mps[root].end(); ++it)
		{
			if( !flags[ *it ])
				que.push( *it );
		}
	}
}

int count(int n)
{
	int ans = 0;

	for(int i = 1; i <= n; ++i)
	{
		if( !flags[i] )
		{
			++ans;
			bfs( i );
		}
	}
	return ans;
}

int main()
{
	int a, b;
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	for(int i = 0; i < m; ++i)
	{
		scanf("%d%d", &a, &b);
		mps[a].push_back( b );
		mps[b].push_back( a );
	}	// init the map

	while (k--)
	{
		scanf("%d", &a);
		memset( flags, 0, sizeof(flags));
		flags[a] = true;
		b = count(n) - 1;
		printf("%d\n", (b >= 0 ? b : 0));
	}
	return 0;
}
