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
	t[0]=0;
	for(int i=1;i<n+1;i++)
	{
		cin>>t[i];
		t[i]+=t[i-1];
	}
	for(int i=1;i<n+1;i++)
	{
		cin>>v[i];
	}
	v[0]=0;
	v[n+1]=0;
	
	for(int i)
	
	cout<<ans<<endl;
	return 0;
}