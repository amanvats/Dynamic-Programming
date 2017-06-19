//minimum number of steps required to change 1 string into another. You can replace,insert and remove 
//letter to do that.
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
const ll MOD = (1e9+7);
int dp[501][501];
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	string s1,s2,str1,str2;
	cin>>str1>>str2;//s1 is the string to convert to s2
	s1=" ";s2=" ";
	int len_1 = str1.length();
	int len_2 = str2.length(); 
	s1+=str1;s2+=str2;//MADE IT INDEX 1
	for(int i=0;i<=len_1;i++)	dp[0][i]=i;
	for(int i=0;i<=len_2;i++)	dp[i][0]=i;
	for(int i=1;i<=len_2;i++)
	{
		for(int j=1;j<=len_1;j++)
		{
			if(s1[j]==s2[i])	{
			dp[i][j]=dp[i-1][j-1];}
			else dp[i][j] = (min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1])))+1;
		}
	}
	cout<<'\n';
	/*for(int i=0;i<=len_2;i++)
	{
		for(int j=0;j<=len_1;j++)	cout<<dp[i][j]<<" ";
		cout<<'\n';
	}*/
	int ans = dp[len_2][len_1];
	cout<<ans<<'\n';
return 0;
}
