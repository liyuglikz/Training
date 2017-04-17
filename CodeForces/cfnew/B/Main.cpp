#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> Point;
const int MAXN = 1e6 + 5;
const int INF = 0x7fffffff;

int lib[MAXN];
bool flags[MAXN];
Point ops[MAXN];

int n, m, k, num;
int ans;

void input()
{
	cin >> n >> m >> k;
	for(int i = 0; i < m; ++i)
	{
		scanf("%d", &num);
		flags[num] = true;
	}

	for(int i = 0; i < k; ++i)
		scanf("%d%d", &ops[i].first, &ops[i].second);
}

void output()
{
	printf("%d\n", ans);
}

void solve()
{
	bool flag = true;;
	ans = 1;
	for(int i = 0; i < k; ++i)
	{
		if( flags[ans] )
			return;
		if( ans == ops[i].first)
			ans = ops[i].second;
		else if( ans == ops[i].second)
			ans = ops[i].first;
	}
}

int main()
{
	input();
	solve();
	output();
	return 0;
}
