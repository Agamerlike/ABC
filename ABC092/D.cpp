#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

string s[100];
int h,w;

int kousi(int mas)
{
	int m;
	if(mas>=100)
	{
		w=100;
		for(int i=0;i<mas/100;i++)
		{
			h++;
			for(int j=0;j<50;j++)
			{
				if(i%2==0)
					s[i]+=".#";
				else
					s[i]+="#.";
			}
		}
		m=mas%100;
		if(m!=0)
		{
			for(int i=0;i<m/2;i++)
			{
				if(h%2==0)
					s[h]+=".#";
				else
					s[h]+="#.";
			}
			m=100-m;
			for(int i=0;i<m/2;i++)
			{
				if(h%2!=0)
					s[h]+=".#";
				else
					s[h]+="#.";
			}
			h++;
		}
	}else{
		w=100;
		h=1;
		for(int i=0;i<mas/2;i++)
		{
			s[h-1]+=".#";
		}
		m=100-mas;
		for(int i=0;i<m;i++)
		{
			s[h-1]+="#";
		}
	}
	return 0;
}

int sw(int hh,int ww)
{
	for(int i=0;i<hh;i++)
	{
		for(int j=0;j<ww;j++)
		{
			if(s[i][j]=='#')
				s[i][j]='.';
			else
				s[i][j]='#';
		}
	}
	return 0;
}

//f=true..."."
//f=false..."#"
int sikitume(int dif,bool f)
{
	int m=dif/25;
	if(m>0)
	{
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<25;j++)
			{
				if(i%2==0)
				{
					if(f)
						s[h]+=".###";
					else
						s[h]+="#...";
				}else{
					if(f)
						s[h]+="##.#";
					else
						s[h]+="..#.";
				}
			}
			h++;
		}
		m=dif%25;
		if(m!=0)
		{
			for(int i=0;i<m;i++)
			{
				if(f)
				{
					if(s[h-1][0]=='.')
						s[h]+="##.#";
					else
						s[h]+=".###";
				}else{
					if(s[h-1][0]=='#')
						s[h]+="..#.";
					else
						s[h]+="#...";
				}
			}
			m=25-m;
			for(int i=0;i<m;i++)
			{
				if(f)
					s[h]+="####";
				else
					s[h]+="....";
			}
			h++;
		}
	}else{
		for(int j=0;j<dif;j++)
			{
					if(f)
						s[h]+="###.";
					else
						s[h]+="...#";
			}
			if(f)
				s[h]+='#';
			else
				s[h]+='.';

			for(int i=dif*4+1;i<100;i++)
			{
				s[h]+=s[h-1][i];
			}
			h++;
	}
	return 0;
}

int main()
{
	int a,b;
	h=0;
	w=0;
	//a..."."
	//b..."#"
	cin>>a>>b;

	//格子状の区画に区切る
	kousi(min(a,b)*2);

	//個数の少ないほうが最後に来るようにする
	if(s[h-1][w-1]=='#' && b>a)
	{
		sw(h,w);
	}else if(s[h-1][w-1]=='.' && a>b){
		sw(h,w);
	}

	//多い方の成分を付け加える
	if(a<b)
		sikitume(abs(a-b),false);
	else if(a>b)
		sikitume(abs(a-b),true);
	
	cout<<h<<" "<<w<<endl;
	for(int i=0;i<h;i++)
	{
		cout<<s[i]<<endl;
	}
	return 0;
}