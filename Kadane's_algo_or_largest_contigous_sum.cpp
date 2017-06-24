/*Kadane's algorithm or the algorithm for finding the longest contiguous sum
Aman Vats*/
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
int arr[10000];
int dp[10000];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	dp[0]=arr[0];
	/*It follows very simple logic.for any ith element of an array,maximum contiguous sum is formed either when that element is included or excluded*/
	for(int i=1;i<n;i++)
	{
		dp[i]=max((dp[i-1]+arr[i]),arr[i]);
	}
	int ans=arr[0];
	for(int i=0;i<n;i++)
	{
			cout<<dp[i]<<'\n';
			ans=max(ans,dp[i]);
	}
	cout<<ans<<'\n';
return 0;
}
