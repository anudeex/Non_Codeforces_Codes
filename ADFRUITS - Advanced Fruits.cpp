/*
Question: ADFRUITS - Advanced Fruits
Link: http://www.spoj.com/problems/ADFRUITS/
Algorithm: LCS + Implementation.
Created: 2017-11-15 01:01 IST 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string a, b;

bool doneA[105], doneB[105];

ll dp[105][105];

ll solve(ll n, ll m) {
	if(n < 0 || m < 0) {
		return 0;
	}
	if(dp[n][m] != -1) {
		return dp[n][m];
	}
	ll ans;
	if(a[n] == b[m]) {
		ans = 1 + solve(n - 1, m - 1);
	}
	else {
		ans = max(solve(n - 1, m), solve(n, m - 1));
	}
	return dp[n][m] = ans;
}

void solve1(ll n, ll m) {
	if(n < 0 || m < 0) {
		return;
	}
	ll ans;
	if(a[n] == b[m]) {
		doneB[m] = 1;
		doneA[n] = 1;
		solve1(n - 1, m - 1);
	}
	else {
		if(solve(n, m - 1) >= solve(n - 1, m)) {
			solve1(n, m - 1);
		}
		else {
			solve1(n - 1, m);
		}
	}
}

string combine() {
	ll n = a.size(), m = b.size(), i, j, k;
	i = 0; j = 0;
	string temp;
	while(i < n and j < m) {
 		if(doneA[i]) {
			if(doneB[j]) {
				temp += a[i];
				i++; j++;
			}
			else {
				temp += b[j];
				j++;
			}
		}
		else {
			temp += a[i];
			i++;
		}
	} 
	while(i < n) {
		temp += a[i];
		i++;
	}
	while(j < m) {
		temp += b[j];
		j++;
	}
	return temp;
}

int main() {
	ios_base :: sync_with_stdio(0);
	ll i, j, k;
	while(cin >> a and cin >> b) {
		memset(doneA, 0, sizeof doneA);
		memset(doneB, 0, sizeof doneB);
		memset(dp, -1, sizeof dp);
		ll n = a.size(), m = b.size();
		ll temp1 = solve(n - 1, m - 1); 
		solve1(n - 1, m - 1);
		string temp = combine();
		cout << temp << "\n";
	}
	return 0;
}
