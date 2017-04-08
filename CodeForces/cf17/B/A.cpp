#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;
const int N = 26;

char s[MAXN];
int lib[MAXN];

void solve()
{
	scanf("%s", s);
	int len = strlen( s );
	if( len < N )
	{
		puts("-1");
		return;
	}

	for(int i = 0; i < N; ++i)
	{
		if( s[i] != '?')
		{
			if( lib[0] & (1 << (s[i] - 'A')))
			{
				puts("-1");
				return;
			}
			lib[0] = lib[0] | (1 << (s[i] - 'A'));
		}
	}

	for(int i = 1; i < len - N; ++i)
	{
		if( s[i] != '?')
		{
			if( lib[i] & (1 << (s[i + N - 1] - 'A')))
			{
				puts("-1");
				return;
			}
			lib[i] = lib[i - 1] - (1 << (s[i] - 'A'));
			lib[i] = lib[i] | (1 << (s[i + N - 1] - 'A'));
		}
	}
}

int main()
{
	solve();
	return 0;
}
