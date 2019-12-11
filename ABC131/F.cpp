#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <utility>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll MOD = 1e9+7;
set<P> ten; //(x,y)を格納
set<int> hori[100001]; //yに対するx
set<int> vert[100001]; //xに対するy
int main()
{
	int n;
	ll ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		hori[y].insert(x);
		vert[x].insert(y);
		ten.insert(P(x,y));
	}
	for(int cnt=0;cnt<3;cnt++)
	{
	//下から順に調べる
	for(int i=0;i<100001;i++)
	{
		int cnt=0;
		auto preitr=hori[i].begin();
		for(auto itr=hori[i].begin();itr!=hori[i].end();itr++)
		{
			if(cnt==0)
			{
				cnt++;
				preitr=itr;
				continue;
			}
			int a=*preitr;
			int c=*itr;
			//aから調べる
			for(auto itr2=vert[a].begin();itr2!=vert[a].end();itr2++)
			{
				if(*itr2==i)
					continue;
				P tar=P(c,*itr2);
				if(ten.count(tar)==0)
				{
					ans++;
					ten.insert(tar);
					hori[*itr2].insert(c);
					vert[c].insert(*itr2);
				}
			}
			//cから調べる
			for(auto itr2=vert[c].begin();itr2!=vert[c].end();itr2++)
			{
				if(*itr2==i)
					continue;
				P tar=P(a,*itr2);
				if(ten.count(tar)==0)
				{
					ans++;
					ten.insert(tar);
					hori[*itr2].insert(a);
					vert[a].insert(*itr2);
				}
			}
			preitr=itr;
		}
	}
	}
	cout<<ans<<endl;
	return 0;
}