#include <iostream>
#include <algorithm>
#include <string>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
const int MAXL = 26;

class Node
{
	public:
		Node(){	memset( next, 0, sizeof(next));}
		Node *next[MAXL];
		bool flags;
};

void insertNode( char *str )
{
	int now;
	Node *p;
	
	while( *str )
	{
		now = *str - '0';

		if( p->next[now] )
		{
			p->next[now] = new Node();
			p->next[now]->flags = true;
			p = p->next[now];
		}

		++str;
	}
	p->val = false;
}

void solve()
{
}

int main()
{
	solve();
	return 0;
}
