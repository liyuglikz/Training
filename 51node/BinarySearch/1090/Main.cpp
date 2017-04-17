#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int INF = 0x7fffffff;
int n, lib[MAXN];

class Node
{
	public:
		explicit Node( int x0 = 0, int x1 = 0, int x2 = 0)
		{
			a[0] = x0; a[1] = x1; a[2] = x2;
		}
		bool operator < (const Node &k) const
		{
			if( this->a[0] != k.a[0])
				return this->a[0] < k.a[0];
			if( this->a[1] != k.a[1])
				return this->a[1] < k.a[1];
			return this->a[2] < k.a[2];
		}
		void st(){	sort(a, a + 3);}
		int a[3];
};
//Node ans[MAXN];
set<Node> ans;

void input()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", lib + i);
	sort( lib , lib + n);
}

int search(int m)
{
	int l = 0;
	int r = n;
	int mid;

	while( l < r)
	{
		mid = (l + r) >> 1;

		if( lib[mid] < m)
			l = mid + 1;
		else if(lib[mid] > m)
			r = mid;
		else
			return lib[mid];
	}
	return INF;
}

void solve()
{
	Node now;
	for(int i = 0; i < n; ++i)
	{
		for(int j = i + 1; j < n - 1; ++j)
		{
			int k = search( -(lib[i] + lib[j]) );
			
			if( k != INF && k != lib[i] && k != lib[j])
			{
//				printf("-> %d %d %d\n", lib[i], lib[j], k);
				now = Node( lib[i], lib[j], k);
				now.st();
//				ans[len++] = Node( i, j, lib[i] );
				ans.insert( now );
			}
		}
	}
}

void output()
{
	/*
	for(int i = 0; i < len; ++i)
		ans[i].st();
	sort(ans, ans + len);
	for(int i = 0; i < len; ++i)
		printf("%d %d %d\n", ans[i].a[0], ans[i].a[1], ans[i].a[2]);
*/

	if( ans.empty())
	{
		puts("No Solution");
		return;
	}

	set<Node> :: iterator it;
	for(it = ans.begin(); it != ans.end(); ++it)
		printf("%d %d %d\n", it->a[0], it->a[1], it->a[2]);
}

int main()
{
	input();
	solve();
	output();
	return 0;
}
