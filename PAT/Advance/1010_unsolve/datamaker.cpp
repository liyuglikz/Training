#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e9 + 5;

typedef long long int ll;

ll rget( ll a, ll b)
{
	return rand() % (b - a) + a;
}

int main()
{
	srand( (unsigned int) time(NULL));
	int T = 100;
	while ( T--)
	{
		ll k = rget(0, MAXN);
		printf("%llx %lld %lld %lld\n", k, k, rget(0, 2), rget(0, MAXN));
	}
	return 0;
}
