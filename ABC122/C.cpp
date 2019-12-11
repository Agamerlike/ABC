#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;

ll rui[100001];//i文字目までにACは何回現れるか
int main()
{
	int n,q;
	string s;
	int ans=0;
	cin>>n>>q;
	cin>>s;
	fill(rui,rui+100001,0);
	for(int i=2;i<n+1;i++)
	{
		rui[i]=rui[i-1];
		if(s[i-1]=='C' && s[i-2]=='A')
			rui[i]++;
	}
	for(int i=0;i<q;i++)
	{
		int l,r;
		cin>>l>>r;
		cout<<rui[r]-rui[l]<<endl;
	}
	return 0;
}