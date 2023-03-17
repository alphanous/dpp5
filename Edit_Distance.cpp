#include<bits/stdc++.h>
using namespace std;
#define ll long long
int edit(string s1, string s2, int n, int m)
{
    int dp[n+1][m+1];
    memset(dp, -1, sizeof(dp));
    if(n==0)
    {
        return m;
    }
    if(m==0)
    {
        return n;
    }
    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    if(s1[n-1]==s2[m-1])
    {
        return dp[n][m] = edit(s1, s2, n-1, m-1);
    }
    else{
        int min1 = edit(s1,s2,n,m-1);
        int min2 = edit(s1,s2,n-1,m);
        int min3 = edit(s1,s2,n-1,m-1);
        int mini = min(min(min1,min2),min3)+1;
        return dp[n][m] = mini;
    }
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int n = s1.size();
    int m = s2.size();
    cout<<edit(s1,s2,n,m)<<endl;
    return 0;
}