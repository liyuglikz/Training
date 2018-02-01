#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;
char s[MAXN];

int i, j, k;
int a, b, c;

bool judge2(int a, int b, int d)
{
	if( a == d && b == 0)
		return true;
	else if( a > d || b < 0)
		return false;
	return judge2( a, b - 1, d - a);
}

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
			int d = len - 1 - c;
			return judge2(a, b, d);
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
