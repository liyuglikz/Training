#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5 + 5;
bool flags[MAXN];
int cp[MAXN];
int ans[MAXN], answer[MAXN];

int main()
{
	int n, m, a, b;

	memset( cp, -1, sizeof(cp));
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d %d", &a, &b);
		cp[a] = b;
		cp[b] = a;
	}

	scanf("%d", &m);
	for(int i = 0; i < m; ++i)
	{
		scanf("%d", ans + i);
		flags[ ans[i] ] = true;
	}
	sort( ans, ans + m);

	for(int i = 0; i < m; ++i)
	{
		if( flags[ ans[i] ] && (cp[ans[i]] != -1) && flags[cp[ ans[i] ]])
		{
			flags[ ans[i] ] = 0;
			flags[ cp[ans[i]] ] = 0;
		}
	}

	int len = 0;
	for(int i = 0; i < m; ++i)
	{
		if( flags[ ans[i] ] )
		{
			answer[len++] = ans[i];
		}
	}
	printf("%d\n", len);
	for(int i = 0; i < len; ++i)
	{
		if( i )
			printf(" ");
		printf("%05d", answer[i]);
	}
	if( len )
	printf("\n");

	return 0;
}
