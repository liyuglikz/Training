#include <bits/stdc++.h>

using namespace std;

int rget(int a, int b)
{
	return rand() % (b - a) + a;
}

int main()
{
	srand( (unsigned int) time(NULL));

	int T = 1;
	printf("%d\n", T);
	while(T--)
	{
		int n = 100000;
		cout << n << endl;
		for(int i = 1; i <= n; ++i)
		//	printf("%d ", i);
			printf("1 ");
	}
	return 0;
}
