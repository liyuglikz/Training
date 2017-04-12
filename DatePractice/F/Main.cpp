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

Date ts;
Date t0;
Date t1;

Date trans( Date old)
{
	Date now;
	ll sec_len;
	memset( &now, 0, sizeof( now ));
	
	double sec = difftime( mktime(&old), mktime(&ts));
//	sec += (24 * 60 * 60);
	sec_len = (ll) sec;
	cout << sec_len << endl;

	sec = sec * 100000 / (24 * 60 * 60);
	sec_len = (ll) sec;
	cout << sec_len << endl;

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
		scanf("%d:%d:%d %d.%d.%d", &t0.tm_hour, &t0.tm_min, &t0.tm_sec,
				&t0.tm_mday, &t0.tm_mon, &t0.tm_year);
		t1 = trans( t0 );	

		printf("%d:%d:%d %d.%d.%d\n", t1.tm_hour, t1.tm_min, t1.tm_sec,
				t1.tm_mday, t1.tm_mon, t1.tm_year);
	}
}

int main()
{
	solve();
	return 0;
}
