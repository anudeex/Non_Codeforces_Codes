/*
Question: COINS - Bytelandian gold coins
Link: http://www.spoj.com/problems/COINS/
Algorithm: DP.
Created: 2017-08-31 14:16 IST 
*/

#include <bits/stdc++.h>

typedef long long ll;

#define maxN (ll) 3000005

using namespace std;

ll DP[maxN];

ll solve(ll n) {
	if(n == 0) {
		return 0;
	}
	if(n < maxN and DP[n] != -1) {
		return DP[n];
	}
	ll ans = n;
	ans = max(ans, solve(n / 2) + solve(n / 3) + solve(n / 4));
	if(n < maxN) {
		DP[n] = ans;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	memset(DP, -1, sizeof DP);
	ll n, i, j, k;
	while(cin >> n) {
		cout << solve(n) << "\n";
	}
	return 0;
}
