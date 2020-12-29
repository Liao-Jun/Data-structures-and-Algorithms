#include <iostream>
#include <cmath>
#include <cstring>
 
using namespace std;
const int n=1e6+5;
int a[1000010];
void Eratosthenes_prime()
{
    int m=sqrt(n+0.5);
    for(int i=2;i<m;i++)
    {
        if(!a[i])
        {
            for(int j=i*i;j<n;j+=i)
                a[j]=1;
        }
    }
}
 
int main()
{
    memset(a,0,sizeof a);
    Eratosthenes_prime();
    for(int i=2;i<100;i++)
        if(a[i]==0)cout<<i<<endl;
    return 0;
}