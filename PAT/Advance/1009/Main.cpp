#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<int, double> Node;
bool cmp( const Node &A, const Node &B)
{
	return A.first > B.first;
}
const int MAXN = 1e1 + 5;
const int MAXM = MAXN * MAXN;
const double eps = 1e-8;

Node A[MAXN];	// Polynomial A
Node B[MAXN];	// Polynomial B
Node C[MAXM];	// A * B
Node D[MAXM];	// (A * B)格式处理过

int main()
{
	int n, m, len, len_ans;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d%lf", &A[i].first, &A[i].second);
	scanf("%d", &m);
	for(int i = 0; i < m; ++i)
		scanf("%d%lf", &B[i].first, &B[i].second);

	len = 0;
	for(int i = 0; i < n; ++i)	//多项式乘法
	{
		for(int j = 0; j < m; ++j)
		{
			C[len].first = A[i].first + B[j].first;
			C[len].second = A[i].second * B[j].second;
			++len;
		}
	}

	len_ans = 0;
	sort(C, C + len, cmp);
	D[0] = C[0];
	for(int i = 1; i < len; ++i)//合并同幂项
	{
		if( D[len_ans].first == C[i].first)
			D[len_ans].second += C[i].second;
		else
		{
			++len_ans;
			D[ len_ans ] = C[i];
		}
	}
	sort( D, D + len_ans + 1, cmp);

	len = 0;
	for(int i = 0; i <= len_ans; ++i)//去除0系数项
	{
		if( fabs(D[i].second) >= eps )
		{
			C[len++] = D[i];
		}
	}

	//输出
	printf("%d", len );
	for(int i = 0; i < len; ++i)
	{
		printf(" %d %.1lf", C[i].first, C[i].second);
	}

	return 0;
}
