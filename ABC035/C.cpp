#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;

int o[200002];
int dif[200002];// [l,r)の区間(lで+1,rで-1)
int main()
{
	int n,q;
	int ans=0;
	cin>>n>>q;
	fill(dif,dif+n+2,0);//初期化
	for(int i=0;i<q;i++)
	{
		int l,r;
		cin>>l>>r;
		r++;
		dif[l]+=1;
		dif[r]-=1;
	}
	o[0]=0;
	for(int i=1;i<n+1;i++)
	{
		o[i]=o[i-1]+dif[i];
	}
	for(int i=1;i<n+1;i++)
	{
		o[i]%=2;
		//cerr<<o[i];
	}
	for(int i=1;i<n+1;i++)
		cout<<o[i];
	cout<<endl;
	return 0;
}