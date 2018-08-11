#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <tuple>
using namespace std;
typedef long long ll;
ll MOD = 1e9+7;

int par[100000]; //親
int sz[100000]; //属してる頂点の数

//n要素で初期化
void init(int n)
{
	for(int i=0;i<n;i++)
	{
		par[i]=i;
		sz[i]=1;
	}
}

//木の根を求める
int find(int x)
{
	if(par[x]==x)
		return x;
	else
		return par[x]=find(par[x]);
}

//xとyの属する集合を併合
void unite(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y)
		return;
	
	if(sz[x]<sz[y])
	{
		par[x]=y;
		sz[y]+=sz[x];
	}else{
		par[y]=x;
		sz[x]+=sz[y];
	}
}

//xとyが同じ集合に属するか否か
bool same(int x,int y)
{
	return find(x)==find(y);
}

tuple<int,int,int> road[200000]; //y,a,b
tuple<int,int,int> que[100000]; //w,v,index

int ans[100000];

int main()
{
	int n,m,q;
	cin>>n>>m;
	init(n);
	fill(ans,ans+100000,0);
	for(int i=0;i<m;i++)
	{
		int a,b,y;
		cin>>a>>b>>y;
		road[i]=make_tuple(y,a,b);
	}
	sort(road,road+m);
	reverse(road,road+m);
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int v,w;
		cin>>v>>w;
		que[i]=make_tuple(w,v,i);
	}
	sort(que,que+q);
	reverse(que,que+q);
	int roadindex=0;//道のインデックス
	for(int i=0;i<q;i++)
	{
		//その人が渡れるようになる年代までの道を建設する
		while(get<0>(que[i])<get<0>(road[roadindex]) && roadindex<m)
		{
			unite(get<1>(road[roadindex]),get<2>(road[roadindex]));
			roadindex++;
		}
		ans[get<2>(que[i])]=sz[find(get<1>(que[i]))];
	}
	
	for(int i=0;i<q;i++)
		cout<<ans[i]<<endl;
	return 0;
}