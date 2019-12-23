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
int dp[100000][26];//s[i]からスタートしていくつたどればchar'j'にたどりつけるか
int main()
{
	string s,t;
	ll ans=0;
	cin>>s>>t;
	string tmp=s+s;
	fill(dp[0],dp[100000],1e8-1);
	//最後の文字を調べる
	for(int i=s.size();i<tmp.size();i++)
		dp[s.size()-1][tmp[i]-'a']=min(dp[s.size()-1][tmp[i]-'a'],i-(int)s.size()+1);
	//最後から2文字目以降は直後の文字を除いてすべて次の文字+1
	for(int i=s.size()-2;i>-1;i--)
	{
		for(int j=0;j<26;j++)
		{
			if(dp[i+1][j]!=1e8-1)
				dp[i][j]=dp[i+1][j]+1;
		}
		dp[i][tmp[i+1]-'a']=1;
	}
	int ind=0;
	if(t[ind]==s[0])
		ind++;
	for(;ind<t.size();ind++)
	{
		//cerr<<dp[ans%s.size()][t[ind]-'a']<<endl;
		if(dp[ans%s.size()][t[ind]-'a']==1e8-1)
		{
			cout<<-1<<endl;
			return 0;
		}
		ans+=dp[ans%s.size()][t[ind]-'a'];
	}
	cout<<ans+1<<endl;
	return 0;
}