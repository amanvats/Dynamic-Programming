/*Coin changing problem. Find the minimum number of coins required to make a given sum using certain coins of specified denoominaions.
Aman Vats */
#include <bits/stdc++.h>
using namespace std;
#define mk make_pair
#define in insert
#define pb push_back
#define all(a) a.begin(),a.end()
#define pf push_front
#define pob pop_back
#define pof pop_front
#define bitcnt(x) __builtin_popcountll(x)
typedef long long int ll;typedef long int l;typedef pair<int,int> pii;
const ll INF=(1<<28);
int denominations[1000];
int arr[1000];
int dp[1000];
int main()
{
	for(int i=0;i<1000;i++)	{dp[i]=INF;arr[i]=-1;}
	dp[0]=0;
	int num_of_coins;
	cin>>num_of_coins;
	for(int i=0;i<num_of_coins;i++)
	{
		cin>>denominations[i];
	}
	int total;cin>>total;
	for(int i=0;i<num_of_coins;i++)
	{
		for(int j=1;j<=total;j++)
		{
			if(j>=denominations[i])
			{
				if(dp[j]>(1+dp[j-denominations[i]]))
				{
					dp[j]=(1+dp[j-denominations[i]]);
					arr[j]=i;
				}
			}
		}
	}
	vector<int> v;
	int k=total;
	while(arr[k]!=-1)
	{
		int index = arr[k];
		v.pb(denominations[index]);
		k-=denominations[index];
	}
	int ans= dp[total];
	cout<<ans<<'\n';
	for(int i=0;i<v.size();i++){cout<<v[i]<<" ";
	}
return 0;
}
