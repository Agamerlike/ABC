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
int h[100000];
int main()
{
	int n;
	ll ans=0;
	cin>>n;
	bool f=true;
	for(int i=0;i<n;i++)
	{
		cin>>h[i];
	}
	if(h[0]!=1)
		h[0]--;
	for(int i=1;i<n;i++)
	{
		if(h[i]>h[i-1])
			h[i]--;
		else if(h[i]<h[i-1])
			f=false;
	}
	if(f)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}