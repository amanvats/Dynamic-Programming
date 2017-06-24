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
pii dp[501][501];	//dp[i][j].first constains the maximum value that the person making the first move will get if only arr indexed from i to j(included) is considered.dp[i][j].second contains max val second person
int arr[501];			//can get
int main()
{
	int n;
	cin>>n;
	//logic: We will make the table considering different lengths. Example: If u have 3,2,9,4..first consider all elements of length 1 i.e. 3 then 2 then 9...After that make the table for length = 2 i.e considering
	//2 at time like 3,2 then 2,9 then 9,4...similarly for 3 elements and then for 4.
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++)	
	{
		dp[i][i].first = arr[i];	//this loop will make the table for length = 1
		dp[i][i].second = 0;
	}
	for(int len = 2;len<=n;len++)
	{
		for(int i=1;i<=(n-len+1);i++)
		{
			int j=i+(len-1);
			if((arr[i]+dp[i+1][j].second) > (arr[j]+dp[i][j-1].second))//understand the working logic with an example. Suppose we are working for length 3 and we have elememts 3,2,9. The person making the first move
			{															//can either choose from left(ith) or right(jth). If he chooses from left, he can then get second of dp[i+1][j]. so net=arr[i]+dp[i+1][j].second
				dp[i][j].first = (arr[i]+dp[i+1][j].second);			//if he chooses from right he is bound to choose dp[i][j-1].second .So net = arr[j]+dp[i][j-1]
				dp[i][j].second = (dp[i+1][j].first);					//so first one should choose max of both the net
			}															//depending upon what the first player chooses , second player gets what is remaining
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
