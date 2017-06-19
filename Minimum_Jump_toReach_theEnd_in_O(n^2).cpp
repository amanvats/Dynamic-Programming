/*The question is same but this approach also give the minimun nuber of jumps required to reach the end.
Other than that it also helps us known the path we should follow for that..but it is slower than the last
one*/
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
int arr[10001];
int source[10001];
int dp[1000];
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int num;
	cin>>num;
	for(int i=0;i<num;i++)	cin>>arr[i];	
	dp[0]=0;
	source[0]=-1;
	for(int i=1;i<num;i++)	dp[i]=INF;
	for(int i=1;i<num;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(j+arr[j]>=i)
			{
				if(dp[i]>(dp[j]+1)){dp[i]=dp[j]+1;
					source[i]=j;
				}
			}
			else continue;
		}
	}
	int ans = dp[num-1];
	int k = num-1;
	vector<int>v;
	while(source[k]!=-1)
	{
		v.pb(source[k]);
		k=source[k];
	}
	vector<int>::iterator it;
	cout<<ans<<'\n';
	for(it= (--v.end());it>=v.begin();it--)	cout<<(*it)<<" ";
return 0;
}
