#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define M 2002002
using namespace std;
struct abcd
{
    int x,y,num,pos,ans;
    abcd() {}
    abcd(int X,int Y,int Num);
    bool operator <(const abcd &y)const
    {
        return x < y.x;
    }
} q[200200],nq[200200];

int num,w,n,ans;
int c[M],tim[M],T;

void update(int x,int y)
{
    for(; x<=w; x+=x&-x)
    {
        if(tim[x]!=T)
            c[x]=0;
        tim[x]=T;
        c[x]+=y;
    }
}

int getans(int x)
{
    int re=0;
    for(; x; x-=x&-x)
        if(tim[x]==T)
            re+=c[x];
    return re;
}

bool cmp(const abcd &x,const abcd &y)
{
    return x.pos < y.pos;
}

abcd :: abcd(int X,int Y,int Num)
{
    x=X;
    y=Y;
    num=Num;
    pos=n;
    ans=0;
}

void CDQ(int l,int r)
{
    int i,j,mid=l+r>>1;
    int l1=l,l2=mid+1;
    if(l==r)
        return ;
    for(i=l; i<=r; i++)
    {
        if(q[i].pos<=mid)
            nq[l1++]=q[i];
        else
            nq[l2++]=q[i];
    }
    memcpy( q+l, nq+l, sizeof(q[0])*(r-l+1) );
    CDQ(l,mid);
    j=l;
    ++T;
    for(i=mid+1; i<=r; i++)
    {
        for(; q[j].x<=q[i].x&&j<=mid; j++)
            if(q[j].num!=19980402)
                update(q[j].y,q[j].num);
        if(q[i].num==19980402)
            q[i].ans+=getans(q[i].y);
    }
    CDQ(mid+1,r);
    l1=l;
    l2=mid+1;
    for(i=l; i<=r; i++)
    {
        if(q[l1]<q[l2]&&l1<=mid||l2>r)
            nq[i]=q[l1++];
        else
            nq[i]=q[l2++];
    }
    memcpy( q+l, nq+l, sizeof(q[0])*(r-l+1) );
}

int main()
{
    int i,p,x,y,z,x1,y1,x2,y2;
    cin>>num>>w;
    while(scanf("%d",&p),p^3)
    {
        if(p==1)
            scanf("%d%d%d",&x,&y,&z),q[++n]=abcd(x,y,z);
        else
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            q[++n]=abcd(x1-1,y1-1,19980402);
            q[++n]=abcd(x1-1,y2,19980402);
            q[++n]=abcd(x2,y1-1,19980402);
            q[++n]=abcd(x2,y2,19980402);
        }
    }

    sort(q+1,q+n+1);
    CDQ(1,n);
    sort(q+1,q+n+1,cmp);

    for(i=1; i<=n; i++)
        if(q[i].num==19980402)
        {

            ans=0;
            ans+=q[i++].ans;
            ans-=q[i++].ans;
            ans-=q[i++].ans;
            ans+=q[i  ].ans;

            printf("%d\n",ans);
        }
	return 0;
}
