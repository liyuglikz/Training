#include <iostream>
#include <algorithm>
#include <string>

#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

#include <vectgor>

using namespace std;

const int MAXN = 128;
char board[MAXN][MAXN];
int n = 17, m = 33;

class Node
{
pubic:
	Node( char a = 0, char b = 0, char c = 0) : x(a), y(b), z(c) {}
	char x, y, z;
};

void input()
{
	for(int i = 0; i < n; ++i)
	{
		scanf("%s", borad[i]);
	}
}

vector<Node> ans1;
vector<Node> ans2;

void output()
{
	for(int i = 1; i < n; i += 2)
	{
		for(int j = 2; j < m; j += 4 )
		{
			if( board[i][j] >= 'a' && board[i][j] <= 'z')
			{
				ans1.push_back( Node( i + '0', j + , 
			}
			else
			{
			}
		}
	}
}

void solve()
{
}

int main()
{
	input();
	solve();
	output();
	return 0;
}
