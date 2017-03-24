#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1005;

class Point
{
	public:
		double cnt, pri, val;
};

bool cmp( const Point &a, const Point &b)
{
	if( a.val != b.val)
		return a.val > b.val;
	return a.cnt < b.cnt;
}

Point lib[MAXN];

void solve()
{
	int n, m;
	double ans = 0;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf("%lf", &lib[i].cnt);
	for(int i = 0; i < n; ++i)
		scanf("%lf", &lib[i].pri);
	for(int i = 0; i < n; ++i)
		lib[i].val = lib[i].pri / lib[i].cnt;

	sort( lib, lib + n, cmp);

	for(int i = 0; i < n && m > 0; ++i)
	{
		if( m > lib[i].cnt )
		{
			ans += lib[i].pri;
			m -= lib[i].cnt;
		}
		else
		{
			ans += lib[i].val * m;
			break;
		}
	}
	printf("%.2f\n", ans);
}

int main()
{
	solve();
	return 0;
}
