#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <functional>
#include <map>
using namespace std;
typedef long long ll;

class Edge
{
	public:
	int cost;
	int from;
	int to;

	Edge(int n,int c)
	{
		to=n;
		cost=c;
	}

	Edge(int f,int t,int c)
	{
		from=f;
		to=t;
		cost=c;
	}
};

vector<Edge> g[100000];
pair<int,int> hako[100000];
int mp[100000]; //そのインデックスからはいくつ繋げられるか

int main()
{
	int n;
	int ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int w,h;
		cin>>w>>h;
		hako[i]=make_pair(w,h);
	}
	sort(hako,hako+n);
	fill(mp,mp+100000,-1);
	for(int i=n-1;i>-1;i--)
	{
		int noww=hako[i].first;
		int nowh=hako[i].second;
		int cnt=1;
		for(int j=i+1;j<n;j++)
		{
			if(noww<hako[j].first && nowh<hako[j].second)
			{
				noww=hako[j].first;
				nowh=hako[j].second;
				//すでに記録されているならそれを加算してループ終了
				if(mp[j]!=-1)
				{
					cnt+=mp[j];
					break;
				}else{
					cnt++;
				}
			}
		}
		mp[i]=cnt;
	}

	//mpの中で最大のものが答え
	for(int i=0;i<n;i++)
	{
		if(ans<mp[i])
			ans=mp[i];
	}
	cout<<ans<<endl;
	return 0;
}