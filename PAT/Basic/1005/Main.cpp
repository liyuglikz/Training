#include <bits/stdc++.h>
using namespace std;

set<int> s;
set<int> flag;
int n, lib[105];

bool search( int num )
{
	flag.insert( num );
	if( num == 1)
		return true;
	else if (num & 1)
		return search( (3 * num + 1) >> 1);
	else
		return search( num  >> 1);
}

int main()
{
	int k;
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		scanf("%d", lib + i);
		if (lib[i] & 1)
			search( (3 * lib[i] + 1) >> 1);
		else if( lib[i] != 1)
			search( lib[i]  >> 1);
	}

	for(int i = 0; i < n; ++i)
	{
		if( flag.find( lib[i] ) == flag.end())
			s.insert( lib[i] );
	}

	set<int> :: reverse_iterator it;
	for( it = s.rbegin(); it != s.rend(); ++it)
	{
		if( it != s.rbegin())
			printf(" ");
		printf("%d", *it);
	}
	printf("\n");
	return 0;
}
