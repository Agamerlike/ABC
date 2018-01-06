#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>
typedef long long ll;

using namespace std;

int prime[100001];
int like[100001];
bool isprime[100001];

int sieve(int n)
{
	int p=0;
	for(int i=0;i<=n;i++)
	{
		isprime[i]=true;
	}
	isprime[0]=false;
	isprime[1]=false;

	for(int i=2;i<=n;i++)
	{
		if(isprime[i])
		{
			prime[p++]=i;
			for(int j=2*i;j<=n;j+=i)
			{
				isprime[j]=false;
			}
		}
	}
	return p;
}

int main()
{
	int q;
	int r[100000];
	int l[100000];
	int p;
	int cnt;
	
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		scanf("%d %d",&l[i],&r[i]);
	}

	p=sieve(100000);
	like[0]=0;
	for(int i=1;i<100001;i++)
	{
		like[i]=like[i-1];
		if(isprime[i]==true && isprime[(i+1)/2]==true)
		{
			like[i]++;
		}
	}

	for(int i=0;i<q;i++)
	{
		cnt = like[r[i]]-like[l[i]-2];
		printf("%d\n",cnt);
	}
	return 0;
}