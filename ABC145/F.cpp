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
struct segtree {
    int N;
		ll dat[2*300];
    segtree() {}
    segtree(int n) {
        N = 1;
        while(N < n) N *= 2;
        for(int i = 0; i < 2*N-1; i++)
            dat[i] = 1e14-1;
    }
    // update k th element
    void update(int k, ll a) {
        k += N-1; // leaf
        dat[k] = min(a,dat[k]);
        while(k > 0) {
            k = (k - 1) / 2;
            dat[k] = min(dat[k*2+1], dat[k*2+2]);
        }
    }
    // min [a, b)
    ll query(int a, int b) { return query(a, b, 0, 0, N); }
    ll query(int a, int b, int k, int l, int r) {
        if(r <= a || b <= l) return 1e14-1;
        if(a <= l && r <= b) return dat[k];
        int m = (l + r) / 2;
        return min(query(a, b, k*2+1, l, m), query(a, b, k*2+2, m, r));
    }
		ll get(int l,int r)
		{
			ll ret=0;
			ll now=0;
			ll q=query(l,r);
			ret+=q-now;
			now=q;
			//境目で探索
		}
};
ll h[300];
int main()
{
	int n,k;
	ll ans=0;
	cin>>n>>k;
	segtree t=segtree(n);
	for(int i=0;i<n;i++)
	{
		cin>>h[i];
		update(i,h[i]);
	}
	cout<<ans<<endl;
	return 0;
}