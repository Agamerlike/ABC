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
	int n;
	int s[50];
	int ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>s[i];
	int maxt=-99999;//高橋君が得た最大得点
	int maxa=-99999;//青木君が得た最大得点

	//i...高橋君が選ぶ場所
	for(int i=0;i<n;i++)
	{
		int t=-99999;
		int a=-99999;
		//j...青木君が選ぶ場所
		for(int j=0;j<n;j++)
		{
			int aa=0;
			int tt=0;
			if(i==j)
				continue;
			if(i>j)
			{
				for(int k=0;k<i-j+1;k++)
				{
					if(k%2==0)
						tt+=s[k+j];
					else
						aa+=s[k+j];
				}
			}else{
				for(int k=0;k<j-i+1;k++)
				{
					if(k%2==0)
						tt+=s[k+i];
					else
						aa+=s[k+i];
				}
			}
			//ここでは青木君が最も得点が高くなるように選ぶ
			if(a<aa)
			{
				a=aa;
				t=tt;
			}
		}
		//ここでは高橋君が最も得点が高くなるように選ぶ
		if(maxt<t)
		{
			maxt=t;
			maxa=a;
		}
	}
	ans=maxt;
	cout<<ans<<endl;
	return 0;
}