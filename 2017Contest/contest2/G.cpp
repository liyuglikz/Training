#include <iostream>
#include <algorithm>
#include <string>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <stack>
#include <set>

using namespace std;
const int MAXN = 1e6 + 1;

class node
{
public:
	int p, t, x;

	bool friend operator < ( const node &a, const node &b)
	{	return a.p > b.p; }
	bool friend operator == (const node &a, const node &b)
	{	return a.p == b.p;}
};

class node2
{
public:
	int l, r, x;
	bool friend operator < (const node2 &a, const node2 &b)
	{	return a.l > b.l;}
};

set<node> s1;
set<int> s2;

set<node2> s3;

set<node> :: iterator it;
set<int> :: iterator it1;

void solve()
{
	int n, p, m;

	scanf("%d", &n);

	node now;

	for(int i = 0; i < n; ++i)
	{
		scanf("%d%d", &now.p, &now.t);
		if(now.t)
		{
			scanf("%d", &now.x);
			it1 = s2.upper_bound( now.p );

			if( it1 != s2.end() )
				s2.erase ( it1 );
			else
				s1.insert(  now );
		}
		else
		{
			it = s1.upper_bound( now );

			if( it != s1.end() )
				s1.erase ( it );
			else
				s2.insert( now.p );
		}

		if(s1.empty())
			printf("-1\n");
		else
			printf("%d\n", s1.begin() -> x);
	}
}

int main()
{
	solve();
	return 0;
}
