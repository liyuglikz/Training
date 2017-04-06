#include <iostream>
#include <algorithm>
#include <string>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <stack>
#include <set>
#include <map>

using namespace std;
const int MAXN = 1e6 + 1;

class node
{
public:
    int p, t, x;

    bool friend operator < ( const node &a, const node &b)
    {
        return a.p > b.p;
    }
    bool friend operator == (const node &a, const node &b)
    {
        return a.p == b.p;
    }
};

typedef pair<int, node> Point;

bool operator < (const Point &a, const Point &b)
{
    return a.first < b.first;
}

set<node> s1;
set<int> s2;

set<node> :: iterator it;
set<int> :: iterator it1;
set<Point> :: iterator it2;

set<Point> mps;

void solve()
{
    int n, p, m, k;

    while(scanf("%d", &n) == 1)
    {

        node now, buff;
		s1.clear();
		s2.clear();
		mps.clear();

        for(int i = 0; i < n; ++i)
        {
            scanf("%d%d", &now.p, &now.t);
            if(now.t)
            {
                scanf("%d", &now.x);

                it2 = mps.upper_bound( Point( now.p, now ) );
//				printf("-> %d %d\n", now.p, it2->second.p);
                while( it2 != mps.end() && now.p > it2->second.p)
                {
//                    puts("got");
                    buff = it2->second;

                    mps.erase( it2 );
                    mps.erase( Point( k, now ) );
                    now = buff;
					it2 = mps.upper_bound( Point( now.p, now) );
                }

                it1 = s2.upper_bound( now.p );

                if( it1 != s2.end() )
                {
//                    printf("-> %d %d %d\n", *it1, now.p, now.x);
                    mps.insert( Point( *it1, now) );
                    s2.erase ( it1 );
                }
                else
                    s1.insert( now );
            }
            else
            {
                it = s1.upper_bound( now );

                it2 = mps.upper_bound( Point( now.p, now) );
                while( it2 != mps.end() && now.p > it2->second.p )
                {
                    k = it2->first;
                    buff = it2->second;

                    mps.erase( it2 );
                    mps.insert( Point ( now.p, buff ) );
                    now.p = k;
                	it2 = mps.upper_bound( Point( now.p, now) );
                }

                if( it != s1.end() )
                {
                    //
                    mps.insert( Point( now.p, *it) );
                    s1.erase ( it );
                }
                else
                    s2.insert( now.p );
            }

            if(s1.empty())
                printf("-1\n");
            else
                printf("%d\n", s1.begin() -> x);
        }
    }
}

int main()
{
    solve();
    return 0;
}
