#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

long long a[300000];
long long ll[300000];
long long rr[300000];

int main()
{
	int n;
	long long sp=0;
	long long sl=0;
	long long ans=0;
	priority_queue<long long>l;//後半n 降順
	priority_queue<long long,vector<long long>,greater<long long>>p;//前半n 昇順
	cin>>n;
	for(int i=0;i<3*n;i++)
	{
		cin>>a[i];
		ans -= a[i];
	}
	for(int i=0;i<n;i++)
	{
		l.push(a[3*n-1-i]);
		p.push(a[i]);
		sp+=a[i];
		sl+=a[3*n-1-i];
	}
	ll[n-1]=sp;
	rr[2*n+1]=sl;
	//llを求める
	for(int i=n;i<2*n+1;i++)
	{
		ll[i]=ll[i-1];
		cerr<<p.top()<<endl;
		if(p.top()<a[i])
		{
			ll[i]+=a[i]-p.top();
			p.pop();
			p.push(a[i]);
		}
	}
	//rrを求める
	for(int i=2*n;i>=n;i--)
	{
		rr[i]=rr[i+1];
		if(l.top()>a[i])
		{
			rr[i]-=l.top()-a[i];
			l.pop();
			l.push(a[i]);
		}
	}

	//差の最大値を求める
	for(int i=n-1;i<2*n+1;i++)
	{
		cerr<<ll[i]<<" "<<rr[i+1]<<endl;
		if(ans<ll[i]-rr[i+1])
			ans=ll[i]-rr[i+1];
	}
	cout<<ans<<endl;
	return 0;
}