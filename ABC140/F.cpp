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
int n;
ll s[1<<18];
vector<ll> v[2];
multiset<ll> st;
int main()
{
	bool ans=true;
	cin>>n;
	for(int i=0;i<(1<<n);i++)
	{
		cin>>s[i];
		st.insert(s[i]);
	}
	sort(s,s+(1<<n));
	reverse(s,s+(1<<n));
	//最初は最大で固定
	v[0].push_back(s[0]);
	st.erase(st.find(s[0]));
	int cnt=0;
	while(st.size()>0)
	{
		cnt++;
		//cerr<<"loop"<<cnt<<endl;
		v[cnt&1].clear();
		for(int i=0;i<v[(cnt+1)&1].size();i++)
		{
			v[cnt&1].push_back(v[(cnt+1)&1][i]);
			//上回らない最大の数を探す
			auto itr=st.lower_bound(v[(cnt+1)&1][i]);
			if(itr==st.begin())
			{
				ans=false;
				break;
			}
			itr--;
			//cerr<<(*itr)<<endl;
			v[cnt&1].push_back(*itr);
			st.erase(itr);
		}
		if(!ans)
			break;
		sort(v[cnt&1].begin(),v[cnt&1].end());
		reverse(v[cnt&1].begin(),v[cnt&1].end());
	}
	if(ans)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}