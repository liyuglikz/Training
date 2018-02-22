#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4;
int a[MAXN], b[MAXN], c[MAXN];

bool cmp( const int &a, const int &b)
{
	return a > b;
}

void output( int s[])
{
	printf("%d%d%d%d", s[0], s[1], s[2], s[3]);
}

void fun( int a[], int b[], int c[])
{
	int A = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
	int B = b[0] * 1000 + b[1] * 100 + b[2] * 10 + b[3];
	int C = A - B;
	int i = 3;
	while( C )
	{
		c[i--] = C % 10;
		C /= 10;
	}
	for( ; i >= 0; --i)
		c[i] = 0;
}

bool judge( int c[])
{
	int C = c[0] * 1000 + c[1] * 100 + c[2] * 10 + c[3];
	return ( C == 0 || C == 6174);
}

int main()
{
	for(int i = 0; i < MAXN; ++i)
		scanf("%1d", a + i);
	do
	{
		b[0] = a[0];
		b[1] = a[1];
		b[2] = a[2];
		b[3] = a[3];
		sort( a, a + 4, cmp);
		sort( b, b + 4);
		fun( a, b, c);
		output(a);
		printf(" - ");
		output(b);
		printf(" = ");
		output(c);
		printf("\n");
		a[0] = c[0];
		a[1] = c[1];
		a[2] = c[2];
		a[3] = c[3];
	}while( !judge( c ) );

	return 0;
}
