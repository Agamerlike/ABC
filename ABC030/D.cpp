#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;

//超でかい整数nを文字列型で表してmで割った剰余を求める
ll longmod(string n,ll m)
{
	ll res=0;
	for(int i=0;i<n.size();i++)
	{
		res*=10;
		res+=(n[i]-'0')+m;
		res%=m;
	}
	if(res>m)
		res-=m;
	return  res;
}

int b[100000];
int used[100000];
int main()
{
	int n,a;
	string k;
	int ans=0;
	cin>>n>>a;
	cin>>k;
	a--;
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
		b[i]--;
	}
	fill(used,used+100000,-1);
	used[a]=0;
	int index=a;
	int cnt=0;//経路記録用　その後は閉路の長さ
	int first,last;//閉路の最初と最後のインデックス
	//閉路を検出する
	while(1)
	{
		if(used[b[index]]!=-1)
		{
			last=index;
			first=b[index];
			break;
		}
		cnt++;
		index=b[index];
		used[index]=cnt;
		//cerr<<cnt<<" "<<index<<endl;
	}
	cnt=used[last]-used[first]+1;//閉路の長さ
	//cerr<<cnt<<endl;
	int tail=used[last]+1;//閉路に至るまでの経路の長さ
	if(k.size()<=8)
	{
		ll kk=stoi(k);
		//閉路に入るまでに終了する場合そのまま
		if(kk<tail)
		{
			ans=used[kk];
		}else{
			kk%=cnt;//ループ分の剰余を取る
			kk-=tail;//しっぽを取る
			kk%=cnt;
			if(kk<0)
				kk+=cnt;//kkを0以上にする
			ans=first;//ここから先は手計算
			for(int i=0;i<kk;i++)
			{
				ans=b[ans];
			}
		}
	}else{
		ll kk=longmod(k,cnt);
		//このケースでは確実にループに入る
		kk-=tail;//しっぽを取る
		kk%=cnt;
		if(kk<0)
			kk+=cnt;//kkを0以上にする
		ans=first;//ここから先は手計算
		for(int i=0;i<kk;i++)
		{
			ans=b[ans];
		}
	}
	ans++;
	cout<<ans<<endl;
	return 0;
}