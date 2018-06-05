/*
By: anudeex_cr7 (anudeexshetty97@gmail.com)
Question: FILRTEST - File Recover Testing
Link: http://www.spoj.com/problems/TESSER/
Algorithm: Strings (KMP)+ BS.
Created: 2018-06-06 00:44 IST 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios_base :: sync_with_stdio(0);
	while(1) {
		ll n, i, j, k;
		string s;
		cin >> n >> s;
		if(n == -1 and s == "*") break;
		ll m = s.size();
		ll lps[m] = {};
		i = 0; j = 1;
		while(j < m) {
			if(s[i] == s[j]) {
				i++;
				lps[j] = i;
				j++;
			}
			else {
				if(i != 0) {
					i = lps[i - 1];
				}
				else {
					lps[j] = i;
					j++;
				}
			}
		}
		ll no = lps[m - 1];
		ll ans = (n - no) / (m - no);
		if(ans < 0) ans = 0;
		cout << ans << "\n";	
	} 
	return 0;
}

