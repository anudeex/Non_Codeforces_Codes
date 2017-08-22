/*
Question: FINDSR - Find String Roots
Link: Z Algorithm, graph and implementation.
Algorithm: 
Created: 2017-08-22 17:25 IST 
*/

#include <bits/stdc++.h>

typedef long long ll;

#define maxN (ll)100005

using namespace std;

ll z[maxN], cnt[maxN];

void z_function(string& s) {
	ll i, j, k, n = s.size(), l = 0, r = 0;
	for(i = 0; i <= n; i++) {
		cnt[i] = z[i] = 0;
	}
	for(i = 1; i < n; i++) {
		if(i <= r) {
			z[i] = min(r - i + 1, z[i - l]);
		}
		while(i + z[i] < n and s[i + z[i]] == s[z[i]]) {
			z[i]++;
		}
		cnt[z[i]]++;
		if(i + z[i] - 1 > r) {
			r = i + z[i] - 1;
			l = i;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	while(1) {
		string s;
		cin >> s;
		if(s == "*") {
			return 0;
		}
		ll i, j, k, n = s.size();
		z_function(s);
		cnt[n]++;
		for(i = n - 1; i >=0; i--) {
			cnt[i] += cnt[i + 1];
		}
		bool flag = 0;
		ll ans = 1;
		for(i = n - 1; i >= 0; i--) {
			if(i + z[i] == n and z[i] * cnt[z[i]] == n) {
				ans = cnt[z[i]];
				flag = 1;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

