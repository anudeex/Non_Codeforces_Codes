/*
Question: FIBOSUM - Fibonacci Sum
Link: http://www.spoj.com/problems/FIBOSUM/
Algorithm: DP, Math and Implementation.
Created: 2017-09-09 00:33 IST 
*/

/*
F(2n) = (2F(n - 1) + F(n)) * F(n)
F(2n + 1) = F(n)^2 + F(n - 1)^2 
*/

#include <bits/stdc++.h>

typedef long long ll;

const ll mod = 1e9 + 7;
const ll maxN = 1e8 + 5;

using namespace std;

ll DP[maxN];

ll fib(ll n) {
	if(n == 0) return 0;
	if(n == 1) return 1;
	if(n < maxN and DP[n] != -1) {
		return DP[n];
	}
	ll ans, a, b, N = n;
	if(n % 2 == 1) {
		n = (n + 1) / 2;
		a = fib(n), b = fib(n - 1);
		ans = (((a * a) % mod) + ((b * b) % mod)) % mod; 	
	}
	else {
		n = (n + 1) / 2;
		a = fib(n), b = fib(n - 1);
		ans = (((2 * a * b) % mod) + ((a * a) % mod)) % mod;
	}
	if(N < maxN) {
		DP[N] = ans;
	}
	return ans;
}

int main() {
	memset(DP, -1 ,sizeof DP);
	ll t;
	scanf("%lld", &t);
	while(t--) {
		ll a, b, i, j, k;
		scanf("%lld %lld", &a, &b);
		a--;
		ll ans = fib(b + 2) - fib(a + 2);
		ans += mod;
		ans %= mod;
		printf("%lld\n", ans);
	}
	return 0;
}
