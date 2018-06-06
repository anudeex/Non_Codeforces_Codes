/*
By: anudeex_cr7 (anudeexshetty97@gmail.com)
Question: EPALIN - Extend to Palindrome
Link: http://www.spoj.com/problems/EPALIN/
Algorithm: KMP.
Created: 2018-06-07 02:37 IST 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios_base :: sync_with_stdio(0);
	string s;
	while(cin >> s) {
		ll n = s.size(), i, j, k;
		string rev = s, s1 = s;
		reverse(rev.begin(), rev.end());
		s  = rev + '$' + s;
		//cout << "S is " << s << "\n";
		i = 0; j = 1;
		n  = s.size();
		ll lps[n] = {};
		while(j < n) {
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
		//cout << "Lps is ";
		//for(i = 0; i < n; i++) {
		//	cout << lps[i] << " ";
		//}
		//cout << "\n";
		ll index = lps[n - 1];
		n = s1.size();
		//cout << "Index is " << index << "\n";
		for(i = index; i < n; i++) {
			s1 += rev[i]; 
		}
		cout << s1 << "\n";
	}
	return 0;
}

