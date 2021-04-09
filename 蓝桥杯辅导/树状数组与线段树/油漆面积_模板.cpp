#include<iostream>
#include<algorithm>
#include<string.h>
#define ls (rt<<1)
#define rs (rt<<1|1)
using namespace std;
const int maxn = 20005;

int cover[maxn];//存放i节点对应覆盖情况的值
double length[maxn];//存放区间i下的总长度
double yy[maxn];//存放离散后的y值，下标用lowerbound进行查找

struct ScanLine
{
    double x;//边的x坐标
    double upy,downy;//边的y坐标上，y坐标下
    int inout;//入边为1，出边为-1
    ScanLine(){}
    ScanLine(double x,double y1,double y2,int io):x(x),upy(y1),downy(y2),inout(io){}
}line[maxn];
bool cmp(ScanLine &a,ScanLine &b)//x排序函数
{
    return a.x<b.x;
}
void pushup(int l,int r,int rt)//pushup其实主要就思考在什么情况，需要更新哪些信息来维护线段树
{
    if(cover[rt]) length[rt] = yy[r]-yy[l];//如果某个节点的cover为正，那么这个点的长度
    else if(l+1==r) length[rt] = 0;//到了叶子节点
    else length[rt] = length[ls]+length[rs];
}
void update(int yl,int yr,int io,int l,int r,int rt)
{
    if(yl>r||yr<l) return ;//极端情况？
    if(yl<=l&&yr>=r)
    {
        cover[rt] += io;//根据出边入边，加上相应的值
        pushup(l,r,rt);
        return ;
    }
    if(l+1==r)return ;//到子节点
    int m = (l+r)>>1;
    if(yl<=m)
        update(yl,yr,io,l,m,ls);
    if(yr>m)
        update(yl,yr,io,m,r,rs);//这里不再是m+1,因为要进入类似[1,2][2,3]的叶子节点
    pushup(l,r,rt);
}

int main()
{
    //freopen("hdu 1542.txt","r",stdin);
    int n,T = 0;//矩形个数，样例个数
    while(scanf("%d",&n),n){
        int cnt = 0;
        double x1,x2,y1,y2;
        int yr,yl;
        int io;
        for(int i = 1;i<=n;++i)
        {
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);//输入数值
            line[++cnt] = ScanLine(x1,y2,y1,1);//给入边赋值
            yy[cnt] = y1;//获得y值
            line[++cnt] = ScanLine(x2,y2,y1,-1);//给出边赋值
            yy[cnt] = y2;//获得y的值
        }

        sort(yy+1,yy+cnt+1);//给yy排个序
        sort(line+1,line+cnt+1,cmp);//给line按照x轴方向从左到右排序
        int len = unique(yy+1,yy+cnt+1)-(yy+1);//进行离散化操作，unique返回重复位置指针，减去（头指针+1）是数组开始的地方得到数组长度
        //printf("%lf\n",yy[4]);
        memset(cover,0,sizeof(cover));
        memset(length,0,sizeof(length));
        double ans = 0;
        for(int i = 1;i<=cnt;++i)
        {
            //printf("%lf %lf %lf\n",length[1],line[i].x,line[i-1].x);
            ans += length[1]*(line[i].x-line[i-1].x);
            yl = lower_bound(yy+1,yy+len+1,line[i].downy)-yy;//基本和上同理
            yr = lower_bound(yy+1,yy+len+1,line[i].upy)-yy;
            io = line[i].inout;
            update(yl,yr,io,1,len,1);
            cout << ans << endl;//debug
        }
        printf("Test case #%d\nTotal explored area: %.2f\n\n",++T,ans);
    }
    return 0;
}
