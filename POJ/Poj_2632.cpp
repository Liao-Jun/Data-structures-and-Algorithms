#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stack>
#include<map>
#include<vector>
#include<set>
using namespace std;
const int MAX=1e2+10;
const double eps=1e-6;
#define INF 0x7fffffff
#define ll long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define mst(a) memset(a,0,sizeof(a))
#define mstn(a,n) memset(a,n,sizeof(a))
struct num{int x,y,fac;}a[MAX];
//bool cmp(const num &x, const num &y){return x.l==y.l?x.r<y.r:x.l<y.l;}
int flag,mx,my,n,m;

void wrong(int x,int y,int i)
{
    if(x==0||x==mx+1||y==0||y==my+1)
    printf("Robot %d crashes into the wall\n",i),flag=0;
    else
    {
        int d=0;
        FOR(j,1,n)
        {
            if(j==i) continue;
            else if(a[j].x==x&&a[j].y==y)
            d=j;
        }
        if(d)
        {
            printf("Robot %d crashes into robot %d\n",i,d);
            flag=0;
        }
    }    
}

void turn(int i,char ch,int t)
{
    if(!flag) return;
    if(ch=='L')
    a[i].fac=(a[i].fac-t%4+4)%4;
    else if(ch=='R')
    a[i].fac=(a[i].fac+t%4)%4;
    else
    while(t--)
    {
        if(a[i].fac==0)
        a[i].y++;
        if(a[i].fac==1)
        a[i].x++;
        if(a[i].fac==2)
        a[i].y--;
        if(a[i].fac==3)
        a[i].x--;
        wrong(a[i].x,a[i].y,i);
        if(!flag)
        break;
    }
}

int main()
{
    int T,x,y;
    char ch;
    cin>>T;
    while(T--)
    {
        cin>>mx>>my;
        flag=1;
        cin>>n>>m;
        FOR(i,1,n)
        {
            cin>>x>>y>>ch;
            a[i].x=x,a[i].y=y;
            if(ch=='N') a[i].fac=0;
            if(ch=='E') a[i].fac=1;
            if(ch=='S') a[i].fac=2;
            if(ch=='W') a[i].fac=3;
        }
        FOR(i,1,m)
        {
            int num,t;
            cin>>num>>ch>>t;
            if(flag)
            turn(num,ch,t);
        }
        if(flag)
        cout<<"OK"<<endl;
    }
    return 0;
 }

 //https://vjudge.net/problem/POJ-2632