#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
bool dp[101][101];
int main()
{
	ll x,y;
	cin>>x>>y;
	//実験コード
	// fill(dp[0],dp[101],false);
	// for(int i=2;i<101;i++)
	// {
	// 	for(int j=0;j<=i;j++)
	// 	{
	// 		//(i-j,j)のケースを調べる
	// 		if(i-j==1 && j==1)
	// 			continue;
	// 		bool f=false;
	// 		for(int k=1;k*2<=i-j;k++)
	// 			f|=!(dp[i-j-k*2][j+k]);
	// 		for(int k=1;k*2<=j;k++)
	// 			f|=!(dp[i-j+k][j-k*2]);
	// 		dp[i-j][j]=f;
	// 	}
	// }
	// for(int i=0;i<101;i++)
	// {
	// 	for(int j=0;j<101-i;j++)
	// 	{
	// 		// if(dp[i][j])
	// 		// 	cerr<<"A";
	// 		// else
	// 		// 	cerr<<"B";
	// 		if(!dp[i][j])
	// 		{
	// 			cerr<<i<<" "<<j<<endl;
	// 			//break;
	// 		}
	// 	}
	// 	//cerr<<endl;
	// }
	if(max(x,y)-min(x,y)<2)
		cout<<"Brown"<<endl;
	else
		cout<<"Alice"<<endl;
	return 0;
}