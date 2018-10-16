#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;
double EPS = 1e-10; //誤差

ll a[100000];

class segtree
{
	public:
	int n;
	vector<ll> node;

	segtree(int size,ll v[])
	{
		n=1;
		while(n<size)
			n*=2;
		node.resize(2*n-1,1e8-1);
		//最下段に値を入れたあとに、下の段から順番に値を入れる
		//値を入れるには自分の子の2値を参照する
		for(int i=0;i<size;i++)
			node[i+n-1]=v[i];
		//今回は最小値
		for(int i=n-2;i>=0;i--)
			node[i]=min(node[2*i+1],node[2*i+2]);
	}

	//値の更新
	//node[k]をaにする
	void update(int k,int a)
	{
		k+=n-1;
		node[k]=a;
		while(k>0)
		{
			k=(k-1)/2;
			node[k]=min(node[k*2+1],node[k*2+2]);
		}
	}
	
	//値の取得
	//[a,b)中の要素の最小値を求める
	//k...現在自分がいるノードのインデックス
	//この関数単体での探索区間は[l,r) <- node[k]が覆える区間
	ll get(int a,int b,int k=0,int l=0,int r=-1)
	{
		//最初に呼び出されたときは探索区間[0,n)
		if(r<0)
			r=n;
		
		//[a,b)と[l,r)が交わらない...INFなどを返す（和の場合は0）
		if(a>=r || b<=l)
			return 1e8-1;
		//[a,b)が[l,r)を完全に被覆...そのままnode[k]を答えの計算に使う
		if(a<=l && b>=r)
			return node[k];
		
		//一部を被覆...子について探索する
		//左側の子をvl,右側の子をvrとする
		int vl=get(a,b,2*k+1,l,(l+r)/2);
		int vr=get(a,b,2*k+2,(l+r)/2,r);
		return min(vl,vr);
	}
}

int main()
{
	
}