#include <bits/stdc++.h>
const int INF = 0x7fffffff;
const int MAXN = 1e5;
using namespace std;

int rget( int a, int b)
{
	return (rand() % (b - a)) + a;
}

void solve()
{
	int T = 10;
	cout << T << endl;;
	while( T-- )
	{
		int n = rget(5, MAXN);
		int m = rget(1, 10);
		printf("%d %d\n", n, m);
		while(n--)
			printf("%d ", rget( 0, INF));
		printf("\n");
		while(m--)
			printf("%d ", rget( 0, INF));
		printf("\n");
	}
}


int main()
{
	srand( (unsigned int) time(NULL));
	solve();
	return 0;
}
