#include <iostream>
#include <algorithm>

using namespace std;

int n,k;
long long a[5000];

//昇順にソートしたとき初めて必要となるカードを求める
int binary_DP()
{
	int left=-1;
	int right=n;
	int mid;
	bool dp[5001];
	bool flag=false;
	while(right-left>1)
	{
		mid=(left+right)/2;
		cerr<<mid<<endl;
		flag=false;
		for(int i=0;i<5001;i++)
		{
			dp[i]=false;
		}
		dp[0]=true;
		//DP
		for(int i=0;i<n;i++)
		{
			if(i==mid)
			{
				continue;
			}
			for(int j=5000;j>=0;j--)
			{
				if(dp[j]==true && j+a[i]<=5000)
				{
					dp[j+a[i]]=true;
				}
			}
		}
		//ここまでDP
		for(int i=0;i<k;i++)
		{
			if(dp[i]==true&&i+a[mid]>=k)
			{
				flag=true;
				break;
			}
		}
		if(flag==true)
		{
			right=mid;
		}else{
			left=mid;
		}
	}
	return right;
}

int main()
{
	int ans=0;
	cin>>n>>k;
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	ans = binary_DP();
	cout<<ans<<endl;
	return 0;
}