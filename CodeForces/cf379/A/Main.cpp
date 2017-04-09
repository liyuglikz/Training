#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int a, b, ans = 0;
	scanf("%d%d", &a, &b);
	while( a >= b )
	{
		ans += b;
		a -= b;
		++a;
	}
	ans += a;
	printf("%d\n", ans);
}

int main()
{
	solve();
	return 0;
}
