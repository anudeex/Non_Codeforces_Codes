/*
Question: AE2A - Dice
Link: http://www.spoj.com/problems/AE2A/
Algorithm: DP (Reduced Bounds) (Bottoms Up)
Created: 2017-10-21 01:36 IST 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxN = 2005;

int main() {
	ll t, i, j, l;
	double dp[maxN][maxN];
	memset(dp, 0.0, sizeof dp);
	dp[0][0] = 1.0;
	scanf("%lld", &t);
	for(i = 1; i < maxN; i++) {
		for(j = i; j <= min(6 * i, maxN - 1); j++) {
			for(l = 1; l <= 6; l++) {
				if(j - l >= 0)
					dp[i][j] += dp[i - 1][j - l];
			}
			dp[i][j] *= (1.0 / 6.0);
		}
	} 
	while(t--) {
		ll n, k;
		scanf("%lld %lld", &n, &k);
		ll ans = 0;
		if(n < maxN and k < maxN)
			ans = dp[n][k] * 100;
		printf("%lld\n", ans);
	}
	return 0;
}
