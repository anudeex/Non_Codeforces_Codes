//Another implementation

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector <vector<ll> > matrix;


#define f first
#define s second

const ll mod = 1e9 + 7;
const ll K = 2;

matrix mult(matrix A, matrix B) {
	ll i, j, k;
	matrix C(K, vector <ll> (K));
	for(i = 0; i < K; i++) {
		for(j = 0; j < K; j++) {
			for(k = 0; k < K; k++) {
				C[i][j] += (A[i][k] * B[k][j]) % mod;
			}
		}
	}
	return C;
} 

matrix pow(matrix A, ll n) {
	if(n == 1) {
		return A;
	}
	if(n % 2) {
		return mult(A, pow(A, n - 1));
	}
	matrix X = pow(A, n / 2);
	return mult(X, X);
}

ll fib(ll n) {
	if(n == 0) {
		return 0;
	}
	if(n == 1) {
		return 1;
	}
	matrix T(K, vector<ll> (K));
	T[0][0] = 0;
	T[0][1] = 1;
	T[1][0] = 1;
	T[1][1] = 1;
	vector <ll> F(K);
	F[0] = 0;
	F[1] = 1;
	ll ans = 0, i, j, k;
	T = pow(T, n - 1);
	for(i = 0; i < K; i++) {
		ans += (T[K - 1][i] * F[i]) % mod;
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