/*
Question: NAJPF - Pattern Find
Link: http://www.spoj.com/problems/NAJPF/
Algorithm: Z Algorithm.
Created: 2017-08-20 18:19 IST 
*/

#include <bits/stdc++.h>

typedef long long ll;

#define maxN (ll)2000005

#define pb push_back
#define f first
#define s second

using namespace std;

ll z[maxN];

void z_function(string& s) {
	ll i, j, k, l = 0, r = 0, n = s.size();
	z[0]=0;
	for(i = 1; i < n; i++) {
		if(i <= r) {
			z[i] = min(r - i + 1, z[i - l]);
		}
		while(i + z[i] < n and s[z[i]] == s[i + z[i]]) {
			z[i]++;
		}
		if(i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] -1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	ll t;
	cin >> t;

	while(t--) {
		ll i, j, k;
		string txt,pat;
		cin >> txt >> pat;
		txt = pat + '$' + txt;
		for(i = 0; i < txt.size(); i++) {
			z[i] = 0;
		}
		z_function(txt);
		vector <ll> ans;
		for(i = pat.size(); i < txt.size(); i++) {
			if(z[i] == pat.size()) {
				ans.pb(i - pat.size());
			}
		}
		if(ans.size()) {
			cout << ans.size() << "\n";
			for(i = 0; i < ans.size(); i++) {
				cout << ans[i] <<" ";
			}
			cout <<"\n\n";
		}
		else {
			cout << "Not Found\n\n";
		}
	}

	return 0;
}
