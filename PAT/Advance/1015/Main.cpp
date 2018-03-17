#include <cstdio>
#include <cmath>

using namespace std;
const int MAXN = 1e5 + 5;

int s[MAXN];
int reverse( int n, int d)
{
	int len = 0;
	while ( n )
	{
		s[len++] = n % d;
		n /= d;
	}

	n = 0;
	for(int i = 0; i < len; ++i)
	{
		n *= d;
		n += s[i];
	}
	return n;
}

bool judge( int k )
{
	if( k== 1)//注意!!
		return false;
	else if( k == 2)
		return true;

	int t = sqrt( k );
	for(int i = 2; i <= t; ++i)
	{
		if( (k % i) == 0)
			return false;
	}
	return true;
}

int main()
{
	int n, d;
	while( scanf("%d%d", &n, &d) == 2 && (n >= 0))
	{
		if( judge( n ) )
		{
			int M = reverse( n, d);
			puts( (judge(M) ? "Yes" : "No") );
		}
		else
			puts("No");
	}
	return 0;
}
