#include <bits/stdc++.h>

using namespace std;
char ans[20];

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	a += b;
	char *s = ans;

	b = 0;
	if(a < 0)
	{
		putchar('-');
		a = -a;
	}
	else if( a == 0)
	{
		printf("0\n");
		return 0;
	}

	while( a )
	{
		if( b == 3)
		{
			*s++ = ',';
			b = 0;
		}
		*s++ = (a % 10) + '0';
		a /= 10;
		++b;
	}

	while( s != ans )
	{
		--s;
		putchar(*s);
	}
	printf("\n");
	return 0;
}
