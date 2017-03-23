#include <bits/stdc++.h>

using namespace std;

int rget(int a, int b)
{
	return rand() % (b - a) + a;
}

int main()
{
	srand( (unsigned int) time(NULL));

	int n = 500;
	int m = (n * (n - 1)) >> 1;
	int src = 0;
	int des = n - 1;

	printf("%d %d %d %d\n", n, m, src, des);
	for(int i = 0; i < n; ++i)
		printf("%d ", rget(1, 50));
	puts("");

	for(int i = 0; i < m; ++i)
	{
		printf("%d %d %d\n", rget(0, n), rget(0, n), rget(1, 10));
	}

	return 0;
}
