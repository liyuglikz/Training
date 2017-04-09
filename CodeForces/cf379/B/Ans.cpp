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

	scanf("%d", &n);

	for(int i = 0; i < n; ++i)
		scanf("%d", lib + i);

	for(int i = 0; i < n - 1; ++i)
	{
		if( lib[i] )
		{
			while( lib[ i ] > 1)
			{
				ans[len++] = 'P';
				--lib[i];
				ans[len++] = 'R';

				if( lib[i + 1] )
				{
					ans[len++] = 'P';
					-- lib[i + 1];
				}

				ans[len++] = 'L';
			}
			--lib[i];	
			ans[len++] = 'P';
		}
		ans[len++] = 'R';
	}

	while( lib[ n - 1 ] > 1)
	{
		-- lib[n - 1];
		ans[len++] = 'P';
		ans[len++] = 'L';
		ans[len++] = 'R';
	}
	ans[len++] = 'P';

	puts( ans );
}

int main()
{
	solve();
	return 0;
}
