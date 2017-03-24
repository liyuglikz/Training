#include <bits/stdc++.h>

using namespace std;

const int MAXN = 64;
int a[MAXN];
int b[MAXN];
int c[MAXN];

vector<int> ans[MAXN];

void output( int d, int cnt)
{
	for(int i = 0; i <= cnt; ++i)
		printf("==");
	printf("> %d\n", d);
}

void build( int l, int r, int L, int R, int cnt)
{
//	printf("%d %d %d %d  %d %d\n", l, r, L, R, cnt, a[r]);
	if( l > r || L > R)
		return;
	else if( l == r || L == R)
	{
		ans[cnt].push_back( a[r] );
//		output( a[r], cnt);
		return;
	}
	ans[cnt].push_back( a[r] );
	int root = a[r];
	int pos = c[ root ];
	int dis = R - pos;

//	printf("***** %d\n", root);
//	output( a[r], cnt );
	
	build( l, r - dis - 1, L, pos - 1, cnt + 1);
	build( r - dis, r - 1, pos + 1, R, cnt + 1);
}

void solve()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	for(int i = 1; i <= n; ++i)
		scanf("%d", b + i);
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			if( b[j] == a[i])
			{
				c[ a[i] ] = j;
				break;
			}
		}
//		printf(" %d, %d\n", c[ a[i] ], a[i]);
	}

	build( 1, n, 1, n, 0);

	vector<int> :: iterator it;
	bool flag = false;
	for(int i = 0; i < MAXN; ++i)
	{
		if( ans[i].empty() )
			break;
		for( it = ans[i].begin(); it != ans[i].end(); ++it)
		{
			if( flag )
				putchar(' ');
			else
				flag = true;
			printf("%d", *it);
		}
	}
	printf("\n");
}

int main()
{
	solve();
	return 0;
}
