#include <iostream>
#include <algorithm>
#include <string>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <map>
#include <stack>

using namespace std;
const int MAXN = 1e4 + 5;
const int MAXL = 26;
const int MAXM = 1e8 + 5;

class Node
{
	public:
		Node() : cnt(0){	next.clear();}
		map<int, Node*> next;
		int cnt;
} *root;
char s[MAXN][MAXL];

void insertNode( char *str )
{
	int now;
	Node *p = root;
	
	while( *str )
	{
		now = *str - '0';
		if( NULL == p->next[now] )
			p->next[now] = new Node();
		p = p->next[now];

		++(p->cnt);
		++str;
	}
}

bool findNode( char *str)
{
	int now;
	Node *p = root;

	while( *str )
	{
		now = *str - '0';
		p = p->next[ now ];
		if( p == NULL)
			return true;
		++str;
	}
	return ( p->cnt <= 1);
}

//Node *sta[MAXM];
//int top = 0;

stack<Node*> sta;

void deleteNode( Node *now )
{
	map<int, Node*> :: iterator it;

	sta.push( now );
	while( !sta.empty() )
	{
		now = sta.top();
		sta.pop();
		for(it = now->next.begin(); it != now->next.end(); ++it)
			sta.push(it->second);
		delete now;
	}
}

void solve()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		root = new Node();
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
		{
			scanf("%s", s[i]);
			insertNode( s[i] );
		}

		bool ans = true;
		for(int i = 0; i < n && ans; ++i)
		{
			ans = findNode( s[i] );
		}
		puts( ans ? "YES" : "NO");

		deleteNode( root );
	}
}

int main()
{
	solve();
	return 0;
}
