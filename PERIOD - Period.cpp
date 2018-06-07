/*
By: anudeex_cr7 (anudeexshetty97@gmail.com)
Question: PERIOD - Period
Link: http://www.spoj.com/problems/PERIOD/
Algorithm: KMP + Implementation.
Created: 2018-06-07 23:10 IST 
*/

#include <bits/stdc++.h>

using namespace std;

typedef int ll;

int main() {
	ios_base :: sync_with_stdio(0);
	int t;
	cin >> t;
	for(int l = 1; l <= t; l++) {
		cout << "Test case #" << l << "\n";
		ll n, i, j, k;
		cin >> n;
		string s;
		cin >> s;
		ll lps1[n + 1] = {}, lps[n + 1] = {};
		i = 0; j = 1;
		while(j < n) {
			if(s[i] == s[j]) {
				i++;
				lps1[j] = i;
				j++;

			}
			else {
				if(i != 0) {
					i = lps1[i - 1];
				}
				else {
					lps1[j] = 0;
					j++;
				}
			}
		} 
		//cout << "Lps is ";
		for(i = 0; i <= n; i++) {
			if(i >= 1) {
				lps[i] = lps1[i - 1];
			}
			//cout << lps[i] << " ";
		}
		//cout << "\n";
		ll x1, x2, sz;
		for(i = 1; i <= n; i++) {
			if(lps[i] == 0) continue;
			x2 = i; x1 = lps[i];
			sz = x2 - x1;
			if(i % sz == 0) {
				cout << i << " " << (i / sz) << "\n";
			}
		}
	}
	return 0;
}

