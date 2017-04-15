#include <iostream>
#include <algorithm>
#include <string>

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <cmath>
#include <map>
#include <set>
#include <vector>

using namespace std;
const int MAXN = 1e5 + 5;
vector<int> ans;

class Node
{
	public:
		int l, r, id;
		bool operator < (const Node &k) const
		{
			if( this->r != k.r)
				return this->r > k.r;
			return this->l > k.l;
		}
};

bool cmp(const Node &a, const Node &b)
{
	if( a.l != b.l)
		return a.l < b.l;
	return a.r < b.r;
}

Node lib[MAXN];
int n;

void input()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d%d", &lib[i].l, &lib[i].r);
		lib[i].id = i;
	}
	sort( lib, lib + n, cmp);
}

void output()
{
	sort( ans.begin(), ans.end());
	printf("%lu\n", ans.size());

	vector<int>::iterator it;
	for( it = ans.begin(); it != ans.end(); ++it)
	{
		if( it != ans.begin())
			putchar(' ');
		printf("%d", *it);
	}

	if( ans.size() )
		printf("\n");
	ans.clear();
}

map<Node, int> mps;
map<Node, int> :: iterator it;

typedef pair<Node, int> Point;

void debug_Node( Node k)
{
	printf("%d %d %d\n", k.id, k.l, k.r);
}

void debug_output()
{
	for( it = mps.begin(); it != mps.end(); ++it)
	{
		debug_Node( it->first );
	}
	puts("");
}

void solve()
{

//	for(int i = 0; i < n; ++i)
//		debug_Node( lib[i] );

	mps.clear();
	for(int i = 0; i < n; ++i)
	{
//		debug_output();
		while( !mps.empty() && mps.rbegin()->first.r < lib[i].l )
			mps.erase( mps.rbegin()->first);

		mps.insert( Point(lib[i], lib[i].id ) );

		if( mps.size() >= 3)
		{
			ans.push_back( mps.begin()->second + 1);
			mps.erase( mps.begin() );
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		input();
		solve();
		output();
	}

	return 0;
}
