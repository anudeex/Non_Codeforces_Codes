/*
Question: FIBOSUM - Fibonacci Sum
Link: http://www.spoj.com/problems/FIBOSUM/
Algorithm: Matrix Exponentiation and Implementation.
Created: 2017-09-08 23:26 IST 
*/

#include <bits/stdc++.h>

typedef long long ll;

const ll K = 2;
const ll mod = 1e9 + 7;

using namespace std;

ll T[K][K], F[K];

void mult(ll A[K][K], ll B[K][K]) {
	ll i, j, k;
	ll C[K][K] = {};
	for(i = 0; i < K; i++) {
		for(j = 0; j < K; j++) {
			for(k = 0; k < K; k++) {
				C[i][j] += (A[i][k] * B[k][j]) % mod;
				C[i][j] %= mod;
			}
		}
	}
	for(i = 0; i < K; i++) {
		for(j = 0; j < K; j++) {
			A[i][j] = C[i][j];
		}
	}
}

void pow(ll n) {
	if(n == 0) {
		return;
	}
	ll A[K][K], ans[K][K] = {}, i, j, k;
	for(i = 0; i < K; i++) {
		for(j = 0; j < K; j++) {
			A[i][j] = T[i][j];
		}
		ans[i][i] = 1;
	}
	while(n) {
		if(n % 2) {
			mult(ans, A);
		}
		mult(A, A);
		n /= 2;
	}
	for(i = 0; i < K; i++) {
		for(j = 0; j < K; j++) {
			T[i][j] = ans[i][j];
		}
	}
}

ll fib(ll n) {
	if(n == 0) return 0;
	if(n == 1) return 1;
	F[0] = 0; F[1] = 1;
	T[0][0] = 0;
	T[0][1] = 1;
	T[1][0] = 1;
	T[1][1] = 1; 
	pow(n - 1);
	ll ans = 0, i, j ,k;
	for(i = 0; i < K; i++) {
		ans += (T[K - 1][i] * F[i]) % mod;
		ans %= mod;
	}
	return ans;
}

int main() {
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
