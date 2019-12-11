#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;

int main()
{
	ll n;
	int rank;
	int ans=0;
	cin>>n;
	rank=(int)log2(n)+1;
	ll s=1;
	//高橋君の手番でnを超えそうな場合
	if(rank%2==1)
	{
		int cnt=0;
		while(s<=n)
		{
			if(cnt%2==0)
				s=s*2+1;
			else
				s*=2;
			cnt++;
		}
		ans=cnt%2;
	}else{//青木君の手番でnを超えそうな場合
		int cnt=0;
		while(s<=n)
		{
			if(cnt%2==0)
				s=s*2;
			else
				s=s*2+1;
			cnt++;
		}
		ans=cnt%2;
	}
	if(ans%2==0)
		cout<<"Takahashi"<<endl;
	else
		cout<<"Aoki"<<endl;
	return 0;
}