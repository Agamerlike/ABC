#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int n;
long long a,b;
long long h[100000];

bool eno(long long t)
{
	int j=0;
	long long cnt=0;
	long long s[100000];
	for(int i=0;i<n;i++)
	{
		s[i]=h[i];
	}
	sort(s,s+n);
	reverse(s,s+n);
	for(int i=0;i<n;i++)
	{
		s[i] -= b*t;
	}
	while(j<n)
	{
		if(s[j]<0)
		{
			j++;
			continue;
		}
		cnt+=(s[j]/(a-b));
		//cerr<<t<<" "<<s[j]<<" "<<cnt<<endl;
		if(s[j]%(a-b)!=0)
		{
			cnt++;
		}
		if(cnt>t)
		{
			return false;
		}
		j++;
	}
	return true;
}

int main()
{
	long long ans;
	long long mid;
	long long l=-1;
	long long r=1e9+7;
	cin>>n>>a>>b;
	for(int i=0;i<n;i++)
	{
		cin>>h[i];
	}
	mid = (l+r)/2;
	//ここから2分探索
	while(abs(r-l)>1)
	{
		//cerr<<mid<<endl;
		mid = (l+r)/2;
		if(eno(mid)==true)
		{
			r=mid;
		}else{
			l=mid;
		}
	}
	
	if(eno(l)==true)
	{
		ans = l;
	}else{
		ans = r;
	}
	//ここまで2分探索　この方法は覚えておくべき
	cerr<<l<<" "<<mid<<" "<<r<<endl;
	cout<<ans<<endl;
	return 0;
}
