#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <functional>
typedef long long ll;

using namespace std;

int d[100][100];
int used[100][100]; //使われていない:0, 使われた:1, そもそもパスが通っていない:-1 

int main()
{
	int n,m;
	int ans=0;
	cin>>n>>m;
	fill(d[0],d[100],(int)1e9-1);
	fill(used[0],used[100],-1);
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		a--;
		b--;
		d[a][b]=c;
		d[b][a]=c;
		used[a][b]=0;
		used[b][a]=0;
	}

	//ワーシャルフロイド
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(d[i][j]>d[i][k]+d[k][j])
				{
					if(d[i][j]!=(int)1e9-1 && !used[i][j])
					{
						used[i][j]=true;
						used[j][i]=true;
					}
					d[i][j]=d[i][k]+d[k][j];
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}