#include <bits/stdc++.h>

using namespace std;
const int MAXN = 3e5 + 5;
int lib[MAXN];

map<int, vector<int> > mps;
map<int, vector<int> > :: iterator it;
map<int, vector<int> > :: iterator it2;
map<int, vector<int> > :: iterator it3;
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

//	for(it = mps.begin(); it != mps.end(); ++it)
	while( mps.begin() != mps.end())
	{
		it = mps.begin();
		if( it->second.size() > 1)
		{
			k = it->first + 1;
			it2 = it;
			++it2;

			while( k == it2->first)
			{
				++k;
				++it2;
			}

			cnt = it->second.size();

			it_v = it->second.begin();
			++it_v;

			for(; it_v != it->second.end(); ++it_v)
			{
				lib[*it_v] = k;
				mps[k].push_back( *it_v );

				while( k == it2->first)
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
		if( i )
			putchar (' ');
		printf("%d", lib[i]);
	}
	printf("\n");
}

int main()
{
	solve();
	return 0;
}
