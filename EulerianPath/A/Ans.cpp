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
typedef long long int ll;
Point lib[1005];

vector<int> mps[MAXN];

int n;
ll cnt;

char s[32];
int father[MAXN];
set<int> st;

int getf(int x)
{
	if( x != father[x])
		return (father[x] =  getf( father[x] ));
}

void merge(int x, int y) // x <- y
{
	int xr = getf( x );
	int yr = getf( y );
	if( xr != yr)
		father[yr] = xr;
}

void init()
{
	cnt = 0;
	st.clear();
	for(int i = 0; i <= 1000; ++i)
		mps[i].clear();
}

void solve()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		init();
		scanf("%d", &n);

		for(int i = 1; i <= n; ++i)
		{
			scanf("%s", s);
			lib[i].first = s[0];
			lib[i].second = s[ strlen(s) - 1];
		}

		for(int i = 1; i < n; ++i)
		{
			for(int j = 1; j <= n; ++j)
			{
				if( lib[i].first == lib[j].second)
				{
					mps[i].push_back( j );
					merge( i, j);
				}
			}
		}

		for(int i = 1; i <= n; ++i)
		{
			getf( i );
			st.insert( father[i] );
		}

		if( st.size() > 1)
		{
			puts("The door cannot be opened.");
			continue;
		}

		for(int i = 1; i <= n; ++i)
			cnt += mps[i].size();

		if( cnt <= 0 || cnt & 1 )
			puts("The door cannot be opened.");
		else
			puts("Ordering is possible.");
	}
}

int main()
{
	solve();
	return 0;
}
