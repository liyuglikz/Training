#include <bits/stdc++.h>

using namespace std;
const int MAXN = 3e5 + 5;
typedef pair<int, int> Point;
int lib[MAXN];

map<int, vector<int> > mps;
map<int, vector<int> > :: iterator it;
map<int, vector<int> > :: iterator it2;
vector<int> :: iterator it_v;

void solve()
{
	int n, k, cnt;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", lib + i);
		mps[ lib[i] ].push_back( i );
	}

	k = 0;
	while( mps.begin() != mps.end())
	{
		it = mps.begin();
		if( it->second.size() > 1)
		{
			if( k <= it->first )
				k = it->first + 1;

			it2 = it;
			++it2;

			while( it2 != mps.end() &&  k == it2->first )
			{
				++k;
				++it2;
			}

			cnt = it->second.size();

			it_v = it->second.begin();
			++it_v;

			for(; it_v != it->second.end(); ++it_v)
			{
				lib [*it_v] = k;
//				mps[k].push_back( *it_v );
				++k;

				while( it2 != mps.end() && k == it2->first )
				{
					++k;
					++it2;
				}
			}
		}
		mps.erase( it );
	}

	for(int i = 0; i < n; ++i)
	{
//		if( i )
//			putchar (' ');
		printf("%d\n", lib[i]);
	}
	printf("\n");
}

int main()
{
	solve();
	return 0;
}
