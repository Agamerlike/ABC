#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int cnt[100000][26];

int main()
{
	string s;
	int ans=0;
	
	cin>>s;
	fill(cnt[0],cnt[100000],0);
	int len=s.length();
	for(int i=0;i<len;i++)
	{
		cnt[i][s[i]-'a']++;
	}

	for(int i=0;i<26;i++)
	{
		int j=0;
		while(j<len)
		{
			while(cnt[j][i]==0 && j<len)
				j++;
			//初めてcnt[j][i]=1
			int l=j;
			int r=-1;
			for(int k=l+1;k<l+3 && k<len;k++)
			{
				if(s[k]=='a'+i)
				{
					r=k;
					cout<<l+1<<" "<<r+1<<endl;
					return 0;
				}
			}
			j=l+3;
		}
	}
	cout<<-1<<" "<<-1<<endl;
	return 0;
}