/* Given a set of non negative numbers ,you have to tell whether it is possible to choose a set of numbe
s to give a specific sum. Please note that the question may seem to be coin changing problem at once. It
is in a way but the only difference is the fact that in case of coins you had infinite coins of a given
denominations, here there are only one element of a given value.*/
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
bool dp[501][501];
int arr[501];
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int total;	//total sum to be made
	int num;	//total number of elements
	cin>>num;
	for(int i=0;i<num;i++){
		cin>>arr[i];
	}
	cin>>total;
	for(int i=0;i<num;i++)
	{
		dp[i][0]=true;
	}
	for(int i=1;i<=total;i++){
		if(i==arr[0])	dp[0][i]=true;
		else dp[0][i] = false;
	}
	for(int i=1;i<num;i++)
	{
		for(int j=1;j<=total;j++)
		{
				if(dp[i-1][j]==true)	dp[i][j]=true;
				else
				{
					if(j>=arr[i])
					dp[i][j] = dp[i-1][j-arr[i]];
				}
		}
	}
	/*for(int i=0;i<num;i++){
		for(int j=0;j<=total;j++)	cout<<dp[i][j]<<" ";
		cout<<'\n';
	}*/
	if(dp[num-1][total]==true)	cout<<"Yes"<<'\n';
	else cout<<"No"<<'\n';
	return 0;
}
