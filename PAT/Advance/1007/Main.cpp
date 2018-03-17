#include <cstdio>
#define MAX(a, b) (a > b ? a : b)

using namespace std;
const int MAXN = 1e5 + 5;
int lib[MAXN];	//数字序列

int dp[MAXN];	/* dp[i] 表示以i为结尾，子串的最大和
	有状态转移 dp[i] = MAX( lib[i], dp[i - 1] + lib[i]);*/

int left[MAXN], right[MAXN];	//记录字串首尾(尾部实际不用记录)

int main()
{
	int n, ans;
	while( scanf("%d", &n) == 1)
	{
		for(int i = 1; i <= n; ++i)
			scanf("%d", lib + i);

		// DP:
		for(int i = 1; i <= n; ++i)
		{
			if( lib[i] < dp[i - 1] + lib[i])	//状态转移
			{
				dp[i] =  dp[i - 1] + lib[i];
				left[i] = left[i - 1];
				right[i] = i;
			}
			else
			{
				dp[i] = lib[i];
				left[i] = right[i] = i;
			}
		}

		ans = 1;
		for(int i = 1; i <= n; ++i)
		{
			if( dp[ans] < dp[i])
				ans = i;
			else if( dp[ans] == dp[i] )
			{
				if( left[ans] > left[i])
					ans = i;
				else if( left[ans] == left[i])
				{
					if( right[ans] > right[i])
						ans = i;
				}
			}
		}

		if( dp[ans] >= 0)
			printf("%d %d %d\n", dp[ans], lib[ left[ans] ], lib[ right[ans]]);
		else	//题目特判，全为负数，输出整个序列的首尾元素
			printf("0 %d %d\n", lib[1], lib[n]);
	}
	return 0;
}
