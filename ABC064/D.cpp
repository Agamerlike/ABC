#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;
	int i=0;
	string s;
	string ans;
	int frcnt=0; //初めて(が出てくるまでの)の登場回数
	int flcnt=0; //初めて)が出てくるまでの(の登場回数
	int rcnt=0;
	int lcnt=0;
	int cnt;
	bool flag=false;
	cin>>n;
	cin>>s;
	ans=s;
	//全部チェック
	while(flag==false)
	{
		flag=true;
		for(int j=0;j<n-1;j++)
		{
			if(s[j]=='('&&s[j+1]==')')
			{
				s.erase(j,2);
				n -=2;
				flag=false;
			}
		}
	}
	for(int j=0;j<n;j++)
	{
		if(s[j]=='(')
		{
			lcnt++;
		}else if(s[j]==')'){
			rcnt++;
		}
	}
	//左から検査
	while(s[i]!='(' && i<n)
	{
		frcnt++;
		i++;
	}
	reverse(begin(s),end(s));
	i=0;
	//右から検査
	while(s[i]!=')' && i<n)
	{
		flcnt++;
		i++;
	}
	cerr<<flcnt<<" "<<frcnt<<endl;
	cerr<<lcnt<<" "<<rcnt<<endl;

	if(rcnt==0 || lcnt==0)
	{
		for(int j=0;j<rcnt;j++)
		{
			ans.insert(0,"(");
		}
		for(int j=0;j<lcnt;j++)
		{
			ans+=')';
		}
	}else{
		for(int j=0;j<frcnt;j++)
		{
			ans.insert(0,"(");
		}
		for(int j=0;j<flcnt;j++)
		{
			ans+=')';
		}
		if(frcnt+flcnt != rcnt+lcnt)
		{
			rcnt -= frcnt;
			lcnt -= flcnt;
			cnt=rcnt-lcnt;
			//(の方が多い
			if(cnt>0)
			{
				for(int j=0;j<cnt;j++)
				{
					ans.insert(0,"(");
				}
			}else if(cnt<0){
				cnt *= -1;
				for(int j=0;j<cnt;j++)
				{
					ans+=')';
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}