#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> Node;
queue<Node> que, ans;

int main()
{
	Node node;
	while( cin >> node.first >> node.second)
	{
		node.first *= node.second;
		--node.second;
		que.push( node );
	}

	while( !que.empty())
	{
		node = que.front();
		que.pop();
		if( node.first != 0 || node.second == 0 )
			ans.push( node );
		else if( node.first == 0 && node.second == -1)
			ans.push( Node(0, 0) );
	}

	while( !ans.empty() )
	{
		printf("%d %d", ans.front().first, ans.front().second);
		ans.pop();
		if( !ans.empty())
			printf(" ");
	}

	printf("\n");

	return 0;
}
