#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5 + 5;

set<int> s;
set<int> :: iterator it1, it2;

int a[10];

void solve()
{
	s.clear();
	int n, k;

	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &k);
		s.insert( k );
	}

	bool ans = true;

	if(s.size() == 3)
	{
		int len = 0;
		it2 = it1 = s.begin();
		++it1;
		for( ; it1 != s.end(); ++it1, ++it2)
		{
			a[len++] = *it1 - *it2;
		}

		ans = ( a[0] == a[1] );
	}
	else if((s.size() == 2) || (s.size() == 1))
		ans = true;
	else
		ans = false;
	puts( ans ? "YES" : "NO");
}

int main()
{
	solve();
	return 0;
}
