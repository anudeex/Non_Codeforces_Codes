/*
Question: GCDEX - GCD Extreme
Link: http://www.spoj.com/problems/GCDEX/
Algorithm: Number Theory + Euler Totient Function. 
Created: 2017-12-15 14:08 IST 
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
		for(j = 2; j * i < maxN; j++) {
			ans[i * j] += i * phi[j];
		}
		ans[i] += ans[i - 1];
	}
}

int main() {
	compute_phi();
	solve();
	while(1) {
		ll n;
		scanf("%lld", &n);
		if(n == 0) {
			break;
		}
		printf("%lld\n", ans[n]);
	}
	return 0;
}
