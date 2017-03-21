#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
const int MAXN = 1e2 + 2;

int s[MAXN][MAXN];
int ans[MAXN];

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int guess(int n, int m) // n x m
{
	for(int i = 1; i <= m; ++i)
	{
		int p = i;

		for(; p <= n; ++p)
		{
			if( s[p][i] )
				break;
		}

		for(int j = 1; j <= m; ++j)
			swap( s[p][j], s[i][j] );

		for(int j = i + 1; j <= n; ++j)
		{
			//cout << s[i][i] << " " << s[j][i] << endl;
			int num = lcm( s[i][i], s[j][i] );
			//cout << num << endl;
			for(int k = i; k <= m; ++k)
			{
				s[j][k] -= num;
			}
		}
	}


	if(s[n][m - 1] == 0 && s[n][m] != 0)
		return -1;

	for(int i = m - 1; i >= 1; --i)
	{
		int sum = 0;
		for(int j = i + 1; j < m; ++j)
			sum += s[i][j] * ans[j];

		ans[i] = (s[i][m] + sum) / s[i][i];
	}

	return 1;
}

int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= m; ++j)
				scanf("%d", &(s[i][j]));
		}

		if(guess(n, m) == 1)
		{
			for(int i = 1; i < m; ++i)
				printf(" %d", ans[i]);
			puts("");
		}
	}
	return 0;
}
