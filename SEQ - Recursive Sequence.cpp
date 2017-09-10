/*
Question: SEQ - Recursive Sequence
Link: http://www.spoj.com/problems/SEQ/
Algorithm: Matrix Exponentiation and Implementation.
Created: 2017-09-10 10:50 IST 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1000000000;
const ll maxK = 11;

ll K, b[maxK], c[maxK];
ll T[maxK][maxK], F[maxK];

void mult(ll A[maxK][maxK], ll B[maxK][maxK]) {
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
	ll A[maxK][maxK], ans[maxK][maxK];
	ll i, j, k;
	for(i = 0; i < K; i++) {
		for(j = 0; j < K; j++) {
			ans[i][j] = 0;
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
	ll i, j , k;
	if(n <= K) {
		return b[n - 1];
	}
	for(i = 0; i < K; i++) {
		F[i] = b[i];
	}
	k = K - 1;
	for(i = 0; i < K; i++) {
		for(j = 0; j < K; j++) {
			T[i][j]  = 0;
		}
		T[i][i + 1] = 1;
	}
	for(i = 0; i < K; i++) {
		T[K - 1][i] = c[k];
		k--;
	}
	pow(n - K);
	ll ans = 0;
	for(i = 0; i < K; i++) {
		ll temp = (T[K - 1][i] * F[i]) % mod;
		ans = (ans + temp) % mod;
	}
	return ans;
}

int main() {
	ll t;
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld", &K); 
		ll i, j, k;
		for(i = 0; i < K; i++) {
			scanf("%lld", &b[i]);
		}
		for(i = 0; i < K; i++) {
			scanf("%lld", &c[i]);
		}
		ll n;
		scanf("%lld", &n);
		printf("%lld\n", fib(n));
	}
	return 0;
}
