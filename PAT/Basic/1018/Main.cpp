#include <bits/stdc++.h>

using namespace std;

typedef pair<char, int> Node;
map<char, int> mps_a, mps_b;

int judge(char a, char b)
{
	switch( a )
	{
		case 'C':
			switch( b )
			{
				case 'C': return 0;
				case 'B': return -1;
				case 'J': return 1;
			}
		case 'J':
			switch( b )
			{
				case 'C': return -1;
				case 'B': return 1;
				case 'J': return 0;
			}
		case 'B':
			switch( b )
			{
				case 'C': return 1;
				case 'B': return 0;
				case 'J': return -1;
			}
	}
}

int A[3], B[3];
void solve()
{
	mps_a.insert( Node( 'C', 0) );
	mps_a.insert( Node( 'J', 0) );
	mps_a.insert( Node( 'B', 0) );
	mps_b.insert( Node( 'C', 0) );
	mps_b.insert( Node( 'J', 0) );
	mps_b.insert( Node( 'B', 0) );
	int n, result;

	char a, b;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("\n%c %c", &a, &b);
		result = judge(a, b);
		if( result == 1)
		{
			mps_a[a]++;
			++A[0];
			++B[2];
		}
		else if( result == -1)
		{
			mps_b[b]++;
			++A[2];
			++B[0];
		}
		else
		{
			++A[1];
			++B[1];
		}
	}

	n = 0;
	map<char, int> :: iterator it;
	for( it = mps_a.begin(); it != mps_a.end(); ++it)
	{
		if( n < it->second)
		{
			n = it->second;
			a = it->first;
		}
		else if( n == it->second && a > it->first)
			a = it->first;
	}

	n = 0;
	for( it = mps_b.begin(); it != mps_b.end(); ++it)
	{
		if( n < it->second)
		{
			n = it->second;
			b = it->first;
		}
		else if( n == it->second && b > it->first)
			b = it->first;
	}
	printf("%d %d %d\n", A[0], A[1], A[2]);
	printf("%d %d %d\n", B[0], B[1], B[2]);
	printf("%c %c\n", a, b);
}

int main()
{
	solve();
	return 0;
}
