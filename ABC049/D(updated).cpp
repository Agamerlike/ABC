#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> road[200000];
vector<int> rail[200000];

int ar[200000];
int br[200000];
int res[200000];

//道路の連結探索を再帰的に行う関数
void link_road(int n)
{
	for(int i=0;i<road[n].size();i++)
	{
		if(ar[road[n][i]]==ar[n])
		{
			continue;
		}else{
			ar[road[n][i]]=ar[n];
			link_road(road[n][i]);
		}
	}
	return;
}
//鉄道の連結探索を再帰的に行う関数
void link_rail(int n)
{
	for(int i=0;i<rail[n].size();i++)
	{
		if(br[rail[n][i]]==br[n])
		{
			continue;
		}else{
			br[rail[n][i]]=br[n];
			link_rail(rail[n][i]);
		}
	}
	return;
}

int main()
{
	int n,k,l;
	cin>>n>>k>>l;
	int p,q;
	map<int,pair<int,int>> link; //それぞれの街がどのような連結成分に属するか
	map<pair<int,int>,int> cnt; //同じ連結成分を持つ要素のカウント
	for(int i=0;i<n;i++)
	{
		ar[i]=-1;
		br[i]=-1;
		res[i]=0;
	}
	for(int i=0;i<k;i++)
	{
		cin>>p>>q;
		road[p-1].push_back(q-1);
		road[q-1].push_back(p-1);
	}
	for(int i=0;i<l;i++)
	{
		cin>>p>>q;
		rail[p-1].push_back(q-1);
		rail[q-1].push_back(p-1);
	}

	//道路の連結探索
	for(int i=0;i<n;i++)
	{
		if(ar[i]!=-1)
		{
			continue;
		}
		ar[i]=i;
		link_road(i);
	}
	//鉄道の連結探索
	for(int i=0;i<n;i++)
	{
		if(br[i]!=-1)
		{
			continue;
		}
		br[i]=i;
		link_rail(i);
	}

	//ペアの作成とグループごとの数え上げ
	for(int i=0;i<n;i++)
	{
		link[i]=pair<int,int>(ar[i],br[i]);
		cnt[pair<int,int>(ar[i],br[i])]+=1;
		//cerr<<link[i].first<<" "<<link[i].second<<endl;
	}
	//数え上げ
	for(int i=0;i<n;i++)
	{
		res[i]=cnt[link[i]];
	}
	//結果の出力
	for(int i=0;i<n;i++)
	{
		cout<<res[i]<<" ";
	}
	cout<<endl;
	return 0;
}
