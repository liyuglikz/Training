#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 1e5 + 5;
char s[MAXN];
int ans = 0;

void input()
{
	scanf("%s", s);
}

void solve()
{
	int len = strlen ( s );
	bool flag = true;
	for( char *p = s; *p; ++p)
	{
		if( *p == 'V' && *(p + 1) == 'K')
		{
			++ans;
			*p = 0;
			*(p + 1) = 0;
			p++;
		}
	}

	for(int i = 0; i < len; ++i)
	{
		if( s[i] && s[i + 1] && s[i] == s[i + 1])
		{
			++ans;
			return;
		}
	}
}

void output()
{
	printf("%d\n", ans);
}


int main()
{
	input();
	solve();
	output();

	return 0;
}
