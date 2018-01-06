#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

long long mini2(long long h,long long w)
{
	long long ans=h*w*5;
	long long a;
	long long s1,s2,s3;
	for(int i=1;i<h;i++)
	{
		s1=i*w;
		s2=(h-i)*(w/2);
		s3=h*w-s1-s2;
		a=max(max(s1,s2),s3)-min(min(s1,s2),s3);
		if(ans>a)
		{
			ans=a;
		}
	}
	return ans;
}

long long mini1(long long h,long long w)
{
	long long ans=h*w*5;
	long long a;
	long long s1,s2,s3;
	for(int i=1;i<h;i++)
	{
		s1=i*w;
		s2=((h-i)/2)*w;
		s3=h*w-s1-s2;
		a=max(max(s1,s2),s3)-min(min(s1,s2),s3);
		if(ans>a)
		{
			ans=a;
		}
	}
	return ans;
}

int main()
{
	long long h,w;
	long long ans;
	cin>>h>>w;
	ans=min(min(mini1(h,w),mini2(h,w)),min(mini1(w,h),mini2(w,h)));
	cout<<ans<<endl;
	return 0;
}
