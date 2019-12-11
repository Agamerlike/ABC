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

	bool used[50];//すでに解析が終わったw
	bool fix[10];//すでに解析が終わったs
	fill(used,used+50,false);
	fill(fix,fix+10,false);
	//最初の1～3文字を決める
	for(int i=0;i<n;i++)
	{
		//1つしかないならこれで確定
		if(v[i].size()==1)
		{
			s[v[i][0]]=w[i];
			fix[v[i][0]]=true;
			used[i]=true;
		}
		double ave=(double)w[i].size()/(double)v[i].size();
		//3文字ならすべて確定する
		if(ave==3.0f)
		{
			for(int j=0;j<w[i].size()/3;j++)
			{
				string tmp="";
				for(int k=j*3;k<j*3+3;k++)
				{
					tmp+=w[i][k];
				}
				s[v[i][j]]=tmp;
				fix[v[i][j]]=true;
			}
			used[i]=true;
		}else if(ave==1.0f){
			//ちょうど1文字でもすべて確定する
			for(int j=0;j<w[i].size();j++)
			{
				s[v[i][j]]=w[i][j];
				fix[v[i][j]]=true;
			}
			used[i]=true;
		}else if(ave>=2.0f){
			//2文字以上なら最初の2文字が確定する
			if(!fix[v[i][0]])
			{
				if(s[v[i][0]].size()<1)
				{
					s[v[i][0]]+=w[i][0];
					s[v[i][0]]+=w[i][1];
				}else if(s[v[i][0]].size()<2){
					s[v[i][0]]+=w[i][1];
				}
			}
		}else{
			//1文字以上なら最初の1文字が確定する
			if(!fix[v[i][0]])
			{
				if(s[v[i][0]].size()<1)
					s[v[i][0]]+=w[i][0];
			}
		}
	}

	//確定もしくは部分的に確定したものを使って残りを埋める
	bool f=true;
	while(f)
	{
		f=false;
		//ここから解析
		for(int i=0;i<n;i++)
		{
			if(used[i])
				continue;
			
			int point[11];//w上におけるそれぞれのsの開始地点（分かっているものだけでよい）
			fill(point,point+11,-1);
			point[0]=0;
			point[v[i].size()]=w[i].size();
			for(int j=0;j<v[i].size();j++)
			{
				//確定しているなら次のスタート地点も確定
				if(fix[v[i][j]] && point[j]!=-1)
					point[j+1]=point[j]+s[v[i][j]].size();
				if(j!=v[i].size()-1)
			}
		}
		//全部解析終わったかチェック
		for(int i=0;i<n;i++)
		{
			if(!used[i])
				f=true;
		}
	}
	cout<<ans<<endl;
	return 0;
}