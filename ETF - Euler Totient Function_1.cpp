/*
Question: ETF - Euler Totient Function
Link: http://www.spoj.com/problems/ETF/
Algorithm: Euler Function Simple Implementation.
Created: 2017-12-14 15:06 IST 
*/

/*
Using the concept of sieve and product formula of euler function.
*/

//Sieve Solution.

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxN = 1e6 + 5;

ll phi[maxN];

ll initialise() {
	ll i, j, k;
	phi[1] = 1;
	for(i = 2; i <= maxN; i++) {
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

int main() {
	initialise();
	ll t;
	scanf("%lld", &t);
	while(t--) {
		ll n, i, j, k;
		scanf("%lld", &n);
		printf("%lld\n", phi[n]);
	}
	return 0;
}