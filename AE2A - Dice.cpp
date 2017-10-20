/*
Question: AE2A - Dice
Link: http://www.spoj.com/problems/AE2A/
Algorithm: DP (Reduced Bounds)
Created: 2017-10-21 01:10 IST 
*/

/*
For Most cases the answer will be zero. So compute DP table for only small values of n and k.
For higher values of n and k, the answer will be 0.
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxN = 2005;

double dp[maxN][maxN];

double solve(ll n, ll k) {
	if(n == 0 and k == 0) {
		return 1.0;
	}
	if(n >= maxN || k >= maxN || k < n || k > 6 * n) {
		return 0.0;
	}
	if(dp[n][k] != -1.0) {
		return dp[n][k];
	}
	return dp[n][k] = ((1.0/6.0) * (solve(n - 1, k - 1) + solve(n - 1, k - 2) + solve(n - 1, k - 3) + solve(n - 1, k - 4) + solve(n - 1, k - 5) + solve(n - 1, k - 6)));
}

int main() {
	ll t, i, j;
	scanf("%lld", &t);
	for(i = 0; i < maxN; i++) {
		for(j = 0; j < maxN; j++) {
			dp[i][j] = -1.0;
		}
	}
	while(t--) {
		ll n, m, k;
		scanf("%lld %lld", &n, &k);
		double no = solve(n, k);
		ll ans = solve(n, k) * 100;
		printf("%lld\n", ans);
	}
	return 0;
}
