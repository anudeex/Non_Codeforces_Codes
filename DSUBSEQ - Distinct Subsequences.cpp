/*
Question: DSUBSEQ - Distinct Subsequences
Link: http://www.spoj.com/problems/DSUBSEQ/
Algorithm: DP (Classic)
Created: 2017-12-13 19:52 IST 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

int main() {
	ll t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		ll n = s.size(), i, j, k;
		s = '*' + s;
		ll dp[n + 1] = {}, last[26] = {};
		dp[0] = 1;
		for(i = 1; i <= n; i++) {
			dp[i] = (2 * dp[i - 1]) % mod;
			ll idx = s[i] - 'A';
			if(last[idx]) {
				dp[i] = (dp[i] - dp[last[idx] - 1] + mod) % mod;
			}
			last[idx] = i;
		}
		cout << dp[n] << "\n";
	}
	return 0;
}
