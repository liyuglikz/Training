#include <bits/stdc++.h>

using namespace std;

vector<int> lib;
const int MAXN = 1e5 + 5005;
bool prim[MAXN];

void init()
{
	for(int i = 2; i <= MAXN; ++i)
	{
		if( !prim[i] )
		for(int j = (i << 1); j <= MAXN; j += i)
		{
			prim[j] = true;	
		}
	}

	for(int i = 2; i < MAXN; ++i)
	{
		if( !prim[i] )
		lib.push_back( i );
	}
}

int main()
{
	init();
	int m, n, t(0);
	scanf("%d%d", &m, &n);
	for(int i = m - 1; i < n; ++i)
	{
		if( t )
			printf(" ");
		printf("%d", lib[i]);
		if( t == 9)
			printf("\n");
		t = (t + 1) % 10;
	}
	return 0;
}
