#include <iostream>
#include <algorithm>
#include <string>

#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;


const int MAXN = 3e6 + 100;
char s[MAXN];
short int ans[MAXN];
int len = 0, len2 = 0;
int gate = (1 << 7) - 1;

void input()
{
	gets(s);
}

void solve()
{
	len2 = 0;
	len = strlen( s );

	int k = len;
	if( k == 0)
		ans[len2++] = 0;

	while( k )
	{
		ans[len2] = k & gate;
		k >>= 7;
		if( k )
			ans[len2] |= (1 << 7);
		++len2;
	}

	for(int i = 0; i < len; ++i)
		ans[i + len2] = (short int) s[i];
}

void output()
{
	for(int i = 0; i < len2; ++i)
		printf("%02X", ans[i]);

	for(int i = len2; i < len + len2; ++i)
		printf("%02X", ans[i]);
	printf("\n");
}


int main()
{
	int T;
	scanf("%d%0c", &T);
	while(T--)
	{
		input();
		solve();
		output();
	}
	return 0;
}
