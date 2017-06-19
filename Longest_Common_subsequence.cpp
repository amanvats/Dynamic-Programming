//longest common subsequence using dynamic programming

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
/* Explanation: suppose i have string 1 'acbcf' and another string 'abcdcf' .Yes the answer is 4 'abcf'. if i just take first element from both, the answer till that point is 1.Now take a of first and abc of 
second,answer is 1 onl*/
int dp[100][100];
int main()
{
	string s1,s2,str;
	cin>>str;
	int length_1=str.length();
	s1=" ";s1+=str;
	cin>>str;
	int length_2=str.length();
	s2=" ";s2+=str;
	for(int i=0;i<=length_1;i++)	dp[0][i]=0;
	for(int i=0;i<=length_2;i++)	dp[i][0]=0;
	int max_len = 0;
	for(int i=1;i<=length_2;i++)
	{
		for(int j=1;j<=length_1;j++)
		{
			if(s1[j]==s2[i]){	dp[i][j] = dp[i-1][j-1] + 1;}
			else {	dp[i][j] = max(dp[i-1][j],dp[i][j-1]);}
		}
	}
	max_len = dp[length_2][length_1];
	for(int i=0;i<=length_2;i++)
	{
		for(int j=0;j<=length_1;j++){cout<<dp[i][j]<<" ";
		}
	}
	cout<<'\n'<<max_len<<'\n';
return 0;	
}
