#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
class segtree
{
  public:
  int depth;//セグ木の深さ(最上部が0）
  int size;
  vector<P> node;//セグ木本体

  //コンストラクタ
  //初期値の代入もする
  segtree(int n/*,vector<int> v*/)
  {
    depth=0;
    size=1;
    while(n>size)
    {
      size*=2;
      depth++;
    }
    size*=2;
    node.resize(size,P(1e8-1,1e8-1));
    //最下段に値を入れたあとに、下の段から順番に値を入れる
    //値を入れるには自分の子の2値を参照する
    // for(int i=0;i<n;i++)
    //   node[i+(1<<depth)]=v[i];
    
    // for(int d=depth-1;d>=0;d--)
    // {
    //   for(int i=0;i<(1<<d);i++)
    //   {
    //     int ind=i+(1<<d);
    //     node[ind]=min(node[ind*2],node[ind*2+1]);
    //   }
    // }
  }

  //値の更新
  //node[k]をaにする
  void update(int k,P a)
  {
    k+=(1<<depth);//セグ木上のインデックスに読み替え
    node[k]=a;
    while(k>0)
    {
      k/=2;
      node[k]=min(node[k*2],node[k*2+1]);
    }
    return;
  }
  
  //値の取得
  //閉区間[l,r]の最小値
  P get(int l,int r)
  {
    l+=(1<<depth);
    r+=(1<<depth);
    if(l==r)
      return node[l];
    int ret=l;
    while(l<=r)
		{
			if(!(r&1))
			{
				if(node[ret]>node[r])
					ret=r;
				r--;
			}
			if(l&1)
			{
				if(node[ret]>node[l])
					ret=l;
				l++;
			}
			l/=2;r/=2;
		}
    return node[ret];
  }
};
string s;
int main()
{
  int n,m;
	cin>>n>>m;
	segtree seg=segtree(n+1);
	cin>>s;
	//可能か調べておく
	for(int i=0;i<s.size();i++)
	{
		int cnt=0;
		while(s[i]=='1')
		{
			cnt++;i++;
		}
		if(cnt>=m)
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	seg.update(n,P(0,n));
	//構築
	for(int i=n-1;i>-1;i--)
	{
		if(s[i]=='1')
			continue;
		//先のマスから求める
		P tmp=seg.get(i+1,min(i+m,n));
		//cerr<<tmp.first<<" "<<tmp.second<<endl;
		seg.update(i,P(tmp.first+1,i));
	}
	//復元
	vector<int> ans;
	ans.push_back(0);
	while(ans[ans.size()-1]<n)
	{
		int tmp=ans[ans.size()-1];
		ans.push_back(seg.get(tmp+1,min(tmp+m,n)).second);
	}
	for(int i=1;i<ans.size();i++)
		cout<<ans[i]-ans[i-1]<<" ";
	cout<<endl;
  return 0;
}