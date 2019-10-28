#include<bits/stdc++.h>
using namespace std;
#define MAX5 100010
#define MAX6 1000010
#define pb push_back
#define mp make_pair
typedef long long int ll;
int main()
{
    ll n;
    cin>>n;
    ll arr[n+10];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    ll dp[n+10];
    for(ll i=0;i<=n;i++)
        dp[i]=1;
    for(ll i=0;i<n-1;i++)
    {
        for(ll j=i+1;j<n;j++)
        {
            if(arr[i]>0 && arr[j]<0 && abs(arr[i])<abs(arr[j]) )
                dp[j]=max(dp[j],dp[i]+1);
            else if(arr[i]<0 && arr[j]>0 && abs(arr[i])<abs(arr[j]) )
                dp[j]=max(dp[j],dp[i]+1);
        }
    }
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        //cout<<dp[i]<<" ";
        ans=max(ans,dp[i]);
    }
    cout<<'\n';
    cout<<ans<<'\n';
return 0;
} 
