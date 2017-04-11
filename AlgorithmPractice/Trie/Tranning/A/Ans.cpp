#include <iostream>
#include <algorithm>
#include <string>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
const int MAXN = 16;
const int MAXM = 1e5 + 5;
const int MAXL = 26;
char s[MAXN];


class Node
{
	public:
		Node() : val(1){ memset( next, 0, sizeof(next));}
		Node *next[MAXL];
		int val;
};
Node *root;

void insertNode( char *str )
{
	int now;
	Node *p = root;

	while( *str )
	{
		now = *str - 'a';
		
		if( NULL == p->next[now])
			p->next[now] = new Node();
		else
			++ (p->next[now]->val);
		p = p->next[now];

		++str;
	}
	p->val = 1;
}

int findNode( char *str )
{
	int now;
	Node *p = root;
	Node *q;

	while( *str )
	{
		now = *str - 'a';

		q = p;
		p = p->next[ now ];
		if( NULL == p)
			return 0;

		++str;
	}

	return p->val;
} 

void deleteNode( Node *now )
{
	for(int i = 0; i < MAXL; ++i)
	{
		if( now->next[i] )
			deleteNode( now->next[i]);
	}
	delete now;
}

void solve()
{
	root = new Node();
	while( gets(s),  strcmp(s, "") != 0)
		insertNode( s );

	while( scanf("%s", s) == 1)
		printf("%d\n", findNode( s ));
	deleteNode(root);
}

int main()
{
	printf("%d\n", sizeof(Node));
	solve();
	return 0;
}
