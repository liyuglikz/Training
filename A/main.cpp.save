#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int r1,r2,l1,l2,k;
    scanf("%d %d %d %d %d",&l1,&r1,&l2,&r2,&k);
    if(l1<l2){
        if(r1<l2) cout<<'0'<<endl;
        else if(r1<r2)
            if(k>=l2&&k<=r1) cout<<r1-l2<<endl;
            else cout<<r1-l2+1<<endl;
        else
            if(k>=l2&&k<=r2)cout<<r2-l2<<endl;
            else cout<<r2-l2+1<<endl;
    }else{
        if(l1>r2)cout<<"0"<<endl;
        else if(r2<r1)
            if(k>=l1&&k<=l2) cout<<r2-l1<<endl;
            else cout<<r2-l1+1<<endl;
        else
            if(k>=l1&&k<=r1)cout<<r1-r1<<endl;
            else cout<<r1-l1+1<<endl;
    }return 0;
}
