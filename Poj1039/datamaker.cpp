#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> Point;
const int INF = 100;

bool operator < (const Point &a, const Point &b)
{
	return a.first < b.first;
}

int rget(int a, int b)
{
	return rand() % (b - a) + a;
}

set<Point> s;
set<Point> :: iterator it;

int main()
{
	srand( (unsigned int ) time(NULL));

	int n = rget(3, 10);
	cout << n << endl;
	for(int i = 0; i < n; ++i)
	{
		s.insert( Point( rget(0, INF), rget(0, INF)) );
	}

	for(it = s.begin(); it != s.end(); ++it)
	{
		printf("%d %d\n", it->first, it->second);
	}	

	return 0;
}
