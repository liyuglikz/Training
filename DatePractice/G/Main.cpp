#include <iostream>
#include <algorithm>
#include <string>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include <ctime>

using namespace std;

typedef struct tm Date;

int mday[] = {31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool judgeY( int k )
{	return ((k % 4 == 0) && (k % 100)) || (k % 400 == 0);}

Date t0;

Date operator + (Date now, int k)
{
	now.tm_mday += k;
	while( now.tm_mday  > mday[ now.tm_mon] + ( now.tm_mon == 2 && judgeY( now.tm_year)) )
	{
		now.tm_mday -= ( mday[ now.tm_mon] + ( now.tm_mon == 2 && judgeY( now.tm_year)) );
		++now.tm_mon;
		if( now.tm_mon >= 13)
		{
			now.tm_mon = 1;
			now.tm_year++;
		}
	}

	return now;
}

Date operator - (Date now, int k)
{
	now.tm_mday -= k;
	while( now.tm_mday <= 0)
	{
		now.tm_mday += ( mday[ now.tm_mon - 1] + ( (now.tm_mon - 1) == 2 && judgeY( now.tm_year)) );
		--now.tm_mon;
		if( now.tm_mon <= 0)
		{
			now.tm_mon = 12;
			now.tm_year--;
		}
	}
	return now;
}

void solve()
{
	t0.tm_year = 2013;
	t0.tm_mon = 3;
	t0.tm_mday = 24;
	
	int T, k;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &k);	
		Date t1 = t0 + k;
		Date t2 = t0 - k;
		printf("%02d/%02d/%02d %02d/%02d/%02d\n", t1.tm_year, t1.tm_mon, t1.tm_mday,
				t2.tm_year, t2.tm_mon, t2.tm_mday);
	}
}

int main()
{
	solve();
	return 0;
}
