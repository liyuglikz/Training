#include <iostream>
#include <algorithm>
#include <string>

#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef struct tm Date;
typedef long long int ll;

const int dlib[] = {31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date ts;
Date t0;
Date t1;

Date t_date;
Date t_time;

bool judgeY( int k )
{
	return (k % 4 == 0 && k % 100) || (k % 400 == 0);
}

Date trans( Date old)
{
	Date now;
	ll sec_len;
	memset( &now, 0, sizeof( now ));
	
	double sec = difftime( mktime(&old), mktime(&ts));
	sec_len = (ll) sec;

	sec = sec * 100000 / (24 * 60 * 60);
	sec_len = (ll) sec;

	now.tm_sec = (sec_len % 100);
	sec_len /= 100;

	now.tm_min = (sec_len % 100);
	sec_len /= 100;

	now.tm_hour = (sec_len % 10);
	sec_len /= 10;

	now.tm_mday = (sec_len % 100) + 1;
	sec_len /= 100;

	now.tm_mon = ((sec_len) % 10) + 1;
	sec_len /= 10;

	now.tm_year = sec_len;

	return now;
}

Date trans2( Date old)
{
	Date now;
	ll sec_len;
	memset( &now, 0, sizeof( now ));
	
	/*
	double sec = difftime( mktime(&old), mktime(&ts));
	sec = sec / 24 / 60 / 60;
	sec_len = (ll) sec;
	*/


	sec_len = old.tm_mday;

	int buff = old.tm_year;
	while( old.tm_year > 2000)
	{
		--old.tm_year;
		sec_len += (365 + judgeY( old.tm_year) );
	}

	while( old.tm_mon > 1)
	{
		--old.tm_mon;
		sec_len += (dlib[ old.tm_mon ] + ( old.tm_mon == 2 && judgeY( buff ) ));
	}
	//cout << sec_len << endl;


	now.tm_mday = (sec_len % 100);
	sec_len /= 100;

	if( !now.tm_mday )
		now.tm_mday = 100;

	now.tm_mon = ((sec_len) % 10) + 1;
	sec_len /= 10;

	now.tm_year = sec_len;

	return now;
}

void solve()
{
	memset( &ts, 0, sizeof( ts ));
	ts.tm_year = 2000;
	ts.tm_mon = 1;
	ts.tm_mday = 1;

	int T;
	scanf("%d", &T);
	while(T--)
	{
		memset( &t_date, 0, sizeof( t_date ));
		t_time = ts;

		scanf("%d:%d:%d %d.%d.%d", &t0.tm_hour, &t0.tm_min, &t0.tm_sec,
				&t0.tm_mday, &t0.tm_mon, &t0.tm_year);

		t_date.tm_year	=	t0.tm_year;
		t_date.tm_mon	=	t0.tm_mon;	
		t_date.tm_mday	=	t0.tm_mday;

		t_time.tm_hour	=	t0.tm_hour;
		t_time.tm_min	=	t0.tm_min;
		t_time.tm_sec	=	t0.tm_sec;

			t1	=	trans2( t_date );	
		t_date	=	trans( t_time );

		printf("%d:%d:%d %d.%d.%d\n", t_date.tm_hour, t_date.tm_min, t_date.tm_sec,
				t1.tm_mday, t1.tm_mon, t1.tm_year);
	}
}

int main()
{
	solve();
	return 0;
}
