#include <iostream>
#include <algorithm>
#include <string>

#include <vector>
#include <set>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
const int MAXN = 1e5 + 5;
typedef pair<char, char> Point;
Point lib[1005];

vector<int> mps[MAXN];
set<int> s;
int father[MAXN];

int n;

char s[32];

////
int getfather( int x )
{
	if( x != father[x])
		father[x] = getfather( father[x] );
	return father[x];
}

void merge( int x, int y)
{
	int x_r = getfather(x);
	int y_r = getfather(y);

	if( x_r != y_r)
		father[y_r] = x_r;
}

void init()
{
	s.clear();
	for(int i = 0; i <= 1000; ++i)
		mps[i].clear();
}

void solve()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);

		for(int i = 1; i <= n; ++i)
		{
			scanf("%s", s);
			lib[i].first = s[0];
			lib[i].second = s[ strlen(s) - 1];
		}

		for(int i = 1; i < n; ++i)
		{
			for(int j = i + 1; j <= n; ++j)
			{
				if( lib[i].first == lib[j].second)
				{
					mps[i].push_back( j );
					mps[j].push_back( i );
				}
			}
		}
	}
}

int main()
{
	solve();
	return 0;
}
