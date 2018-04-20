#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;
int a[100001];

int main()
{
	int n;
	int ans=0;
	int index[2];
	int j=0;
	fill(a,a+100001,0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int b;
		cin>>b;
		a[b]++;
	}

	//3以上のものを調べる
	for(int i=0;i<100001;i++)
	{
		if(a[i]>2)
		{
			a[i]%=2;
			if(a[i]==0)
				a[i]=2;
		}
	}

	//2のものを調べる
	for(int i=0;i<100001;i++)
	{
		if(a[i]==2)
		{
			index[j]=i;
			j++;
		}
		if(j==2)
		{
			a[index[0]]=1;
			a[index[1]]=1;
			j=0;
		}
	}
	
	//残ったものを合計する
	for(int i=0;i<100001;i++)
	{
		ans+=a[i];
	}
	if(j==1)
		ans-=2;
	cout<<ans<<endl;
	return 0;
}