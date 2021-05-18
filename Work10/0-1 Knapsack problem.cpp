#include <iostream>
#include <string>
//#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define dep(i,a,b) for(int i=a;i>=b;--i)
const int maxn=1e5+50;
int a[maxn],dp[maxn],n;
int main()
{
    int n,k;cin>>n>>k;//
    rep(i,1,n) cin>>a[i];
    rep(i,1,n)
    {
        dep(j,k,a[i])
        {
            dp[j]=max(dp[j],dp[j-a[i]]+1);
        }
    }
    cout<<dp[k]<<endl;
    
    return 0;
 }
