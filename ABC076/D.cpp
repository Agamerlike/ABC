#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int main()
{
	int n;
	float t[102];
	float v[102];
	float x,y,kyori;
	float nowv,nextv;
	float ans=0;
	
	cin>>n;
	for(int i=1;i<n+1;i++)
	{
		cin>>t[i];
	}
	for(int i=1;i<n+1;i++)
	{
		cin>>v[i];
	}
	v[0]=0;
	nowv=0;
	v[n+1]=0;
	
	for(int i=1;i<n+1;i++)
	{
		nowv = min(v[i],v[i-1]);
		nextv = min(v[i],v[i+1]);
		x = (t[i]+nextv-nowv)/2;
		y = x+nowv;
		cerr<<v[i-1]<<" "<<v[i]<<" "<<v[i+1]<<endl;
		//加速部+減速部（等速部は存在しないと仮定）
		kyori = (nowv+y)*x/2 + (y+nextv)*(t[i]-x)/2;
		//はみ出している部分=等速部を引く
		if(y>v[i])
		{
			cerr<<y-v[i]<<endl;
			kyori -= (y-v[i])*(y-v[i]);
			cerr<<ans<<" "<<kyori<<endl;
		}
		ans += kyori;
	}
	cout<<ans<<endl;
	return 0;
}