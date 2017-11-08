/*
Question: IOIPALIN - Palindrome 2000
Link: http://www.spoj.com/problems/IOIPALIN/
Algorithm: DP (Standard DP Algorithm).
Created: 2017-11-08 22:43 IST 
*/

#include <bits/stdc++.h>

using namespace std;

typedef int ll;

const ll INF = 1e9;

ll DP[5005][5005];

string s;

ll solve(ll l, ll r) {
	if(l > r) {
		return INF;
	}
	if(l == r) {
		return 0;
	}
	if(r - l == 1) {
		return (s[l] == s[r] ? 0 : 1);
	}
	if(DP[l][r] != -1) {
		return DP[l][r];
	}
	ll ans;
	if(s[l] == s[r]) {
		ans = solve(l + 1, r - 1);
	}
	else{
		 ans = 1 + min(solve(l + 1, r), solve(l, r - 1));
	}
	return DP[l][r] = ans;
}

int main() {
	ios_base :: sync_with_stdio(0);
	memset(DP, -1, sizeof DP);
	ll n, i, j, k;
	cin >> n;
	cin >> s;
	ll ans = solve(0, n - 1);
	cout << ans << "\n";
	return 0;
}
