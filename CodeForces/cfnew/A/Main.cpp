#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5 + 5;
const int INF = 0x7fffffff;
int lib[MAXN];

int n, m, k;
int ans;
void input()
{
	cin >> n >> m >> k;
	for(int i = 0; i < n; ++i)
		scanf("%d", lib + i);;
}

void output()
{
	printf("%d\n", ans * 10);
}

void solve()
{
	--m;
	ans = INF;
	for(int i = m - 1; i >= 0; --i)
	{
		if(lib[i] && lib[i] <= k )
			ans = min(ans, abs( i - m));
	}

	for(int i = m + 1; i < n; ++i)
		if(lib[i] && lib[i] <= k)
			ans = min (ans, abs(i - m) );
}

int main()
{
	input();
	solve();
	output();
	return 0;
}
