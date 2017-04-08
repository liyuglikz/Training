#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;
const int N = 26;

char s[MAXN];
int lib[MAXN];

set<char> A;
set<char> B;
set<char> B_pos;

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

			A.insert( s[i] );
			lib[0] = lib[0] | (1 << (s[i] - 'A'));
		}
		else
			B_pos.insert( i );
	}

	for(int i = 0; i < N; ++i)
	{
		if( lib[0] ^ (1 << i) )
			B.insert( 'A' + i );
	}

	int j;
	for(int i = 0; i < len - N - 1; ++i)
	{
		j = i + 1;
		if( s[i + N] != '?' && s[i] != '?')
		{
			if( s[i + N] != s[i])
			{
				puts("-1");
				return;
			}
		}
		else if( s[i + N] == '?' && s[i] != '?')
		{
			s[i + N] = s[i];
		}
		else if( s[i + N] != '?' && s[i] == '?')
		{
			s[i] = s[i + N];	
		}
		else if( s[i + N] == '?' && s[i] == '?')
		{
		}
	}
	puts(s);
}

int main()
{
	solve();
	return 0;
}
