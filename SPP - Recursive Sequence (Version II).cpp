/*
Question: SPP - Recursive Sequence (Version II)
Link: http://www.spoj.com/problems/SPP/
Algorithm: Matrix Exponentiation and Implementation.
Created: 2017-09-10 14:31 IST 
*/

#include <bits/stdc++.h>

typedef long long ll;

const ll maxK = 17;

using namespace std;

ll mod, sz1, sz2, T[maxK][maxK], b[maxK], c[maxK], F[maxK], S[maxK];

void mult(ll A[maxK][maxK], ll B[maxK][maxK]) {
	ll i, j, k ;
	ll C[maxK][maxK] = {};
	for(i = 0; i < sz2; i++) {
		for(j = 0; j < sz2; j++) {
			for(k = 0; k < sz2; k++) {
				ll val = (A[i][k] * B[k][j]) % mod;
				C[i][j] += val;
				C[i][j] %= mod;
			}
		}
	}
	for(i = 0; i < sz2; i++) {
		for(j = 0; j < sz2; j++) {
			A[i][j] = C[i][j];
		}
	}
}

void pow(ll n) {
	ll i, j, k;
	ll ans[maxK][maxK], A[maxK][maxK];
	for(i = 0; i < sz2; i++) {
		for(j = 0; j < sz2; j++) {
			A[i][j] = T[i][j];
			ans[i][j] = 0;
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
	for(i = 0; i < sz2; i++) {
		for(j = 0; j < sz2; j++) {
			T[i][j] = ans[i][j];
		}
	}
}

ll fib(ll n) {
	ll i, j, k;
	if(n <= sz1) {
		return S[n - 1];
	}
	j = sz1 - 1;
	for(i = 1; i < sz2; i++) {
		F[i] = b[j];
		j--;
	}
	F[0] = S[sz1 - 1];
 	for(i = 0; i < sz2; i++) {
 		for(j = 0; j < sz2; j++) {
 			T[i][j] = 0;
 		}
 		cout << "\n";
 	}
	for(i = 1; i < sz2; i++) {
		T[0][i] = T[1][i] = c[i - 1];
	}
	T[0][0] = 1;
	for(i = 2; i < sz2; i++) {
		T[i][i - 1] = 1;
 	}
 	pow(n - sz1);
 	ll ans = 0;
 	for(i = 0 ; i < sz2; i++) {
 		ll temp = (T[0][i] * F[i]) % mod;
 		ans = (ans + temp) % mod;
 	}
 	return ans;
}

int main() {
	ll t, i, j, k;
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld", &sz1);
		sz2 = sz1 + 1;
		for(i = 0; i < sz2; i++) {
			for(j = 0; j < sz2; j++) {
				T[i][j] = 0;
			}
			b[i] = S[i] = c[i] = F[i] = 0;
		}
		for(i = 0; i < sz1; i++) {
			scanf("%lld", &b[i]);
		}
		for(i = 0; i < sz1; i++) {
			scanf("%lld", &c[i]);
		}
		S[0] = b[0];
		for(i = 1; i < sz1; i++) {
			S[i] = S[i - 1] + b[i];
		}
		ll n, m;
		scanf("%lld %lld %lld", &n, &m, &mod);
		n--;
		ll ans = (fib(m) - fib(n)) % mod;
		ans += mod;
		ans %= mod;
		printf("%lld\n", ans);
	}
	return 0;
}

