#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;
char s[MAXN];

int i, j, k;
int a, b, c;

bool judge( char s[] )
{
	char *p = s;
	int len = strlen( s );
	i = j = k = 0;
	a = b = c = 0;

	while( *p)
	{
		switch( *p )
		{
			case 'P': ++i; a = p - s;break;
			case 'A': ++j; break;
			case 'T': ++k; c = p - s;break;
			default: break;		 
		}
		++p;
	}

	if( i != 1 || k != 1 || k + i + j != len )
		return false;

	if( a <= c - 2)
	{
		if( a == c - 2)
		{
			return a == len - c - 1;
		}
		else
		{
			b = c - a - 2;
			return (len - 1 - c - a >= 0) && ( b == 0 || a % b == 0);
		}
	}
	else
	{
		return false;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	while( n-- )
	{
		scanf("%s", s);
		printf("%s\n", (judge( s ) ? "YES" : "NO"));
	}
	return 0;
}
