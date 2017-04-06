#include <bits/stdc++.h>

using namespace std;

int rget(int a, int b)
{
	return (rand() % (b - a)) + a;
}

int main()
{
	srand( (unsigned int) time(NULL));
	
	int T = 100;
	while(T--)
	{
		printf("%d %d %d\n", rget(0, 20), rget(0, 20), rget(0, 20));
	}

	return 0;
}
