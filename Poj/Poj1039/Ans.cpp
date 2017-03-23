#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <math.h>

using namespace std;

const double eps = 1e-8;
int sgn(double x)
{
    if(fabs(x) < eps)return 0;
    if(x < 0)return -1;
    else return 1;
}
struct Point
{
    double x,y;
    Point(){}
    Point(double _x,double _y)
    {
        x = _x;y = _y;
    }
    Point operator -(const Point &b)const
    {
        return Point(x - b.x,y - b.y);
    }
    //叉积
    double operator ^(const Point &b)const
    {
        return x*b.y - y*b.x;
    }
    //点积
    double operator *(const Point &b)const
    {
        return x*b.x + y*b.y;
    }
    void input()
    {
        scanf("%lf%lf",&x,&y);
    }
};
struct Line
{
    Point s,e;
    Line(){}
    Line(Point _s,Point _e)
    {
        s = _s;e = _e;
    }
    //两直线相交求交点
    //第一个值为0表示直线重合，为1表示平行，为0表示相交,为2是相交
    //只有第一个值为2时，交点才有意义
    pair<int,Point> operator &(const Line &b)const
    {
        Point res = s;
        if(sgn((s-e)^(b.s-b.e)) == 0)
        {
            if(sgn((s-b.e)^(b.s-b.e)) == 0)
                return make_pair(0,res);//重合
            else return make_pair(1,res);//平行
        }
        double t = ((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));
        res.x += (e.x-s.x)*t;
        res.y += (e.y-s.y)*t;
        return make_pair(2,res);
    }
};
//判断直线和线段相交
bool Seg_inter_line(Line l1,Line l2) //判断直线l1和线段l2是否相交
{
    return sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e)) <= 0;
}

Point up[100],down[100];
int main()
{
    int n;
    while(scanf("%d",&n) == 1 && n)
    {
        for(int i = 0;i < n;i++)
        {
            up[i].input();
            down[i] = up[i];
            down[i].y -= 1;
        }
        bool flag = false;//穿过所有的标记
        double ans = -10000000.0;
        int k;
        for(int i = 0;i < n;i++)
        {
            for(int j = i+1;j < n;j++)
            {
                for(k = 0;k < n;k++)
                    if(Seg_inter_line(Line(up[i],down[j]),Line(up[k],down[k])) == false)
                        break;
                if(k >= n)
                {
                    flag = true;
                    break;
                }
                if(k > max(i,j))
                {
                    if(Seg_inter_line(Line(up[i],down[j]),Line(up[k-1],up[k])))
                    {
                        pair<int,Point>pr = Line(up[i],down[j])&Line(up[k-1],up[k]);
                        Point p = pr.second;
                        ans = max(ans,p.x);
                    }
                    if(Seg_inter_line(Line(up[i],down[j]),Line(down[k-1],down[k])))
                    {
                        pair<int,Point>pr = Line(up[i],down[j])&Line(down[k-1],down[k]);
                        Point p = pr.second;
                        ans = max(ans,p.x);
                    }
                }

                for(k = 0;k < n;k++)
                    if(Seg_inter_line(Line(down[i],up[j]),Line(up[k],down[k])) == false)
                        break;
                if(k >= n)
                {
                    flag = true;
                    break;
                }
                if(k > max(i,j))
                {
                    if(Seg_inter_line(Line(down[i],up[j]),Line(up[k-1],up[k])))
                    {
                        pair<int,Point>pr = Line(down[i],up[j])&Line(up[k-1],up[k]);
                        Point p = pr.second;
                        ans = max(ans,p.x);
                    }
                    if(Seg_inter_line(Line(down[i],up[j]),Line(down[k-1],down[k])))
                    {
                        pair<int,Point>pr = Line(down[i],up[j])&Line(down[k-1],down[k]);
                        Point p = pr.second;
                        ans = max(ans,p.x);
                    }
                }
            }
            if(flag)break;
        }
        if(flag)printf("Through all the pipe.\n");
        else printf("%.2lf\n",ans);
    }
    return 0;
}
