#include <cstdio>
#include <cmath>

using namespace std;
const int MAXN = 3;
const char str_status[] = "WTL";

int main()
{
	char s[8];
	s[1] = s[3] = ' ';
	s[5] = 0;

	double lib[MAXN][MAXN];
	for(int i = 0; i < MAXN; ++i)
	{
		for(int j = 0; j < MAXN; ++j)
			scanf("%lf", &lib[i][j]);
	}

	double ans = 0;
	double val;

	for(int i = 0; i < MAXN; ++i)
	{
		for(int j = 0; j < MAXN; ++j)
		{
			for(int k = 0; k < MAXN; ++k)
			{
				val = lib[0][i] * lib[1][j] * lib[2][k];

				if( !i )
					val *= 0.65;

				if( !j )
					val *= 0.65;
				
				if( !k )
					val *= 0.65;

				if( val > ans)
				{
					ans = val;
					s[0] = str_status[i];
					s[2] = str_status[j];
					s[4] = str_status[k];
				}
			}
		}
	}
	ans = (ans - 1.0) * 2.0;
	printf("%s %.2lf\n", s, ans);
	return 0;
}
