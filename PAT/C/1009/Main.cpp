#include <bits/stdc++.h>

using namespace std;

stack<string> sta;

int main()
{
	string s;
	while( cin >> s)
		sta.push( s );
	while( !sta.empty())
	{
		cout << sta.top();
		sta.pop();
		if( !sta.empty())
			printf(" ");
	}
	printf("\n");
	return 0;
}
