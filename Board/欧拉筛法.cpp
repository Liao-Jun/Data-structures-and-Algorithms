#include <iostream>
#include <cstring>
 
using namespace std;
 
const int MAXN=3000001;
int prime[MAXN];//保存素数
bool vis[MAXN];
int Prime(int n)
{
	int cnt=0;
	memset(vis,0,sizeof(vis));
	for(int i=2;i<n;i++)
	{
		if(!vis[i])
		prime[cnt++]=i;
		for(int j=0;j<cnt&&i*prime[j]<n;j++)
		{
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)//关键
			break;
		}
	}
	return cnt;//返回小于n的素数的个数
}
int main()
{
    memset(vis,0,sizeof vis);
    cout<<Prime(MAXN)<<endl;
    for(int i=0;i<100;i++)
        cout<<prime[i]<<endl;
    return 0;
}