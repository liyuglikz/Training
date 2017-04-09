#include <bits/stdc++.h>

using namespace std;
const int MAXN = 3e5 + 5;

int lib[MAXN];
set<int> st;
set<int> flags;
set<int> :: iterator it;

void solve()
{
	int n, k;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", lib + i);
		st.insert( lib[i] );
	}

	for(int i = 0; i < n; ++i)
	{
		k = lib[i];

		if( flags.find(k) == flags.end() )
		{
			flags.insert( k );
		}
		else
		{
			it = st.lower_bound( k );
			k = *it;
			while( st.end() != st.find( k ) )
				++k;
			st.insert( k );
			flags.insert( k );
			lib[i] = k;
		}
	}

	for(int i = 0; i < n; ++i)
	{
//		if( i )
//			putchar (' ');
		printf("%d\n", lib[i]);
	}
	printf("\n");
}

int main()
{
	solve();
	return 0;
}
