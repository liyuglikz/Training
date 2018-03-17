#include <cstdio>

using namespace std;

const int MAXN = 1e3 + 5;
const int MAXM = 24;

int lib[MAXM];
char s1[MAXM], s2[MAXM], s3[MAXM];

int main()
{
	int n, m;
	for(int i = 0; i < MAXM; ++i)
	{
		scanf("%d", lib + i);
	}

	scanf("%d", &m);
	for(int i = 0; i < m; ++i)
	{
		scanf("%s %s %s", s1, s2, s3);
	}
	return 0;
}
