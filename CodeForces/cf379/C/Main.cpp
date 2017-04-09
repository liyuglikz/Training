#include <bits/stdc++.h>

using namespace std;
const int MAXN = 3e5 + 5;
typedef pair<int, int> Point;

int lib[MAXN];

Point mps[MAXN];

bool cmp( const Point &a, const Point &b)
{
	if( a.first != b.first)
		return a.first < b.first;
	return a.second < b.second;
}

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

	sort( mps, mps + n, cmp);

	int now = lib[0].first;

	for(int i = 1; i < n; ++i)
	{
		if( lib[i].first == lib[i - 1].first)
		{
			if( now > lib[i].first)
				++now;
			lib[i].first = now;
		}
		++now;
	}

	for(int i = 0; i < n; ++i)
		lib[ mps[i].second ] = mps[i].first;

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
