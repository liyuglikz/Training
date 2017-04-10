#include <bits/stdc++.h>

using namespace std;
const int MAXN = 2e5 + 5;
typedef long long int ll;
ll lib[MAXN];

void solve()
{
	ll cnt = 1;
	ll n, c;
	cin >> n >> c;
	for(int i = 0; i < n; ++i)
		scanf("%lld", lib + i);
	sort( lib, lib + n );
	for(int i = 1; i < n; ++i)
	{
		if( lib[i] - lib[i - 1] <= c)
			++cnt;
		else
			cnt = 1;
	}
	cout << cnt << endl;
}

int main()
{
	solve();
	return 0;
}
