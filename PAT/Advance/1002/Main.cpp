#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1005;
const double eps = 1e-8;
typedef pair<int, double> Node;

map<int, double> A, B, C;
bool flag[MAXN];

int main()
{
	A.clear();
	B.clear();
	C.clear();

	int n;
	Node node;

	scanf("%d", &n);

	for(int i = 0; i < n; ++i)
	{
		scanf("%d%lf", &node.first, &node.second);
		flag[ node.first] = true;
		A.insert( node );
	}

	scanf("%d", &n);
	for(int j = 0; j < n; ++j)
	{
		scanf("%d%lf", &node.first, &node.second);
		flag[ node.first ] = true;
		B.insert( node );
	}

	n = 0;
	for(int i = 0; i < MAXN; ++i)
	{
		if( flag[i] )
		{
			C[i] = A[i] + B[i];
			if( fabs(C[i]) < eps)	// 如果结果系数为0，則不必输出
			{
				flag[i] = false;
				continue;
			}
			++n;
		}
	}

	printf("%d", n);
	for(int i = MAXN - 1; i >= 0; --i)
	{
		if( flag[i] )
		{
			printf(" %d %.1lf", i, C[i]);
		}
	}

	printf("\n");

	return 0;
}
