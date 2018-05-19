/*
By: anudeex_cr7 (anudeexshetty97@gmail.com)
Question: Fake Binary Search
Link: https://www.codechef.com/problems/FAKEBS
Algorithm: Binary Search + Implementation.
Created: 2018-05-19 01:14 IST 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;

ll bs(ll* arr, ll x) {
	ll l = 0, r = n - 1, mid;
	while(r >= l) {
		mid = l + (r - l) / 2;
		if(arr[mid] == x) return mid;
		if(arr[mid] > x) {
			r = mid - 1;
		}
		else {
			l = mid + 1; 
		}
	}
	return -1;
}

int main() {
	ll t;
	scanf("%lld", &t);
	while(t--) {
		map <ll, ll> m;
		ll q, i, j, k;		
		scanf("%lld %lld", &n, &q);
		ll arr[n], arr1[n];
		for(i = 0; i < n; i++) {
			scanf("%lld", &arr[i]);
			arr1[i] = arr[i];
			m[arr[i]] = i;
		}
		sort(arr1, arr1 + n);
		while(q--) {
			ll x, index;
			scanf("%lld", &x);
			index = m[x];
			ll greater = 0, not_greater = 0, smaller = 0, not_smaller = 0;
			ll mid, l = 0, r = n - 1;
			while(r >= l) {
				mid = l + (r - l) / 2;
				if(index == mid) {
					break;
				}
				else if(index > mid) {
					if(arr[mid] > x) {
						smaller++;
					}
					else {
						not_smaller++;
					}
					l = mid + 1;
				}
				else {
					if(arr[mid] < x) {
						greater++;
					}
					else {
						not_greater++;
					}
					r = mid - 1;
				}
			}
			ll index1 = bs(arr1, x) + 1;
			ll ans = -1;
			if(greater <= (n - index1 - not_greater) && smaller <= (index1 - 1 - not_smaller)) {
				ans = max(greater, smaller);
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}

