/* You are given an array of elements. You and other player can choose from ends of the array. Devise a strategy such that you end up collecting maximum sum of elements */
//Aman Vats
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
const ll MOD=(1e9+7);
pii dp[501][501];
int arr[501];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++)
	{
		dp[i][i].first = arr[i];
		dp[i][i].second = 0;
	}
	for(int len = 2;len<=n;len++)
	{
		for(int i=1;i<=(n-len+1);i++)
		{
			int j=i+(len-1);
			if((arr[i]+dp[i+1][j].second) > (arr[j]+dp[i][j-1].second))
			{
				dp[i][j].first = (arr[i]+dp[i+1][j].second);
				dp[i][j].second = (dp[i+1][j].first);
			}
			else
			{
				dp[i][j].first = (arr[j]+dp[i][j-1].second);
				dp[i][j].second = (dp[i][j-1].first);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)	cout<<dp[i][j].first<<","<<dp[i][j].second<<" ";
		cout<<'\n';
	}
	int winner_score = dp[1][n].first;
	int loser_score = dp[1][n].second;
	cout<<winner_score<<" "<<loser_score<<'\n';
return 0;
}
