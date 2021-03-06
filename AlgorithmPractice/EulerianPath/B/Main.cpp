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
const int MAXM = 1e3 + 5;

vector<int> mps_out[30];
vector<int> mps_in[30];

char s[MAXM];

int n;
int a, b;

int father[MAXN];
set<int> st;

int getFather( int x )
{
	if( x != father[x])
		return (father[x] = getFather( father[x] ) );
}

void merge( int x, int y)
{
	int rx = getFather(x);
	int ry = getFather(y);
	if( rx != ry)
		father[ry] = rx;
}

void init()
{
	for(int i = 0; i <= 'z'; ++i)
	{
		mps_in[i].clear();
		mps_out[i].clear();
	}
	st.clear();
	memset( father, -1, sizeof( father ));
}

void input()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%s", s);
		a = s[0] - 'a';
		b = s[ strlen(s) - 1 ] - 'a';

		if( father[a] == -1)
			father[a] = a;

		if( father[b] == -1)
			father[b] = b;
		mps_out[a].push_back( b );
		mps_in [b].push_back( a );
		merge(a, b);
	}
}

void mss()
{
	for(int i = 0; i <= 'z'; ++i)
	{
		if( father[i] != -1)
		{
			getFather( i );
			st.insert( father[i] );
		}
	}

	if( st.size() > 1)
	{
		puts("The door cannot be opened.");
		continue;
	}
}

void judge_degree()
{
	for(int i = 0; i <= 'z' && ans; ++i)
	{
		if( father[i] != -1)
		{
			if( mps_out[ i ].size() != mps_in[i].size())
			{
				if( mps_out[i].size() - mps_in[i].size() == 1)
					++a;
				else if( mps_out[i].size() - mps_in[i].size() == -1)
					++b;
				else
					ans = 0;
			}
		}
	}
}

bool judge()
{
	mss();
	judge_degree();
	a = b = 0;
	int ans = 1;

	if(a > 1 || b > 1)
		ans = 0;

	return ans == 1;
}

void dfs(int now)
{
}

void solve()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		init();
		input();
		int ans = judge();
		if( !ans )
			puts("***");

	}
}

int main()
{
	solve();
	return 0;
}
