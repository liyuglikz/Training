#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;
const int INF = 0x7fffffff;

int lib[MAXN];
int n, ans;

void input()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", lib + i);	
}

void solve()
{
	sort( lib, lib + n );
	ans = 0;

	int i, j;
	for(i = n - 1; i >= 0 && lib[i] >= 0; --i )
	{
		ans += lib[i];
	}
	if( ans & 1 )
		return;

	int minileft = -INF;
	int miniright = INF;

	for( j = i + 1; j < n; ++j)
		if( lib[j] & 1)
		miniright = min( miniright, lib[j]);

	for( j = i; j >= 0; --j)
	{
		if( abs(lib[j]) & 1 )
		minileft = max(minileft, lib[j]);
	}

	if( minileft != -INF && miniright != INF)
		ans -= (min( abs( minileft ), miniright ) );
	else if( minileft != -INF)
		ans += minileft;
	else
		ans -= miniright;
}

void output()
{
	printf("%d\n", ans);
}

int main()
{
	input();
	solve();
	output();

	return 0;
}
