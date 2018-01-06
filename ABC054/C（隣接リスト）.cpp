#include <iostream>
#include <vector>
using namespace std;

vector <int> path[8];
int ans;

int dfs(int n,bool past[],int now)
{
	bool flag=true;
	bool past2[8];
	for(int i=0;i<n;i++)
	{
		past2[i]=past[i];
	}
	past2[now]=true;

	//新しく経路探索
	for(int i=0;i<path[now].size();i++)
	{
		if(past2[path[now][i]]==false)
		{
			ans += dfs(n,past2,path[now][i]);
		}
	}

	//全頂点を訪れたかどうか（終了判定）
	for(int i=0;i<n;i++)
	{
		if(past2[i]==false)
		{
			flag=false;
			break;
		}
	}
	if(flag==true)
	{
		return 1;
	}else{
		return 0;
	}
}

int main()
{
	int n,m,a,b;
	ans = 0;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		path[a-1].push_back(b-1);
		path[b-1].push_back(a-1);
	}
	bool past[8];//過去に訪れた頂点を記録
	for(int i=0;i<8;i++)
	{
		past[i]=false;
	}

	ans += dfs(n,past,0); //頂点1を始点として全頂点を訪れるルートを深さ優先探索
	cout<<ans<<endl;
	return 0;
}
