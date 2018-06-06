/*
By: anudeex_cr7 (anudeexshetty97@gmail.com)
Question: TESSER - Finding the Tesserect
Link: http://www.spoj.com/problems/TESSER/
Algorithm: KMP.
Created: 2018-06-07 02:08 IST 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios_base :: sync_with_stdio(0);
	ll t;
	cin >> t;
	while(t--) {
		ll n, i, j, k;
		cin >> n;
		ll arr[n];
		for(i = 0; i < n; i++) {
			cin >> arr[i];
		}
		string s1 = "", s2 = "";
		for(i = 1; i < n; i++) {
			if(arr[i] > arr[i - 1]) {
				s1 += 'G';
			}
			else if(arr[i] < arr[i - 1]) {
				s1 += 'L';
			}
			else {
				s1 += 'E';
			}
		}
		cin >> s2;
		//cout << "s1 is " << s1 << " s2 is " << s2 << "\n";
		ll m = s2.size();
		n--;
		//cout << "Intitial " << n << " " << m << "\n";
		ll temp = m;
		string s = s2 + "$" + s1;
		//cout << "s is " << s << "\n";
		m = n + m + 1;
		n = temp;
		//cout << "Now is " << m << " " << n << "\n";
		i = 0; j = 1;
		ll lps[m] = {};
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
		bool flag = 0;
		for(i = 0; i < m; i++) {
			if(lps[i] == n) {
				//cout << "I is " << i << "\n";
				flag = 1;
				break;
			}
		}
		if(flag) {
			cout << "YES\n";
		} 
		else {
			cout << "NO\n";
		}
	}
	return 0;
}

