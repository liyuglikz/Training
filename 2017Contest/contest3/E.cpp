#include <iostream>
#include <algorithm>
#include <string>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const double eps = 1e-8;
const double pi = acos(-1);
const int MAXN = 3000 + 5;

typedef long long int ll;

int mouth[13];
int sum;
ll yearSum[MAXN], tmp;
int Day[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int pDay[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};


int pM[6] = {2, 3, 5, 7, 11}, pMlen = 5;
int pD[20] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
int pDlen[6] = {9, 11, 11, 11, 10};

ll day[2][370];

inline int trans(int m, int d, bool select)
{
	return pDay[select][m - 1] + d;
}

bool judge( int y )
{
	return ((y % 4 == 0) && (y % 100) ) || (y % 400 == 0);
}

void init()
{
	for(int j = 0 ; j < 2; ++j)
		for(int i = 1; i < 12; ++i)
			pDay[j][i] += pDay[j][i - 1];

	tmp = 52;

	for(int i = 1; i <= MAXN; ++i)
	{
		yearSum[i] = judge(i) + (yearSum[i - 1] + tmp);
	}

	for(int j = 0; j < 9; ++j)
		day[0][ trans(2, pD[j], 0)] = 1;
	for(int j = 0; j < 10; ++j)
		day[1][ trans(2, pD[j], 1)] = 1;
		

	for(int i = 1; i < pMlen; ++i)
	{
		for(int j = 0; j < pDlen[i]; ++j)
		{
			day[0][ trans(pM[i], pD[j], 0)] = 1;
			day[1][ trans(pM[i], pD[j], 1)] = 1;
		}
	}

	for(int i = 1; i <= 367; ++i)
	{
		day[0][i] += day[0][i - 1];
		day[1][i] += day[1][i - 1];
	}
}

void solve()
{
	init();
	int T;
	scanf("%d", &T);	
	while(T--)
	{
		int ans = 0;
		int y1, m1, d1;
		int y2, m2, d2;
		scanf("%4d%2d%2d", &y1, &m1, &d1);
		scanf("%4d%2d%2d", &y2, &m2, &d2);

		bool j1 = judge( y1 );
		bool j2 = judge( y2 );

		ans += (yearSum[ y2 - 1] - yearSum[ y1 - 1]);
		ans += ( day[ j2 ][trans(m2, d2, j2) ] - day[ j1 ][trans(m1, d1, j1) - 1]);
		printf("%d\n", ans);
	}
}

int main()
{
	solve();
	return 0;
}
