#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
typedef long long ll;
ll MOD = 1e9+7;
using namespace std;
class kukan
{
	public:
	int l,r;
	double v;
	kukan(int a,int b,double c)
	{
		l=a;r=b;v=c;
	}
};
vector<kukan> vec;
double ans[40001];//t/2
int main()
{
	int n;
	int t[102];
	int v[102];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>t[i+1];
		t[i+1]*=2;
	}
	for(int i=0;i<n;i++)
		cin>>v[i];
	v[n]=0;
	t[0]=0;
	for(int i=1;i<n+1;i++)
		t[i]+=t[i-1];
	vec.push_back(kukan(0,0,0.0));
	for(int i=1;i<n+1;i++)
		vec.push_back(kukan(t[i-1],t[i],v[i-1]));
	vec.push_back(kukan(t[n],t[n],0.0));
	for(int i=0;i<t[n]+1;i++)
	{
		//それぞれについてそれぞれの関数を適用したときの値を調べる
		double tmp=1e8-1;
		for(int j=0;j<vec.size();j++)
		{
			if(vec[j].l<=i && i<=vec[j].r)
				tmp=min(tmp,vec[j].v);
			else if(i<vec[j].l)
				tmp=min(tmp,vec[j].v+(double)(vec[j].l-i)/2.0);
			else
				tmp=min(tmp,vec[j].v+(double)(i-vec[j].r)/2.0);
		}
		ans[i]=tmp;
	}
	double sum=0.0;
	for(int i=1;i<t[n]+1;i++)
	{
		//cerr<<ans[i]<<endl;
		sum+=(ans[i]+ans[i-1])*0.5/2.0;
	}
	cout<<setprecision(12)<<fixed<<sum<<endl;
	return 0;
}