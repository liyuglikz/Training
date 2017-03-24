#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1005;
int lib[MAXN];
int a[MAXN], lena;
int b[MAXN], lenb;
int ans[MAXN], len;

class node
{
public:
	explicit node(node *parent = NULL, int k = 0) : lson(NULL), rson(NULL), fath(parent), val(k) 
	{}
		node *lson;
		node *rson;
		node *fath;
		int val;
};

void build( node *now, int val , bool flag)
{
	if( (val < now->val) ^ flag)
	{
		if( !now->lson )
		{
			node *son = new node( now, val );
			now->lson = son;
		}
		else
		{
			build( now->lson, val, flag);
		}
	}
	else if( (val >= now->val) ^ flag)
	{
		if( !now->rson )
		{
			node *son = new node( now, val);
			now->rson = son;
		}
		else
		{
			build( now->rson, val, flag);
		}
	}
}

void dfs_mid( node *now)
{
//	printf("-> %d\n", now->val);
	a[lena++] = now->val;

	if( now->lson )
		dfs_mid( now->lson);
	if( now->rson )
		dfs_mid( now->rson);
}

void dfs_beh( node *now)
{
	if( now->lson )
		dfs_beh( now->lson);
	if( now->rson )
		dfs_beh( now->rson);

	ans[len++] = now->val;
}

node* judge( int n, bool flag)
{
	lena = 0;
	node *root = new node( NULL, lib[0] );
	for(int i = 1; i < n; ++i)
	{
		build( root, lib[i], flag);
	}

	dfs_mid( root );
	for(int i = 0; i < n; ++i)
	{
		if( a[i] != lib[i])
			return NULL;
	}
	return root;
}

void solve()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", lib + i);

	node *root;
	if( (root = judge(n, 0 )) || (root = judge( n, 1)) )
	{
		dfs_beh(root);

		puts("YES");
		for(int i = 0; i < len; ++i)
		{
			if(i) putchar(' ');
			printf("%d", ans[i]);
		}
		printf("\n");
	}
	else
		puts("NO");
}

int main()
{
	solve();
	return 0;
}
