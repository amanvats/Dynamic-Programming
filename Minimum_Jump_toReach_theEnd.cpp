/* Given an array, find minimum number to jumps to reach end of array, given you can jump at max as much
 as value at position in array. THere are two approaches to this problem. One takes O(n) to be solved 
 which is a bit tricky to solve. To understanc this O(n) solution visit
 https://stackoverflow.com/questions/27858356/how-to-find-minimum-number-of-jumps-to-reach-the-end-of-the
 -array-in-on-time       .Look at the first answer very carefully and try to apply manually on this array 
 to understand [2,3,1,1,2].
 Here i am mentioning the same O(n) solution. For O(n^2) soln, see tr tutorial.
 *Aman Vats */
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
 int arr[501];
 int main()
 {
 	ios_base::sync_with_stdio(false);cin.tie(NULL);
 	int num;
 	cin>>num; //number of elements in the array
	for(int i=0;i<num;i++)	cin>>arr[i];
	int maxReach=arr[0];
	int jump = 1;
	int steps = arr[0];
	for(int i=1;i<num;i++)
	{
		if(i==num-1)	break;
		maxReach = max(maxReach,i+arr[i]);
		steps--;
		if(steps==0)
		{
			jump++;
			steps  = maxReach-i;
		}	
	}
	cout<<jump<<'\n';
return 0;
 }
