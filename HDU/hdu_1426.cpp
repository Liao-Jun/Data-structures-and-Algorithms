#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int map[10][10];
int num;//记录有多少个数需要填
struct zb//用来存储坐标
{
    int x,y;
} a[100];
int jc(int k,int step)//判断能否深搜的条件
{
    int x,y;
    for(int i=0; i<9; i++)
        if(map[a[step].x][i]==k||map[i][a[step].y]==k)//判断这个数所处的行和列有没有出现重复的数
            return 0;
    //这个很重要，想一想为什么这么做
    x=(a[step].x/3)*3;
    y=(a[step].y/3)*3;
    //printf("a[step(%d)].x=%d,/3=%d  ",step,a[step].x,(a[step].x/3)*3);
    //printf("a[step(%d)].y=%d,/3=%d\n",step,a[step].y,(a[step].y/3)*3);
    for(int i=x; i<x+3; i++)//判断这个数所处的的那个小九宫格里面有没有重复的数
        for(int j=y; j<y+3; j++)
            if(map[i][j]==k)
                return 0;
    return 1;
}
void dfs(int step)
{
    if(step==num)//如果搜到了
    {
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<8; j++)
                cout<<map[i][j]<<" ";
            cout<<map[i][8]<<endl;//直接在这里输出结果，要不然会发生可怕的事~
        }
        return;
    }
    for(int i=1; i<=9; i++)//试这9个数
    {
        if(jc(i,step))//判断能否填数
        {
            map[a[step].x][a[step].y]=i;//如果满足条件就填数
            dfs(step+1);//搜索下一个数的填法
            map[a[step].x][a[step].y]=0;//还原地图
        }
    }
    return;
}
int main()
{
    int q=0;
    char s;
    while(cin>>s)//输入字符
    {
        num=0;
        if(s=='?')//对第一个字符进行特判
        {
            a[num].x=0;
            a[num].y=0;
            num++;
            map[0][0]=0;
        }
        else
            map[0][0]=s-'0';
        for(int i=0; i<9; i++)//输入后面的数，并把他们转换成整型,没走过的用0代替
        {
            for(int j=0; j<9; j++)
            {
                if(i==0&&j==0)continue;
                cin>>s;
                if(s=='?')
                {
                    a[num].x=i;
                    a[num].y=j;
                    num++;
                    map[i][j]=0;
                }
                else
                    map[i][j]=s-'0';
            }
        }
        if(q++)//用来换行
            cout<<endl;
        dfs(0);//从0开始
    }
    return 0;
}