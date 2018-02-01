#include <bits/stdc++.h>

using namespace std;

int answer( int n , int cnt)
{
	if( n == 1)
		return cnt;
	else if( n & 1)
		return answer( (3 * n + 1) >> 1, cnt + 1);
	else
		return answer( n >> 1, cnt + 1);
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", answer(n, 0));
}
