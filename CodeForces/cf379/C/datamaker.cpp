#include <bits/stdc++.h>

using namespace std;

int rget(int a, int b)
{
	return ( rand() % (b - a)) + a;
}

int main()
{
	srand( (unsigned int ) time(NULL));
	int t = rget(2, 100);
	printf("%d\n", t);
	while( t-- )
	{
		printf("%d ", rget(1, 100));
	}
	return 0;
}
