/*Longest increasing subsequence(LIS) in O(n^2). Please note that their is an algorithm to solve this in O(nlogn) too..
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
int arr[1000];
int dp[1000];
int main()
{
	int n;cin>>n;
	for(int i=0;i<n;i++){
		dp[i]=1;
	}
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=1;i<n;i++)
	{								//for every element at i,iterate j from 0 till that element. Now, if the element at j is lesser than that at i, arr[i] is a potential member of lis
		for(int j=0;j<i;j++)
		{
			if(arr[i]>arr[j]){	dp[i]=max(dp[i],(dp[j]+1));	}//in this case assign max of what is already there or what can be formed considering arr[j]
		}
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		cout<<dp[i]<<'\n';
		ans=max(ans,dp[i]);
	}
	cout<<ans<<'\n';
return 0;
}
