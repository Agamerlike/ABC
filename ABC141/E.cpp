#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;

string s;
vector<int> pt[26];
//cから始まる連続文字列の最長を求める
int lcs(char c,int now)
{
	int ret=now;
	//それぞれ調べる
	for(int i=0;i<pt[c-'a'].size();i++)
	{
		for(int j=pt[c-'a'].size()-1;j>i;j--)
		{
			int a=pt[c-'a'][i];
			int b=pt[c-'a'][j];
			int cnt=0;
			int bs=b;
			if(b-a<=ret)
				continue;
			while(s[a]==s[b])
			{
				//cerr<<a<<" "<<b<<endl;
				a++;
				b++;
				cnt++;
				if(a==bs || b==s.size())
					break;
			}
			ret=max(ret,cnt);
		}
	}
	return ret;
}

int main()
{
	int n;
	int ans=0;
	cin>>n;
	cin>>s;
	
	for(int i=0;i<n;i++)
	{
		pt[s[i]-'a'].push_back(i);
	}
	for(int i=0;i<26;i++)
		ans=max(ans,lcs('a'+i,ans));
	
	// int ng=n;
	// int ok=0;
	// while(ng-ok>1)
	// {
	// 	int mid=(ok+ng)/2;
	// 	bool f=false;
	// 	for(int i=0;i<n-mid*2+1;i++)
	// 	{
	// 		for(int j=i+mid;j<n-mid+1;j++)
	// 		{
	// 			bool tmp=true;
	// 			//mid文字の一致を調べる
	// 			for(int k=0;k<mid;k++)
	// 			{
	// 				if(s[i+k]!=s[j+k])
	// 				{
	// 					tmp=false;
	// 					break;
	// 				}
	// 			}
	// 			if(tmp)
	// 			{
	// 				f=true;
	// 				break;
	// 			}
	// 		}
	// 		if(f)
	// 			break;
	// 	}
	// 	if(f)
	// 		ok=mid;
	// 	else
	// 		ng=mid;
	// }
	cout<<ans<<endl;
	return 0;
}