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
			int d = len - 1 - c;
			if( a == 0)
			{
				return a == d;
			}
			else
			{
				if( a )
				{
//					printf("%d %d %d\n", (d % a), (d % b), (d - a) / b);
					return (d % a == 0) && (d % b == 0) && ((d - a) / b == a);
				}
				else
					return d == 0;
			}
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
