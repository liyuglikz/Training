#include <bits/stdc++.h>

using namespace std;
const int MAXN = 3e5 + 5;
const int MAXM = 1e9 + 5;

int lib[MAXN];
set<int> st;
set<int> cur;
set<int> :: iterator it;
set<int> :: iterator it_c;

void solve()
{
	int n, k, cnt = 0;
	scanf("%d", &n);

	for(int i = 0; i < n; ++i)
	{
		scanf("%d", lib + i);
		cur.insert( lib[i] );
	}

	cnt = k = lib[0];
	for(int i = 1; i < n; ++i)
	{
		k = min(k, lib[i]);
		cnt = max( cnt, lib[i] );
	}

	for(int i = k + 1; i < cnt + n; ++i)
	{
		if( cur.end() == cur.find( i ) )
		{
			st.insert( i );
			--cnt;
		}
	}

	cur.clear();

	for(int i = 0; i < n; ++i)
	{
		if( cur.end() != cur.find( lib[i] ) )
		{
			it_c = st.upper_bound( lib[i] );
//			printf("%d %d\n",lib[i],  *it_c);
			lib[i] = *it_c;

//			st.erase (it_c);
			++it_c;
		}
		cur.insert( lib[i] );
	}

	for(int i = 0; i < n; ++i)
	{
		if( i )
			putchar(' ');
		printf("%d", lib[i]);
	}
	printf("\n");
}

int main()
{
	solve();
	return 0;
}
