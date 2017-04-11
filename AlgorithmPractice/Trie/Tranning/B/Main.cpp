#include <iostream>
#include <algorithm>
#include <string>

#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#include <stack>

using namespace std;
typedef long long int ll;

const int MAXL = 32;
const int MAXN = 36;
const int MAXX = 1 << 20;

int len;
int buff[MAXN];

class Node
{
	public:
		Node() { next[0] = next[1] = 0;}
		Node *next[2];
} *root;

void trans( int k )
{
	memset( buff, 0, sizeof(buff));
	len = 1;
	while( k )
	{
		buff[MAXL - len] = (k & 1);
		++len;
		k >>= 1;
	} } 
void insertNode( int *s)
{
	int now;
	Node *p = root;
	for(int i = 0; i < MAXL; ++i)
	{
		now = *s;
		if( NULL == p->next[ now] )
			p->next[ now ] = new Node();
		p = p->next[ now ];
		++s;
	}
}

ll findNode( int *s )
{
	ll ans = 0;
	int now;
	Node *p = root;
	for(int i = 0; i < MAXL; ++i)
	{
		now = !(*s);

		if( p->next[ now ] )
		{
			p = p->next[now];
			ans = (ans << 1) | now;
		}
		else if( NULL == p->next[ now ] && p->next[ *s ])
		{
			p = p->next[*s];
			ans = (ans << 1) | *s;
		}
		else if( NULL == p->next[ *s ] && NULL == p->next[ now ] )
		{
			return ans;
		}
		++s;
	}
	return ans;
}

void deleteNode( Node *now )
{
	if( now->next[0] )
		deleteNode( now->next[0] );
	if( now->next[1] )
		deleteNode( now->next[1] );
	delete now;
}

void solve()
{
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t)
	{
		printf("Case #%d:\n", t);
		root = new Node();
		int n, m, k;
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; ++i)
		{
			scanf("%d", &k);
			trans( k );
			insertNode( buff );
		}
		for(int i = 0; i < m; ++i)
		{
			scanf("%d", &k);
			trans( k );
			printf("%lld\n", (findNode( buff )));
		}
		deleteNode( root );
	}
}

int main()
{
	solve();
	return 0;
}
