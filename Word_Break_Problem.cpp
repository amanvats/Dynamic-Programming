/*Given a dictionary of different words and a string, there are two tasks. First comment whether it is
possible to split the string into individuals words of the string. Second split the string into
constituent words*/
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
const ll MOD = (1e9+7);
vector<string> v; //to contain words of dictionary
bool dp[500][500];
string str=" ";
bool contains(int index, int length)
{
	string sub = str.substr(index,length);
	for(int i=0;i<v.size();i++)
	{
		if(v[i].compare(sub)==0){cout<<"AAAAA"<<'\n';return true;}
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int num;
	cin>>num; //number of words in dictionary
	for(int i=0;i<num;i++){string s; cin>>s;v.pb(s);
	}
	string s;cin>>s;	//string to split
	int n = s.length();
	str+=s; //final string to split is str. We have done this to make string 1 indexed
	/*Logic: We will be using bottom up approach. The approach goes like : dp[i][j] contains boolen value showing if it is possible to split string from i to j into constituent words. we will move from bottom
	to top in the sense of length like first checking if words of length 1 are possible,then 2, then 3 ans so on. Assume the dictionary have words like i,a,am,aman,vats and given string iamamanvats.
	dp[1][1]=true as 'a' is in the dictionary..similarly we do for each 1 length chars,..As we move for 2 letter words ,like suppose 'ia' for instance. It is not present in the dictionary, we will make partition
	of it to see if it consists of different constituent words, Here only one partition is possible..i,a.. */
	for(int i=1;i<=n;i++)
	{
		if(contains(i,1))	dp[i][i]=true;
		else dp[i][i]=false;
	}
	for(int len = 2;len<=n;len++)
	{
		for(int i=1;i<=(n-len+1);i++){
		int j = i+(len-1);
		if(contains(i,len))	{	dp[i][j]=true;
		}
		else
		{						//if the word is not present in the dictionary , we are partitioning it about different points. Say for example the word from 2 to 5 does not exist. Check for the 2-3 and 4-5.i.e.
			for(int k=i;k<(len);k++){	//if both of these exist, then 2-3 and 4-5 are two words and hence 2-5 forms a valid combination of words.If it doesn't then split it about 4(2-4 and 5th alone)...and so on..
				if(dp[i][k] && dp[k+1][j]){	dp[i][j]=true;	break;}
				else dp[i][j]=false;
			}
		}
	}
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)	cout<<dp[i][j]<<" ";
		cout<<'\n';
	}
	if(dp[1][n]==true)	cout<<"Yes"<<'\n';
	else cout<<"No"<<'\n';
return 0;
}
