/*
Question: ETF - Euler Totient Function
Link: http://www.spoj.com/problems/ETF/
Algorithm: Euler Function Simple Implementation.
Created: 2017-12-14 11:56 IST 
*/

/*
Using the concept of sieve and product formula of euler function.
*/

//Brute Force Solution.

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(ll n) {
	ll i, j, k, result = n;
	for(i = 2; i * i <= n; i++) {
		if(n % i == 0) {
			result -= result / i;
			while(n % i == 0) {
				n /= i;
			}
		}
	}
	if(n > 1) {
		result -= result / n;
	}
	return result;
}

int main() {
	ll t;
	scanf("%lld", &t);
	while(t--) {
		ll n, i, j, k;
		scanf("%lld", &n);
		ll ans = solve(n);
		printf("%lld\n", ans);
	}
	return 0;
}