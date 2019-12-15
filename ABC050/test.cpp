#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll MOD = 1e9+7;
set<P> st;
int main()
{
	ll n;
	cin>>n;
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<n-i+1;j++)
		{
			st.insert(P(i+j,i^j));
		}
	}
	cout<<st.size()<<endl;
	for(auto itr=st.begin();itr!=st.end();itr++)
		cout<<(*itr).first<<" "<<(*itr).second<<endl;
	return 0;
}