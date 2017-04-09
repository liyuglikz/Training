#include <bits/stdc++.h>

using namespace std;
const int MAXN = 3e5 + 5;
typedef pair<int, int> Point;

int lib[MAXN];

Point mps[MAXN];

void solve()
{
	int n, k, cnt;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", lib + i);
		mps[i].first = lib[i];
		mps[i].second = i;
	}

	k = 0;

	for(int i = 0; i < n; ++i)
	{
		if( i )
			putchar (' ');
		printf("%d", lib[i]);
	}
	printf("\n");
}

int main()
{
	solve();
	return 0;
}
