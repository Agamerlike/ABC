//いいリスト構造があれば多分いけそう
#include "bits/stdc++.h"

using namespace std;

int count(int i,int N,int keiro[][2*pow(10,5)])
{
	bool city[2*pow(10,5)];
	for(int i=0;i<2*pow(10,5);i++)
	{
		city[i]=false;
	}

}

int main()
{
	int N,K,L;
	int p,q;
	int road[2*pow(10,5)][2*pow(10,5)];
	int rail[2*pow(10,5)][2*pow(10,5)];
	int city[2*pow(10,5)];
	for(int i=0;i<2*pow(10,5);i++)
	{
		city[i]=0;
		for(int j=0;j<2*pow(10,5);j++)
		{
			road[i][j]=0;
			rail[i][j]=0;
		}
	}
	cin >> N >> K >> L;
	for(int i=0;i<K;i++)
	{
		cin >> p >> q;
		road[p][q]+=1;
		road[q][p]+=1;
	}
	for(int i=0;i<L;i++)
	{
		cin >> p >> q;
		rail[p][q]+=1;
		rail[q][p]+=1;
	}
	for(int i=0;i<N;i++)
	{
		city[i]+=count(i,N,road);
		city[i]+=count(i,N,rail);
		cout << city[i];
	}
	cout << endl;
	return 0;
}