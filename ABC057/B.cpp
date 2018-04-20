#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

ll stu[50][2];
ll che[50][2];

int main()
{
	int n,m;
	ll ans=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>stu[i][0]>>stu[i][1];
	for(int i=0;i<m;i++)
		cin>>che[i][0]>>che[i][1];
	
	for(int i=0;i<n;i++)
	{
		int index;
		ans=1e15;
		for(int j=0;j<m;j++)
		{
			ll man = abs(stu[i][0]-che[j][0])+abs(stu[i][1]-che[j][1]);
			if(man<ans)
			{
				index=j+1;
				ans=man;
			}
		}
		cout<<index<<endl;
	}
	return 0;
}