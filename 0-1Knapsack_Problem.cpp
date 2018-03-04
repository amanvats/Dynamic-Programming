/* You are Given a bag which can only take certain weight W. Given list of items with their weights and 
price. How do you fill this bag to maximize value of items in the bag.The bag is called knapsack.*/
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
int weight[10001];	//array to keep the weight of different items
int val[10001];	//to keep the value associated with different items
int dp[1001][1001];	//for tabulation of data used for bottom up solution
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int max_wt;	//maximum possible weight that the knapsack can hold
	int num;	//number of elements
	cin>>num;
	cin>>max_wt;
	for(int i=0;i<num;i++)	cin>>weight[i];
	for(int i=0;i<num;i++)	cin>>val[i];
	for(int i=0;i<=num;i++)	dp[i][0] = 0;	
	for(int j=1;j<=max_wt;j++){
		if(weight[0]>j)	dp[0][j]=0;
		else dp[0][j]=val[0];
	}
	for(int i=1;i<num;i++)
	{
		for(int j=1;j<=max_wt;j++)
		{
			if(weight[i]>j)	dp[i][j]=dp[i-1][j];
			else dp[i][j]=max((val[i]+dp[i-1][j-weight[i]]),dp[i-1][j]);
		}
	}
	/*for(int i=0;i<num;i++)
	{
		for(int j=0;j<=max_wt;j++)	cout<<dp[i][j]<<" ";
		cout<<'\n';
	}*/
	int ans = dp[num-1][max_wt];
	cout<<ans<<'\n';
return 0;
}
