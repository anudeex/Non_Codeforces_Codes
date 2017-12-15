/*
Question: LCMSUM - LCM Sum
Link: http://www.spoj.com/problems/LCMSUM/
Algorithm: Number Theory (Classic).
Created: 2017-12-15 16:41 IST 
*/

/*
Refer:
https://oeis.org/A051193
https://forthright48.blogspot.in/2015/08/spoj-lcmsum-lcm-sum.html
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxN = 1e6 + 5;

ll phi[maxN], ans[maxN];

void compute_phi() {
	ll i, j, k;
	phi[1] = 1;
	for(i = 2; i < maxN; i++) {
		if(phi[i] == 0) {
			phi[i] = i - 1;
			for(j = (i << 1); j < maxN; j += i) {
				if(phi[j] == 0) {
					phi[j] = j;
				}
				phi[j] -= phi[j] / i;
			}
		}
	}
}

void solve() {
	ll i, j, k;
	for(i = 1; i < maxN; i++) {
		for(j = 1; j * i < maxN; j++) {
			ans[i * j] += i * phi[i];
		}
		ans[i]++;
		ans[i] /= 2;
		ans[i] *= i;
	}
}

int main() {
	compute_phi();
	solve();
	ll t;
	scanf("%lld", &t);
	while(t--) {
		ll n;
		scanf("%lld", &n);
		printf("%lld\n", ans[n]);
	}
	return 0;
}
