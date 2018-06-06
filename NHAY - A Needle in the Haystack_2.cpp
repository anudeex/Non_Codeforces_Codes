/*
By: anudeex_cr7 (anudeexshetty97@gmail.com)
Question: NHAY - A Needle in the Haystack
Link: http://www.spoj.com/problems/NHAY/
Algorithm: KMP (implementation type of Z Algorithm)
Created: 2018-06-06 02:24 IST 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ll n, m, i, j, k;
	while(cin >> m) {
		string needle, haystack, s;
		cin >> needle >> haystack;
		s = needle + '$' + haystack;
		n = haystack.size();
		int temp = m;
		m = n + m + 1;
		n = temp;
		ll lps[m] = {};
		i = 0; j = 1;
		while(j < m) {
			if(s[i] == s[j]) {
				i++;
				lps[j] = i;;
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
		bool got = 0;
		for(i = 0; i < m; i++) {
			if(lps[i] == n) {
				got = 1;
				cout << (i - n - n) << "\n";
			}
		}
		if(!got) cout << "\n";
	}
	return 0;
}

