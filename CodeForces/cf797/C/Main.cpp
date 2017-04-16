#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;
char s[MAXN];
char ans[MAXN];
int ans_len = 0;

class Node
{
	public:
		Node(int a = 0, char b = 0) : first( a ), second(b){}
		bool operator < (const Node &k)
		{
			if( this->second != k.second)
				return this->second < k.second;
			return this->first > k.first;
		}
		int first;
		char second;
};

bool operator < (const Node &a, const Node &b)
{
	if( a.second != b.second)
		return a.second < b.second;
	return a.first > b.first;
}

set<Node> st;

void input()
{
	scanf("%s", s);
}

void solve()
{
	int len = strlen( s ), t = 0;
	for(int i = 0; i < len; ++i)
		st.insert( Node(i, s[i] ) );

	set<Node> :: iterator it;
	len = 0;

//	for(it = st.begin(); it != st.end(); ++it)
//		printf("%d %c\n", it->first, it->second);

	while( !st.empty() )
	{
		it = st.begin();
		t = it->first;

		for(int i = it->first; i >= len; --i)
		{
			ans[ ans_len++] = s[i];
			st.erase( Node( i, s[i] ) );
		}
		len = t + 1;
	}
}

void output()
{
	puts(ans);
}

int main()
{
	input();
	solve();
	output();
	return 0;
}
