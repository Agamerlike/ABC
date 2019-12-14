#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
#include <cassert>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1e9+7;
class RollHash
{
	public:
	ull base=1e9+7;
	RollHash(){}
	RollHash(ull b)
	{
		base=b;
	}
	//sの[l,r)におけるハッシュ値を計算する
	ull calchash(string &s,int l,int r)
	{
		ull ret=0;
		for(int i=l;i<min(r,(int)s.size());i++)
			ret=ret*base+s[i];
		return ret;
	}
	//aはbに含まれているか？
	//含まれていれば最初に一致した場所の先頭のindex
	//含まれていなければ-1
	int contain(string &a,string &b)
	{
		int al=a.size();int bl=b.size();
		if(al>bl)
			return false;
		ull t=1;
		for(int i=0;i<al;i++)
			t*=base;
		ull ah=0;ull bh=0;
		for(int i=0;i<ah;i++)
			ah=ah*base+a[i];
		for(int i=0;i<ah;i++)
			bh=bh*base+b[i];
		if(ah==bh)
			return 0;
		for(int i=0;i+al<bl;i++)
		{
			bh=bh*base+b[i+al]-b[i]-t;
			if(ah==bh)
				return i;
		}
		return -1;
	}
	//aの末尾とbの先頭を何文字重ねることができるか
	int overlap(string &a,string &b)
	{
		int al=a.size();int bl=b.size();
		int ret=0;
		ull ah=0;ull bh=0; ull t=1;
		for(int i=1;i<=min(al,bl);i++)
		{
			ah=ah+a[al-i]*t;
			bh=bh*base+b[i-1];
			if(ah==bh)
				ret=i;
			t*=base;
		}
		return ret;
	}
};
ull shash[5001];
ull t[5001];
int main()
{
	int n;
	string s;
	RollHash h=RollHash();
	cin>>n>>s;
	shash[0]=0;
	for(int i=1;i<n+1;i++)
		shash[i]=shash[i-1]*h.base+s[i-1];
	t[0]=1;
	for(int i=1;i<5001;i++)
		t[i]=t[i-1]*h.base;
	//順番に調べる
	ull l,r;
	//midは長さ
	int ok=0;
	int ng=n/2+1;
	while(ng-ok>1)
	{
		int mid=(ok+ng)/2;
		bool f=false;
		for(int i=0;i<n;i++)
		{
			if(mid+i>n)
				break;
			//cerr<<k<<" "<<i<<endl;
			l=shash[mid+i]-t[mid]*shash[i];
			assert(h.calchash(s,i,mid+i)==l);
			for(int j=mid+i;j+mid<=n;j++)
			{
				r=shash[j+mid]-t[mid]*shash[j];
				if(l==r)
				{
					ok=mid;
					f=true;
					break;
				}
			}
			if(f)
				break;
		}
		if(!f)
			ng=mid;
	}
	cout<<ok<<endl;
	return 0;
}