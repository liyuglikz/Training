#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5 + 5;
const int MAXM = MAXN << 2;

int lib[MAXN];
char ans[MAXM];

void solve()
{
	int n;
	int len = 0;
	int cnt = 0;

	scanf("%d", &n);

	for(int i = 0; i < n; ++i)
	{
		scanf("%d", lib + i);
		cnt += lib[i];
	}

	int now = 0;
	int dir = 1;

	while( cnt )
	{
		now += dir;

		if( dir == 1)
			ans[len++] = 'R';
		else if(dir == -1)
			ans[len++] = 'L';

		if( lib[now] )
		{
			ans[len++] = 'P';
			--lib[now];
			--cnt;
		}

		if( now == n - 1)
			dir = -1;
		else if(now == 0)
			dir = 1;
	}

	puts( ans );
}

int main()
{
	solve();
	return 0;
}
