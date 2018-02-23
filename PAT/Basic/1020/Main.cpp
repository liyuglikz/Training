#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1005;
const double eps = 1e-8;

class Node
{
	public:
		double a, b, c; //此处注意卡精度！
};

bool cmp( Node &A, Node &B)
{	return A.c > B.c;}

Node lib[MAXN];

int main()
{
	int n, m;
	double ans = 0;
	scanf("%d%d", &n, &m);

	for(int i = 0; i < n; ++i)
		scanf("%lf", &lib[i].a);
	for(int i = 0; i < n; ++i)
	{
		scanf("%lf", &lib[i].b);
		lib[i].c = lib[i].b / (double)lib[i].a;
	}
	sort( lib, lib + n, cmp);
	for( int i = 0; i < n && m > 0; ++i)
	{
		if( m >= lib[i].a)
		{
			ans += lib[i].b;
			m -= lib[i].a;
		}
		else
		{
			ans += (m * lib[i].c);
			break;
		}
	}
	printf("%.2lf\n", ans);

	return 0;
}
