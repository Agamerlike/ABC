#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
#include <set>
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;
int p[100000];
ll b[100001];//iはpの中でどこ
multiset<int> st;
int main()
{
	int n;
	ll ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
		b[p[i]]=i;
	}
	st.insert(-1);
	st.insert(-1);
	st.insert(n);
	st.insert(n);
	for(int i=n-1;i>0;i--)
	{
		st.insert(b[i+1]);
		auto r=st.upper_bound(b[i]);
		auto l=st.lower_bound(b[i]);
		l--;
		ll b1=*r;r++;ll b2=*r;
		ll s1=*l;l--;ll s2=*l;
		//cerr<<s2<<" "<<s1<<" "<<b1<<" "<<b2<<endl;
		ans+=i*((b2-b1)*(b[i]-s1)+(b1-b[i])*(s1-s2));
		//cerr<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}