#include <bits/stdc++.h>

using namespace std;

const int MAXL = 26;

class Node
{
	public:
		Node()
		{	memset( next, 0, sizeof(next));}

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

		if( NULL == p->next[ now ] )
		{
			p->next[now] = new Node();	
			p->next[now]->val = 1;
		}
		p = p->next[now];

		++str;
	}

	p->val = -1;
}

int findNode( char *str )
{
	int now = 0;
	Node *p = root;
	while( *str )
	{
		now = *str - 'a';
		p = p->next[ now ];
		if( p == NULL)
			-1;
		if( p->val == -1)
			0;
		++str;
	}
	return 1;
}

void deleteTrie( Node *now)
{
	Node *p = now;
	
	for(int i = 0; i < MAXL; ++i)
	{
		if( p->next[i] )
			deleteTrie( p );
	}
	delete p;
}

void solve()
{
}

int main()
{
	return 0;
}
