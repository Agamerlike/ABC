#include <iostream>

using namespace std;

int main()
{
	int N;
	int b;
	int uuu;
	long MOD = 1000000007;
	long cnt = 0;
	cin >> N;
	for(int uu=0;uu<=N;uu++)
	{
		for(int vv=0;vv<=N;vv++)
		{
			for(int a=0;a<=vv;a++)
			{
				b = vv-a; //a+b=vv
				uuu = a^b;
				if(b >= 0 && uuu == uu)
				{
					cnt++;
					break;
				}else if(b<0){
					break;
				}
			}
		}
	}
	cout << cnt % MOD << endl;
	return 0;
}