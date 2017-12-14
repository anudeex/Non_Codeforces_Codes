/*
Question: DCEPCA03 - Totient Extreme
Link: http://www.spoj.com/problems/DCEPCA03/
Algorithm: Euler Totient Function and Maths.
Created: 2017-12-14 20:08 IST 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxN = 1e4 + 5;

ll phi[maxN];

void initialise() {
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
		phi[i] += phi[i - 1];
	}
}

int main() {
	initialise();
	ll t;
	scanf("%lld", &t);
	while(t--) {
		ll n, i, j, k;
		scanf("%lld", &n);
		ll ans = phi[n] * phi[n];
		printf("%lld\n", ans);
	}
	return 0;
}
