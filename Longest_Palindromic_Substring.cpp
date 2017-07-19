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
bool dp[501][501];	//dp[i][j] is storing wether the substring from index i to index j is a palindromuic sequence or not
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	string s;
	cin>>s;
	for(int i=0;i<501;i++){
		for(int j=0;j<501;j++)	dp[i][j]=false;		//initialised with false
	}
	int len  = s.length();
	for(int i=0;i<len;i++)	dp[i][i] = true;			//each element alone is palindrome in itself
	for(int i=0;i<len-1;i++){
		if(s[i]==s[i+1])	dp[i][i+1] = true;	//each substring of length 2 is palindromic if both the elements are same
	}
	//So, we are building up the table...bottom up approach.
	/*The approach of building is substring from i to j will be palindromic if the substring from i+1 and j-1 is palindromic and the elements at ith and jth position are equal.*/
	for(int lnth = 3; lnth<=len;lnth++){
		for(int i=0;i<(len-lnth+1);i++)
		{
			int j = i + lnth - 1;
			if(dp[i+1][j-1] && (s[i]==s[j]))	dp[i][j] = true;
			else dp[i][j] = false;
		}
	}
	int max = 0;
	//Now we will count that i,j pair whose dp[i][j] value is true and the difference between i and j is maximum.
	for(int i = 0;i<len;i++){
		for(int j = 0;j<len;j++){
			if(dp[i][j] == true){
				if(max<((j-i)+1)){	max = j-i+1;}
			}
		}
	}
	cout<<max<<'\n';
return 0;
}
