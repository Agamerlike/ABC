#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int MOD=1e9+7;

long long pow_mod(int n)
{
	long long r=1;
	for(int i=0;i<n;i++)
	{
		r*=2;
		r%=MOD;
	}
	return r;
}

int main()
{
	int n;
	int a[100000];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	//偶数の場合
	if(n%2==0)
	{
		//解の存在確認
		for(int i=0;i<n;i++)
		{
			if(a[i]!=i+1 || a[i+1]!=i+1)
			{
				cout<<0<<endl;
				return 0;
			}
			i++;
		}
		//ここまで来れたら解は存在する
		cout<<pow_mod(n/2)<<endl;
	}else{//奇数の場合
		//解の存在確認
		for(int i=0;i<n;i++)
		{
			if(i==0)
			{
				if(a[i]!=0)
				{
					cout<<0<<endl;
					return 0;
				}
			}else{
				if(a[i]!=i+1 || a[i+1]!=i+1)
				{
					cout<<0<<endl;
					return 0;
				}
				i++;
			}
		}
		//ここまで来れたら解は存在する
		cout<<pow_mod(n/2)<<endl;
	}
	return 0;
}