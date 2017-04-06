#include <iostream>
#include <algorithm>
#include <string>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <vector>
#include <queue>
#include <stack>

using namespace std;

const double eps = 1e-8;
const double pi = acos(-1);
const int MAXN = 105;

typedef long long int ll;

double lib[MAXN];
double buff[MAXN];

bool cmp(const double &a, const double &b)
{
	return a > b;
}

void solve()
{
	
	int m, n, p = 0;
	while(	scanf("%d%d", &m, &n) == 2)
	{
		p = 0;
		bool flag = true;
		double ans = 0;
		memset(buff, 0, sizeof(buff));

		for(int i = 0; i < n; ++i)
			scanf("%lf", lib + i);			
		sort(lib, lib + n, cmp);

		for(int i = 0; i < n; ++i)
		{	
			if(flag)
				buff[p++] += lib[i];
			else
				buff[--p] += lib[i];
			if( flag > m )
				flag = false;
			else if(flag <= 0)
				flag = true;
		}
		
		ans = buff[0];
		for(int i = 0; i < m; ++i)
			ans = min( buff[i], ans);
	
		lib[0] = ans;
		for(int i = 0; i < m; ++i)
		{
			ans += (buff[i] - lib[0]);
		}
		printf("%f\n", ans);
	}
}

int main()
{
	solve();
	return 0;
}
