#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	int w,a,b;
	int ar,br;
	int ans;
	cin>>w>>a>>b;
	ar = a+w;
	br=b+w;
	if(max(abs(ar-b),abs(br-a))<2*w)
	{
		ans=0;
	}else{
		ans=min(abs(br-a),abs(b-ar));
	}
	cout<<ans<<endl;
	return 0;
}