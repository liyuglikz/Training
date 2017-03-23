#include <bits/stdc++.h>
using namespace std;
const int INF = 1e3;
int rget(int a, int b)
{
	return (rand() % (b - a) ) + a;
}

int main()
{
	srand( (unsigned int) time(NULL));

	int T = 10;
	while(T--)
	{
		int n = rget(1, 10);
		cout << n << endl;
		for(int i = 0; i < n; ++i)
		{
			printf("%d %d\n", rget(-INF, INF), rget(-INF, INF));
		}
		cout << endl;
	}

	return 0;
}
