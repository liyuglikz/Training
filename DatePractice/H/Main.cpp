#include <iostream>
#include <algorithm>
#include <string>

#include <ctime>

#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct tm t0;
struct tm t1;
struct tm t2;

struct tm operator - (struct tm a, struct tm b)
{
	struct tm ans;

	if( a.tm_sec < b.tm_sec)
	{
		a.tm_sec += 60;
		a.tm_min--;
		if( a.tm_min < 0)
		{
			--a.tm_hour;
			a.tm_min += 60;
		}
		if( a.tm_hour < 0)
			a.tm_hour += 12;
	}

	ans.tm_sec = a.tm_sec - b.tm_sec;
	
	if( a.tm_min < b.tm_min)
	{
		a.tm_min += 60;
		a.tm_hour--;
		if( a.tm_hour < 0)
			a.tm_hour += 12;
	}
	ans.tm_min = a.tm_min - b.tm_min;

	while( a.tm_hour < b.tm_hour)
		a.tm_hour += 12;
	ans.tm_hour = a.tm_hour - b.tm_hour;


	return ans;
}

void solve()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d:%d:%d", &t0.tm_hour, &t0.tm_min, &t0.tm_sec);
		scanf("%d:%d:%d", &t1.tm_hour, &t1.tm_min, &t1.tm_sec);
		t2 = t0 - t1;
		printf("%02d:%02d:%02d\n", t2.tm_hour, t2.tm_min, t2.tm_sec);
	}
}

int main()
{
	solve();
	return 0;
}
