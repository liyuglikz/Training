#include <iostream>
#include <algorithm>
#include <string>

#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct tm t1;
struct tm t2;

void solve()
{
	time_t a;
	time_t b;

	t1.tm_sec = t1.tm_min = t1.tm_hour = 0;
	t2.tm_sec = t2.tm_min = t2.tm_hour = 0;

	while(scanf("%d%d%d", &t2.tm_year, &t2.tm_mon, &t2.tm_mday) == 3)
	{
	}
}

int main()
{
	solve();
	return 0;
}
