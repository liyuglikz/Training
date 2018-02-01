#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, a, b, c;
	scanf("%d", &n);
	a = (n / 100) % 10;
	b = (n / 10) % 10;
	c = n % 10;
	while(a--)
		printf("B");
	while(b--)
		printf("S");
	for(int i = 1; i <= c; ++i)
		printf("%d", i);
	printf("\n");
	return 0;
}
