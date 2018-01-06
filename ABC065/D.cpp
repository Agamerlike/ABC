#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

//辺データ
//拡張可能コンストラクタによってpush_backする
class e
{
	public:
	long long cost;//かかるコスト
	int next;//行き先
	e(long long c, int n)
	{
		cost = c;
		next = n;
	}
};

vector<e> v[100000];
pair<int,int> x[100000];//データ構造(頂点名,x座標)
pair<int,int> y[100000];//データ構造(頂点名,y座標)

//プリム法で使うデータ構造
long long mincost[100000];//集合Xからの最小コスト
bool used[100000];//頂点iがXに含まれているか
typedef pair<long long,int> P;//firstは最短距離、secondは頂点の番号

int main()
{
	int n;
	long long ans=0;
	priority_queue<P, vector<P>, greater<P>> que; //priority_queueを使って最短距離が短い順に取り出せるようにする

	cin>>n;
	for(int i=0;i<n;i++)
	{
		x[i].first=i;
		y[i].first=i;
		mincost[i]=1e9+7;
		used[i]=false;
		cin>>x[i].second>>y[i].second;
	}
	//x座標およびy座標昇順でソート
	sort(x,x+n,[](const pair<int,int> &x, const pair<int,int> &y){return x.second<y.second;});
	sort(y,y+n,[](const pair<int,int> &x, const pair<int,int> &y){return x.second<y.second;});
	//それぞれの辺をグラフに付け足していく
	for(int i=0;i<n-1;i++)
	{
		//cerr<<x[i].first<<"<>"<<x[i+1].first<<" "<<y[i].first<<"<>"<<y[i+1].first<<endl;
		v[x[i].first].push_back(e((long long)(x[i+1].second-x[i].second),x[i+1].first));
		v[x[i+1].first].push_back(e((long long)(x[i+1].second-x[i].second),x[i].first));
		v[y[i].first].push_back(e((long long)(y[i+1].second-y[i].second),y[i+1].first));
		v[y[i+1].first].push_back(e((long long)(y[i+1].second-y[i].second),y[i].first));
	}
	//cerr<<"input done"<<endl;
	//プリム法を使って最小全域木を求める
	mincost[0]=0;
	que.push(P(0,0));
	while(que.empty()==false)
	{
		P p = que.top();
		que.pop();
		int f = p.second;//フラグ兼追加する頂点
		//すでにより短い経路が見つかっているなら探す必要はない
		if(mincost[f]<p.first)
		{
			continue;
		}
		//Xに属さない頂点のうちXからの辺のコストが最小になる頂点を探す
		for(int i=0;i<n;i++)
		{
			if(used[i]==false && mincost[i]<mincost[f])
			{
				f=i;
			}
		}
		
		used[f]=true; //頂点fをXに追加
		ans += mincost[f];//辺のコストを加える(mincost[0]=0より最初は必ず0かつ0番目の頂点が加えられる)
		//cerr<<f<<" "<<ans<<endl;
		//Xに属している頂点から伸びる辺を使ってmincostを更新
		for(int i=0;i<v[f].size();i++)
		{
			if(used[v[f][i].next]==false && mincost[v[f][i].next] > v[f][i].cost)
			{
				mincost[v[f][i].next] = v[f][i].cost;
				que.push(P(mincost[v[f][i].next],v[f][i].next));
			}
			//mincost[v[f][j].next] = min(mincost[v[f][j].next], v[f][j].cost);
		}
	}
	cout<<ans<<endl;
	return 0;
}