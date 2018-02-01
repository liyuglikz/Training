#include <bits/stdc++.h>

using namespace std;

void output( double &k)
{
	if( k == 0)
		printf("N");
	else
		printf("%g", k);
}


int main()
{
	bool flag = true;;
	int n, k;
	double a1(0), a2(0), a3(0), a4(0), a5(0);
	double t2 = 1, t3(0);
	scanf("%d", &n);

	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &k);
		if( k % 5 == 0 && (k & 1) == 0)
		{
			a1 += k;
		}

		if( k % 5 == 1)
		{
			flag = false;
			a2 += ( t2 * k);
			t2 *= -1;
		}

		if( k % 5 == 2)
		{
			++a3;
		}

		if( k % 5 == 3)
		{
			a4 += k;
			++t3;
		}

		if( k % 5 == 4)
		{
			a5 = max( (double)k, a5);
		}
	}
	output(a1);	printf(" ");
	if( flag )//小坑点，a2交错求和可能为0，需要特判
		printf("N");
	else
		printf("%g", a2);
	printf(" ");
	output(a3);	printf(" ");
	if( a4 == 0)
		printf("N");
	else
		printf("%.1f", a4 / t3);
	printf(" ");
	output(a5);	printf("\n");
	return 0;
}
