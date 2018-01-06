#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	int flag=0;
	char s[100000];
	char a[100000];
	char a_last;
	char a_begin;
	string x[4];
	x[0]="SWS";
	x[1]="WWW";
	x[2]="SSW";
	x[3]="WSS";
	string o[4];
	o[0]="SWW";
	o[1]="WWS";
	o[2]="WSW";
	o[3]="SSS";
	cin>>n;
	cin>>s;
	if(s[0]=='o')
	{
		for(int j=0;j<4;j++)
		{
			if(flag==1)
			{
				break;
			}
			for(int i=0;i<n;i++)
			{
				if(i==0)
				{
					//cerr<<o[j][0]<<o[j][1]<<o[j][2]<<endl;
					a_last=o[j][0];
					a[0]=o[j][1];
					a[1]=o[j][2];
					//cerr<<a_last<<endl;
				}else if(i==n-1){
					if(a[i-1]=='S'&&a[i]=='S'&&s[i]=='o')
					{
						a_begin='S';
					}else if(a[i-1]=='S'&&a[i]=='S'&&s[i]=='x')
					{
						a_begin='W';
					}else if(a[i-1]=='S'&&a[i]=='W'&&s[i]=='o')
					{
						a_begin='W';
					}else if(a[i-1]=='S'&&a[i]=='W'&&s[i]=='x')
					{
						a_begin='S';
					}else if(a[i-1]=='W'&&a[i]=='S'&&s[i]=='o')
					{
						a_begin='W';
					}else if(a[i-1]=='W'&&a[i]=='S'&&s[i]=='x')
					{
						a_begin='S';
					}else if(a[i-1]=='W'&&a[i]=='W'&&s[i]=='o')
					{
						a_begin='S';
					}else if(a[i-1]=='W'&&a[i]=='W'&&s[i]=='x')
					{
						a_begin='W';
					}
					if(a_begin==a[0]&&a_last==a[i])
					{
						//cerr<<"done"<<endl;
						flag=1;
						break;
					}
				}else{
					if(a[i-1]=='S'&&a[i]=='S'&&s[i]=='o')
					{
						a[i+1]='S';
					}else if(a[i-1]=='S'&&a[i]=='S'&&s[i]=='x')
					{
						a[i+1]='W';
					}else if(a[i-1]=='S'&&a[i]=='W'&&s[i]=='o')
					{
						a[i+1]='W';
					}else if(a[i-1]=='S'&&a[i]=='W'&&s[i]=='x')
					{
						a[i+1]='S';
					}else if(a[i-1]=='W'&&a[i]=='S'&&s[i]=='o')
					{
						a[i+1]='W';
					}else if(a[i-1]=='W'&&a[i]=='S'&&s[i]=='x')
					{
						a[i+1]='S';
					}else if(a[i-1]=='W'&&a[i]=='W'&&s[i]=='o')
					{
						a[i+1]='S';
					}else if(a[i-1]=='W'&&a[i]=='W'&&s[i]=='x')
					{
						a[i+1]='W';
					}
				}
			}
		}
	}else{
			for(int j=0;j<4;j++)
			{
				if(flag==1)
				{
					break;
				}
				for(int i=0;i<n;i++)
				{
					if(i==0)
					{
					a_last=x[j][0];
					a[0]=x[j][1];
					a[1]=x[j][2];
				}else if(i==n-1){
					if(a[i-1]=='S'&&a[i]=='S'&&s[i]=='o')
					{
						a_begin='S';
					}else if(a[i-1]=='S'&&a[i]=='S'&&s[i]=='x')
					{
						a_begin='W';
					}else if(a[i-1]=='S'&&a[i]=='W'&&s[i]=='o')
					{
						a_begin='W';
					}else if(a[i-1]=='S'&&a[i]=='W'&&s[i]=='x')
					{
						a_begin='S';
					}else if(a[i-1]=='W'&&a[i]=='S'&&s[i]=='o')
					{
						a_begin='W';
					}else if(a[i-1]=='W'&&a[i]=='S'&&s[i]=='x')
					{
						a_begin='S';
					}else if(a[i-1]=='W'&&a[i]=='W'&&s[i]=='o')
					{
						a_begin='S';
					}else if(a[i-1]=='W'&&a[i]=='W'&&s[i]=='x')
					{
						a_begin='W';
					}
					if(a_begin==a[0]&&a_last==a[i])
					{
						flag=1;
						break;
					}
				}else{
					if(a[i-1]=='S'&&a[i]=='S'&&s[i]=='o')
					{
						a[i+1]='S';
					}else if(a[i-1]=='S'&&a[i]=='S'&&s[i]=='x')
					{
						a[i+1]='W';
					}else if(a[i-1]=='S'&&a[i]=='W'&&s[i]=='o')
					{
						a[i+1]='W';
					}else if(a[i-1]=='S'&&a[i]=='W'&&s[i]=='x')
					{
						a[i+1]='S';
					}else if(a[i-1]=='W'&&a[i]=='S'&&s[i]=='o')
					{
						a[i+1]='W';
					}else if(a[i-1]=='W'&&a[i]=='S'&&s[i]=='x')
					{
						a[i+1]='S';
					}else if(a[i-1]=='W'&&a[i]=='W'&&s[i]=='o')
					{
						a[i+1]='S';
					}else if(a[i-1]=='W'&&a[i]=='W'&&s[i]=='x')
					{
						a[i+1]='W';
					}
				}
				}
			}
	}
	if(flag==1)
	{
		for(int i=0;i<n;i++)
		{
			cout<<a[i];
		}
	}else{
		cout<<-1;
	}
	cout<<endl;
	return 0;
}