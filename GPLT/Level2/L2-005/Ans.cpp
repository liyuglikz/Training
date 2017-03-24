#include <bits/stdc++.h>

#define EX(a, b) (a = a ^ b, b = a ^ b, a = a ^ b)
using namespace std;
const int MAXN = 50;
typedef pair<int, int> Point;
typedef pair<Point, int> ans_node;

class node
{
	public:
		int len;
		set<int> s;
};

node lib[MAXN];
map<Point, int> mps0;
map<Point, int> mps1;

set<int> buff;
set<int> :: iterator it1;
set<int> :: iterator it2;

void solve()
{
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

	
	double ans = 0;
	scanf("%d", &k);
	for(int i = 0; i < k; ++i)
	{
		scanf("%d%d", &a, &b);

		if(a > b)
			EX(a, b);

		if( mps0.end() == mps0.find( Point(a, b) ))
		{
			buff.clear();
			for( it1 = lib[a].s.begin(); it1 != lib[a].s.end(); ++it1)
				buff.insert( *it1 );

			for( it1 = lib[b].s.begin(); it1 != lib[b].s.end(); ++it1)
				buff.insert( *it1 );

			mps0.insert( ans_node( Point(a, b), buff.size()) );
		}

		if( mps1.end() == mps1.find( Point(a, b) ))
		{
			int cache = 0;
			for( it1 = lib[a].s.begin(); it1 != lib[a].s.end(); ++it1)
			{
				if( lib[b].s.end() != lib[b].s.find( *it1 ) )
					++cache;
			}
			mps1.insert( ans_node( Point(a, b), cache) );
		}


		ans = 100.0 * (mps1[ Point(a, b ) ] / (double)mps0[ Point(a, b) ]);
		printf("%.2f%%\n", ans);
	}
}

int main()
{
	solve();
	return 0;
}
