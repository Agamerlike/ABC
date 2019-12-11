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
ll a[500];
ll b[500];

vector<ll> divisor(ll n)
{
	vector<ll> ret;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
	reverse(ret.begin(),ret.end());
  return (ret);
}

int main()
{
	int n;
	ll k;
	ll ss=0;
	ll ans=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		ss+=a[i];
	}
	vector<ll> yaku=divisor(ss);
	for(int j=0;j<yaku.size();j++)
	{
		//cerr<<yaku[j]<<endl;
		fill(b,b+500,0);
		//順番にyaku[j]の倍数にするのにかかる手数を調べる
		for(int i=0;i<n;i++)
			b[i]=(a[i]+yaku[j])%yaku[j];
		//検証する
		sort(b,b+n);
		for(int i=0;i<n+1;i++)
		{
			ll sum=0;
			ll psum=0;
			ll msum=0;
			//マイナスを加える
			for(int k=0;k<i;k++)
			{
				sum+=-b[k];
				msum+=b[k];
			}
			for(int k=i;k<n;k++)
			{
				if(b[k]!=0)
				{
					sum+=(yaku[j]-b[k]);
					psum+=(yaku[j]-b[k]);
				}
			}
			//cerr<<yaku[j]<<" "<<sum<<" "<<absum<<endl;
			if(sum==0 && max(psum,msum)<=k)
			{
				ans=yaku[j];
				break;
			}
		}
		if(ans>0)
			break;
	}
	cout<<ans<<endl;
	return 0;
}