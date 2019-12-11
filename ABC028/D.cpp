#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;

int main()
{
	ll n,k;
	ll pt=0;//総数がいくつあるか
	double ans;
	cin>>n>>k;
	pt+=6*(k-1)*(n-k);//kより小さい数,k,kより大きい数　のパターン
	pt+=3*(k-1);//kより小さい数,k,k　のパターン
	pt+=3*(n-k);//k,k,kより大きい数　のパターン
	pt++;//k,k,k　のパターン
	cerr<<pt<<endl;
	ans=(double)pt/pow(n,3);
	cout<<fixed<<setprecision(12)<<ans<<endl;
	return 0;
}