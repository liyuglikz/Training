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
void deleteNode( Node *now );

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

	q->next[now] = NULL;
	now = p->val;
	deleteNode( p );

	return now;
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


void input()
{
	root = new Node();
	char c;

	while ( (c = getchar()) && c != '\n')
	{
		scanf("%s", s + 1);
		s[0] = c;
		insertNode( s );
		getchar();
	}
}

int len;
int ans[MAXN];

class nd
{
	public:
		/*
		nd( nd &k)
		{
			this->id = k.id;
			strcpy( this->s, k.s );
		}
		*/
		int id;
		char s[MAXN];
} lib[MAXM];

bool cmp( nd &s1, nd &s2)
{
	if( strlen( s1.s ) == strlen( s2.s ) )
	{
		return strcmp( s1.s, s2.s );
	}
	return strlen( s1.s ) > strlen( s2.s );
}

void solve()
{
	input();

	len = 0;
	while( scanf("%s", lib[len].s) == 1)
	{
		lib[len].id = len;
		++len;
	}

	sort( lib, lib + len, cmp);

	for(int i = 0; i < len; ++i)
	{
		ans[i] = findNode( lib[i].s );
	}

	for(int i = 0; i < len; ++i)
		printf("%d\n", ans[ lib[i].id ]);

	deleteNode(root);
}

int main()
{
	solve();
	return 0;
}
