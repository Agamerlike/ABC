#include <iostream>

using namespace std;

	int n,ma,mb;
int m;
int flag;
	int a[40];
	int b[40];
	int c[40];

void saiki(int k,int A,int B,int C)
{
	int w=0;
	A += a[k];
	B += b[k];
	C += c[k];
	//cerr << C << endl;
	if(A%ma==0&&(w=A/ma))
	{
		if(B==mb*w)
		{
			if(m>C)
			{
				flag=1;
				m = C;
			}
		}
	}
	for(int i=k+1;i<n;i++)
	{
		saiki(i,A,B,C);
	}
	return;
}
int main()
{
	m = 1000000;
	flag = 0;
	cin >> n>>ma>>mb;
	for(int i=0;i<n;i++)
	{
		cin >>a[i]>>b[i]>>c[i];
	}
	for(int i=0;i<n;i++)
	{
		saiki(0,0,0,0);
	}
	if(flag==1)
	{
		cout << m << endl;
	}else{
		cout << -1 <<endl;
	}
	return 0;
}