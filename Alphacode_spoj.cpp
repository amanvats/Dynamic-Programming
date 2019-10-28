#include<bits/stdc++.h>
using namespace std;
#define MAX5 100010
#define MAX6 1000010
#define pb push_back
#define pf push_front
#define mp make_pair
const int inf=0x7FFFFFFF;
#define all(a) a.begin(),a.end()
typedef long long int ll;typedef long int l;typedef pair<int,int> pii;
ll big_mod(string str,ll mvar)
{
    ll ans=0;
    for(ll i=0;i<str.length();i++)
    {
        ans=(ans*10+(int)str[i]-'0')%mvar;
    }
return ans;
}
ll dp[10000];
void initial()
{
    for(int i=0;i<10000;i++)
        dp[i]=0;
}
ll func(string str)
{
    dp[0]=1;
    dp[1]=1;
    for(ll i=1;i<str.size();i++)
    {
            if(str[i]!='0' && str[i-1]!='0' && str[i+1]!='0' && ((int)str[i]-'0'+((int)str[i-1]-'0')*10)<=26)
            {
                dp[i+1]=dp[i]+dp[i-1];
            }
            else
            {
                dp[i+1]=dp[i];
            }
    }
    return dp[str.size()];
}
int main()
{
    while(1)
    {
        initial();
        string str;
        cin>>str;
        if(str[0]=='0') 
            break;
        else
        {
            cout<<func(str)<<'\n';
        }
    }
return 0;
} 
