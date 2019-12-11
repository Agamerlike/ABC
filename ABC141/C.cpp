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
ll pt[100000];
int main()
{
	int n;
	ll k;
	int q;
	cin>>n>>k>>q;
	fill(pt,pt+100000,0);
	for(int i=0;i<q;i++)
	{
		int a;
		cin>>a;
		a--;
		pt[a]++;
	}
	for(int i=0;i<n;i++)
	{
		if(k-(q-pt[i])>0)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}