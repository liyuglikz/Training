#include <iostream>
#include <algorithm>
#include <string>

#include <set>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)

using namespace std;

const double eps = 1e-8;
const int MAXN = 30;
const int INF = 0x7fffffff;

double iabs(const double &k)
{
    return k < 0 ? -k : k;
}

class Point
{
public:
    double x, y;
    Point(const double &a = 0, const double &b = 0) : x(a), y(b) {}

    Point operator + (const Point &k)
    {
        return Point( this->x + k.x, this->y + k.y);
    }

    Point operator - (const Point &k)
    {
        return Point(this->x - k.x, this->y - k.y);
    }

    double operator ^ (const Point &k)
    {
        return this->x * k.y - this->y * k.x;
    }

    void input()
    {
        scanf("%lf%lf", &x, &y);
    }

    bool operator < (const Point &k) const
    {
        if( iabs(this->x - k.x) < eps)
            return this->y < k.y;
        return this->x < k.x;
    }
};

inline bool isCrossed( Point &A, Point &B, Point &C, Point &D)
{
    return ((((C - A) ^ (C - B)) * ((D - A) ^ (D - B))) < 0 );
}

inline bool isCrossed2( Point &A, Point &B, Point &C, Point &D)
{
    return ((((C - A) ^ (C - B)) * ((D - A) ^ (D - B))) <= 0 );
}

inline Point crossed( Point &A, Point &B, Point &C, Point &D)
{
    Point AB = B - A;
    double k = (A.x - D.x) * (A.y - C.y) - (A.x - C.x) * (A.y - D.y);
    k /= (AB.x * (A.y - D.y) + AB.y * (A.x - C.x) - AB.y * (A.x - D.x) - AB.x * (A.y - C.y));
    AB.x *= k;
    AB.y *= k;
    return (A + AB);
}

Point s1[MAXN], s2[MAXN];

bool onSide( Point A, Point B, Point s[], int n)
{
    int i = 0;
    double k;
    while( iabs((s[i] - A) ^ (s[i] - B)) < eps && i < n)
    {
        ++i;
    }

    k = (s[i] - A) ^ (s[i] - B);
    ++i;

    for(; i < n; ++i)
    {
        //cout << (k * ((s[i] - A) ^ (s[i] - B)) < 0 );
        if(k * ((s[i] - A) ^ (s[i] - B)) < 0 )
        {
            return true;
        }
    }
	//printf(" %g\n", k );
    return false;
}

double shotPipes( Point A, Point B, Point s[], int n)
{
    set<double> cache;

    cache.clear();

    for(int i = 0; i < n - 1; ++i)
    {
        if( isCrossed( A, B, s[i], s[i + 1]) )
            cache.insert( crossed(A, B, s[i], s[i + 1]).x );
        else if( iabs((A - B) ^ (s[i] - s[i + 1])) < eps)
            cache.insert( MIN( s[i + 1].x, s[i].x) );
    }

	/*
	for(int i = 0; i < n - 1; ++i)
	{
		if( ((s[i] - A) ^ (s[i] - B)) * ((s[i + 1] - A) ^ (s[i] - B)) < 0)
		{
			cache.insert(
		}
	}
	*/

    if(!cache.empty())
    {
		printf("-> %g\n", *(cache.begin()) );
        return *(cache.begin());
    }

    return -1;
}

void solve()
{
    int n;
    while(scanf("%d", &n) == 1 && n)
    {
        bool flag = true;
        double ans = -INF;

        for(int i = 0; i < n; ++i)
        {
            s1[i].input();
            s2[i].x = s1[i].x;
            s2[i].y = s1[i].y - 1.0;
        }

        for(int i = 0; i < n && flag; ++i)
        {
            for(int j = 0; j < n && flag; ++j)
            {
                if(i != j)
                {
                    double ca,cb;
                    Point A = s1[i], B = s2[j];
                    bool flag2 = true;

                    bool f1 = onSide( A, B, s1, n);
                    bool f2 = onSide( A, B, s2, n);

                    bool f3 = isCrossed2( A, B, s1[0], s2[0]) &&
                              isCrossed2( A, B, s1[1], s2[1]);

                    if(f3)
                    {
						printf("%d %d: %d %d %d\n", i, j, f1, f2, f3);

                        if( f1 && !f2 )
                        {
                            ca = shotPipes( A, B, s1, n);
                            ans = MAX( ans, ca );
                            flag2 = false;
                        }
                        else if( !f1 && f2 )
                        {
                            ca = shotPipes( A, B, s2, n);
                            ans = MAX(ans, ca );
                            flag2 = false;
                        }
                        else if( f1 && f2 )
                        {
                            ca = shotPipes( A, B, s1, n);
                            cb = shotPipes( A, B, s2, n);

                            ans = MAX(ans, MIN( ca, cb) );
                            flag2 = false;
                        }
						cout << ans << endl;
                    }
                    else if( f1 || f2)
                        flag2 = false;

                    if( flag2 )
                    {
                        flag = false;
                    }
                }
            }
        }

        if(flag)
        {
            printf("%.2lf\n", ans);
        }
        else
        {
            puts("Through all the pipe.");
        }

    }
}

int main()
{
    solve();
    return 0;
}
