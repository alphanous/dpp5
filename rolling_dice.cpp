#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dp[100][100];
int rolling(int n, int t, int x)
{
    memset(dp, -1, sizeof(dp));
    if(t==0 && x==0)
    {
        return 1;
    }
    if(x<0 || t==0)
    {
        return 0;
    }
    if(dp[t][x]!=-1)
    {
        return dp[t][x];
    }
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        ans+=rolling(n,t-1,x-i);
    }
    return dp[t][x]=ans;
}
int main()
{
    int n, t, x;
    cin>>n>>t>>x;
    cout<<rolling(n,t,x)<<endl;
    return 0;
}