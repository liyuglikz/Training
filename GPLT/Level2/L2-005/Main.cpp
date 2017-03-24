#include <bits/stdc++.h>

#define EX(a, b) (a = a ^ b, b = a ^ b, a = a ^ b)
using namespace std;
const int MAXN = 55;
typedef pair<int, int> Point;
typedef pair<Point, int> ans_node;

class node
{
	public:
		int len;
		set<int> s;
};

node lib[MAXN];
int mps0[MAXN][MAXN];
int mps1[MAXN][MAXN];

map<int, vector<int> > mps;

set<int> buff;
set<int> :: iterator it1;
set<int> :: iterator it2;

void init()
{
	memset( mps1, 0, sizeof( mps1 ) );
	memset( mps0, 0, sizeof( mps0 ) );
}

void deal(int n)
{
	for(int i = 1; i <= n; ++i)
	{
		for( it1 = lib[i].s.begin(); it1 != lib[i].s.end(); ++it1)
		{
			if( mps.end() == mps.find( *it1 ))
			{
				vector<int> now;
				now.push_back( i );
				mps.insert( pair<int, vector<int> > (*it1, now) );
			}
			else
			{
				mps[ *it1 ].push_back( i );
			}
		}
	}

	map<int, vector<int> > :: iterator it;
	for(it = mps.begin(); it != mps.end(); ++it)
	{
		int len = it->second.size();

		for(int i = 0; i < len; ++i)
		{
			for(int j = i + 1; j < len; ++j)
			{
				++mps1[ it->second[i] ][ it->second[j] ];
				++mps1[ it->second[j] ][ it->second[i] ];
			}
		}
	}

	for(int i = 1; i < n; ++i)
	{
		for(int j = i + 1; j <= n; ++j)
		{
			mps0[j][i] = mps0[i][j] = lib[i].s.size() + lib[j].s.size() - mps1[i][j];
		}
	}
}

void show(int n)
{
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
			printf("%d", mps1[i][j]);
		printf("\n");
	}
	
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
			printf("%d", mps0[i][j]);
		printf("\n");
	}
}


void solve()
{
	init();

	int n, k, a, b;
	scanf("%d", &n);

	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &lib[i].len);
		for( int j = 0; j < lib[i].len; ++j)
		{
			scanf("%d", &b);
			lib[i].s.insert( b );
		}
	}

	deal( n );
//	show( n );
	
	double ans = 0;
	scanf("%d", &k);

	for(int i = 0; i < k; ++i)
	{
		scanf("%d%d", &a, &b);
		if( a > b )
			EX(a, b);
		if( a != b)
			ans = 100.0 * (mps1[a][b] / (double)mps0[a][b]);
		else
			ans = 100.0;
		printf("%.2f%%\n", ans);
	}
}

int main()
{
	solve();
	return 0;
}
