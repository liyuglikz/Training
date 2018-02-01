#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main()
{
	int n;
	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		ll A, B, C;
		scanf("%lld%lld%lld", &A, &B, &C);
		printf("Case #%d: %s\n", i, ((A + B > C) ? "true" : "false"));
	}

	return 0;
}
