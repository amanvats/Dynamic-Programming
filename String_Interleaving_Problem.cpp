/*Given three strings A,B and C, comment whether it is possible to make C using characters of string A
and B and keeping them in the same order.
For example:aaxaby can be made using aab and axy*/
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
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	string str1,str2,str3,s1=" ",s2=" ",s3=" ";
	cin>>str1>>str2>>str3;
	s1+=str1;s2+=str2;s3+=str3;
	dp[0][0]=true;
	for(int i=0;i<str2.length();i++){
		if(s3[i]==s2[i] && dp[0][i-1]==true)	dp[0][i]= true;
	}
	for(int i=0;i<str1.length();i++){
		if(s3[i]==s1[i] && dp[i-1][0]==true)	dp[i][0]=true;
	}
	for(int i=1;i<=str1.length();i++)
	{
		for(int j=1;j<=str2.length();j++)
		{
			if(s3[i+j]==s1[i])	dp[i][j]=dp[i-1][j];
			else if(s3[i+j]==s2[j])	dp[i][j]=dp[i][j-1];
			else	dp[i][j]=false;
		}
	}
	for(int i=0;i<s1.length();i++){
		for(int j=0;j<s2.length();j++)	cout<<dp[i][j]<<" ";
		cout<<'\n';
	}
	if(dp[str1.length()][str2.length()]==true)	cout<<"Yes"<<'\n';
	else cout<<"No"<<'\n';
return 0;
}
