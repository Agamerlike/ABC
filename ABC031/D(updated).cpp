#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;

int main()
{
	int k,n;
	vector<int> v[50];//1桁ずつ分解して格納
	string w[50];
	string s[10];//s[0]は使わない
	int ans=0;
	cin>>k>>n;
	for(int i=0;i<n;i++)
	{
		int vv;
		cin>>vv>>w[i];
		while(vv!=0)
		{
			v[i].push_back(vv%10);
			vv/=10;
		}
		reverse(v[i].begin(),v[i].end());
	}

	int slength[11];//sの長さ
	fill(slength,slength+11,1);
	for(int i=0;i<20000;i++)
	{
		//sそれぞれの長さを決める
		slength[1]++;
		for(int j=1;j<10;j++)
		{
			if(slength[j]==4)
			{
				slength[j]=1;
				slength[j+1]++;
			}
		}
		bool f=true;
		for(int j=0;j<n;j++)
		{
			int len=0;
			for(int k=0;k<v[j].size();k++)
				len+=slength[v[j][k]];
			if(len!=w[j].size())
			{
				f=false;
				break;
			}
		}
		if(f)
			break;
	}
	
	//sの長さが確定したら順番に当てはめるだけ
	for(int i=0;i<n;i++)
	{
		int point=0;
		for(int j=0;j<v[i].size();j++)
		{
			s[v[i][j]]=w[i].substr(point,slength[v[i][j]]);
			point+=slength[v[i][j]];
		}
	}

	for(int i=1;i<k+1;i++)
		cout<<s[i]<<endl;
	return 0;
}