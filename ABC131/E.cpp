#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll MOD = 1e9+7;
vector<P> hen;

int main()
{
	int n,k;
	ll ans=0;
	cin>>n>>k;
	int mx=(n-2)*(n-1)/2;//最大数
	cerr<<mx<<endl;
	if(k>mx)
	{
		cout<<-1<<endl;
	}else{
		for(int i=1;i<n;i++)
			hen.push_back(P(i,n));
		//潰す個数だけ辺を張る
		int cnt=0;
		bool f=true;
		if(k!=mx)
		{
			for(int i=1;i<n;i++)
			{
				for(int j=i+1;j<n;j++)
				{
					hen.push_back(P(i,j));
					cnt++;
					if(cnt==mx-k)
					{
						f=false;
						break;
					}
				}
				if(!f)
					break;
			}
		}
		cout<<hen.size()<<endl;
		for(int i=0;i<hen.size();i++)
			cout<<hen[i].first<<" "<<hen[i].second<<endl;
	}
	return 0;
}