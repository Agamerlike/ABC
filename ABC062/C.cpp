#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

long long max(long long a, long long b,long long c)
{
	long long m=a;
	if(m<=b)
	{
		m=b;
	}
	if(m<=c)
	{
		m=c;
	}
	return m;
}

long long min(long long a,long long b,long long c)
{
	long long m=a;
	if(m>=b)
	{
		m=b;
	}
	if(m>=c)
	{
		m=c;
	}
	return m;
}

int main()
{
	long long a[2];
	long long s1,s2,s3;
	long long ans;
	cin>>a[0]>>a[1];
	sort(a,a+2);
	cerr<<a[0]<<a[1]<<endl;
	if(a[1]%3==0 || a[0]%3==0)
	{
		ans=0;
	}else if(a[0]==2 && a[1]==2){
		ans=1;
	}else{
		s1=(a[1]/3)*a[0];
		s2=(a[0]/2)*(a[1]-(a[1]/3));
		s3=a[0]*a[1]-s1-s2;
		cerr<<s1<<s2<<s3<<endl;
		ans=max(s1,s2,s3)-min(s1,s2,s3);
		s1=(a[1]/3+1)*a[0];
		s2=(a[0]/2)*(a[1]-1-(a[1]/3));
		s3=a[0]*a[1]-s1-s2;
		cerr<<s1<<s2<<s3<<endl;
		ans=min(ans,max(s1,s2,s3)-min(s1,s2,s3),a[0]);
	}
	cout<<ans<<endl;
	return 0;
}