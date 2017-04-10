#include <iostream>
#include <algorithm>
#include <string>

#include <vector>
#include <set>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
const int MAXN = 1e5 + 5;
typedef pair<char, char> Point;
typedef long long int ll;
Point lib[MAXN];

int n;
ll cnt;
int ct[30];
int ct2[30];

int pt[MAXN];
int pt2[MAXN];

char s[1005];

void init()
{
	cnt = 0;
	memset( ct, 0, sizeof( ct ) );
	memset( ct2, 0, sizeof( ct2 ) );
}

void solve()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		init();
		scanf("%d", &n);

		for(int i = 1; i <= n; ++i)
		{
			scanf("%s", s);

			lib[i].first = s[0];
			lib[i].second = s[ strlen(s) - 1];

			++ct[ lib[i].second - 'a']; // out
			++ct2[ lib[i].first - 'a']; // in
		}

		for(int i = 1; i <= n; ++i)
		{
			//printf("%d %d\n", ct[ lib[i].first - 'a'], ct2[lib[i].second - 'a']);
			pt[i] = ct[ lib[i].first - 'a' ]; // out
			pt2[i] = ct2[ lib[i].second - 'a' ];// in
		}

		int a = 0, ap;
		int b = 0, bp;

		for(int i = 1; i <= n; ++i)
		{
//			printf("%d %d\n", pt[i], pt2[i]);
//			if( pt[i] - pt2[i] == 1)
			if( pt[i] > pt2[i])
			{
				++a;
				ap = i;
			}

//			if( pt[i] - pt2[i] == -1)
			if( pt[i] < pt2[i])
			{
				++b;
				bp = i;
			}
		}
		printf("a:%d b:%d\n", a, b);

		if( (a != 1 || b != 1) )
		{
			puts("The door cannot be opened.");
			continue;
		}

		for(int i = 0; i < n && !cnt; ++i)
		{
			if( i != ap && i != bp)
			{
				if( pt[i] != pt2[i])
					cnt = 1;
			}
		}

		if( cnt )
			puts("The door cannot be opened.");
		else
			puts("Ordering is possible.");
	}
}

int main()
{
	solve();
	return 0;
}
