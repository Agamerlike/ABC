#include <iostream>

using namespace std;

int main()
{
	int n;
	int now;
	int cnt;
	int a[100000];
	bool ap[100000];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		a[i]--;
		ap[i]=false;
	}
	now = a[0];
	ap[0] = true;
	cnt++;
	while(ap[now]!=true)
	{
		if(now==1)
		{
			cout<<cnt<<endl;
			return 0;
		}
		ap[now] = true;
		now = a[now];
		cnt++;
	}
	cout<<-1<<endl;
	return 0;
}