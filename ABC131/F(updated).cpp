#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
using namespace std;
typedef long long ll;

class Edge
{
	public:
	int to,cost;

	Edge(int t,int c)
	{
		to=t;cost=c;
	}
};
vector<Edge> g[200010];
bool used[200010];
ll vecx=0; //連結成分中のx側の個数
ll vecy=0;
//連結成分の深さを判定する
int saiki(int now,int dep)
{
	//cerr<<dep<<endl;
	int ret=dep;
	used[now]=true;
	if(now<1e5)
		vecx++;
	else
		vecy++;
	for(int i=0;i<g[now].size();i++)
	{
		Edge e=g[now][i];
		if(!used[e.to])
			ret=max(ret,saiki(e.to,dep+1));
	}
	return ret;
}

int main()
{
	int n;
	ll ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		x--;y--;
		y+=1e5;
		g[x].push_back(Edge(y,1));
		g[y].push_back(Edge(x,1));
	}
	fill(used,used+200010,false);
	//全要素について深さを判定する
	//2以上なら条件を満たしているので求める
	cerr<<"init done"<<endl;
	for(int i=0;i<200000;i++)
	{
		if(!used[i])
		{
			vecx=0;vecy=0;
			int tmp=saiki(i,0);
			//cerr<<vecx<<" "<<vecy<<endl;
			ans+=vecx*vecy;
		}
	}
	cout<<max(0LL,ans-n)<<endl;
	return 0;
}