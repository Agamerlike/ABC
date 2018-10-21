#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;
double EPS = 1e-10; //誤差

pair<double,int> en[1000];
double syoku[1000];//目標濃度に対して余る食塩の量 不足の場合はマイナス

int main()
{
	int n,k;
	double ans=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		double w,p;
		cin>>w>>p;
		en[i]=make_pair(w,p);
	}

	//二分探索
	double l=0;
	double r=100;
	while(r-l>EPS)
	{
		double mid=(l+r)/2.0f;
		//cerr<<l<<" "<<r<<endl;
		//midを目標濃度とする
		for(int i=0;i<n;i++)
		{
			syoku[i]=en[i].first*(en[i].second-mid);
		}
		sort(syoku,syoku+n);
		reverse(syoku,syoku+n);//降順にソート
		double s=0;
		for(int i=0;i<k;i++)
			s+=syoku[i];
		
		if(s>=0)
			l=mid;
		else
			r=mid;
	}
	cout<<fixed<<l<<endl;
	return 0;
}