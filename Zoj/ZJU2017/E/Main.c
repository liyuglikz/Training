#include <stdio.h>

int main()
{
	int n, i;
	int a = 1, b = 1;
	scanf("%d", &n);

	for(i = 3; i <= n; ++i)
	{
		b = a + b;
		a = b - a;
	}
	printf("%d\n", b);
	return 0;
}
