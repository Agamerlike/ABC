#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

long long a[300000];

int main()
{
	int n;
	long long sp=0;
	long long sl=0;
	long long lmax[100000];
	long long rmin[100000];
	long long ans;
	priority_queue<long long>l;//後半n
	priority_queue<long long,vector<long long>,greater<long long>>p;//前半n
	cin>>n;
	for(int i=0;i<3*n;i++)
	{
		cin>>a[i];
		ans -= a[i];
	}
	for(int i=n;i<n*2;i++)
	{
		p=priority_queue<long long,vector<long long>,greater<long long>>();
		l=priority_queue<long long>();
		sp=0;
		sl=0;
		//前半の要素を入れる
		for(int j=0;j<i;j++)
		{
			sp+=(long long)a[j];
			p.push(a[j]);
		}
		//最大値を取得
		for(int j=p.size();j>n;j=p.size())
		{
			sp-=p.top();
			cerr<<i<<" "<<p.top()<<endl;
			p.pop();
		}
		lmax[i-n]=sp;
		//後半の要素を入れる
		for(int j=i;j<n*3;j++)
		{
			sl+=a[j];
			l.push(a[j]);
		}
		//最小値を取得
		for(int j=l.size();j>n;j=l.size())
		{
			sl-=l.top();
			cerr<<i<<" "<<l.top()<<endl;
			l.pop();
		}
		rmin[i-n]=sl;
	}
	ans = lmax[0] - rmin[0];
	for(int i=1;i<n;i++)
	{
		ans = max(ans, lmax[i]-rmin[i]);
	}
	cout<<ans<<endl;
	return 0;
}