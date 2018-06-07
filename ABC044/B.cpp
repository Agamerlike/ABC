#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int cnt[26];

int main()
{
	int n;
	string w;
	int ans=0;
	
	cin>>w;
	n=w.length();
	fill(cnt,cnt+26,0);
	for(int i=0;i<n;i++)
		cnt[(int)(w[i]-'a')]++;
	bool f=true;
	for(int i=0;i<26;i++)
	{
		if(cnt[i]%2!=0)
			f=false;
	}
	if(f)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}