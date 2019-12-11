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


int main()
{
	double n,k;
	double ans=0;
	cin>>n>>k;
	for(double i=1;i<n+1;i+=1)
	{
		if(i>=k)
		{
			ans+=(1.0f/n);
			continue;
		}
		int tmp=i;
		int cnt=0;
		while(tmp<k)
		{
			tmp*=2;
			cnt++;
		}
		ans+=(1.0f/n)*(double)pow(0.5f,cnt);
	}
	cout<<fixed<<setprecision(12)<<ans<<endl;
	return 0;
}