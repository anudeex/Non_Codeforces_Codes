/*
Question: NHAY - A Needle in the Haystack
Link: http://www.spoj.com/problems/NHAY/
Algorithm: Z algortihm.
Created: 2017-08-20 13:19 IST 
*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll z[2000005];

string needle, haystack;

void z_function(){
	ll n = haystack.size(), l, r, i, j, k;
	l = 0; r = 0;
	memset(z, 0, sizeof z);
	for(i = 1; i < n; i++){
		if(i <= r){
			z[i] = min(r - i + 1, z[i - l]);
		}
		while(i + z[i] < n and haystack[i + z[i]] == haystack[z[i]]){
			z[i]++;
		}
		if(i + z[i] - 1 > r){
			l = i;
			r = i + z[i] -1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	ll t, i, j, k;
	while(cin >> k){
		cin >> needle >> haystack;
		haystack = needle + '$' + haystack;
		z_function();
		ll count = 0;
		for(i = 0; i < haystack.size(); i++){
			if(z[i] == k){
				count++;
				cout<< i - k - 1 << "\n";
			}
		}
		if(count){
			cout << "\n";
		}
	}
	return 0;
}
