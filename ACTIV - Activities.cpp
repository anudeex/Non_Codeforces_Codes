/*
Question: ACTIV - Activities
Link: http://www.spoj.com/problems/ACTIV/
Algorithm: DP and Implementation.
Created: 2017-08-31 01:46 IST 
*/

#include <bits/stdc++.h>

typedef long long ll;

#define maxN (ll) 100005
#define mod (ll) 100000000

#define f first
#define s second

using namespace std;

ll n, DP[maxN];

pair <ll, ll> arr[maxN];

ll bs(ll x) {
	ll l = 0, r = n - 1, mid, ans = -1;
	while(r >= l) {
		mid = l + (r - l) / 2;
		if(arr[mid].f >= x) {
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return ans;
}

ll solve(ll m) {
	if(m >= n || m == -1) {
		return 0;
	}
	if(DP[m] != -1) {
		return DP[m];
	} 
	ll ans = 1;
	ans += solve(m + 1);
	ans %= mod;
	ll pos = bs(arr[m].s);
	ans += solve(pos);
	ans %= mod;
	return DP[m] = ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	while(1) {
		ll i, j, k;
		cin >> n;
		if(n == -1) {
			return 0;
		}
		for(i = 0; i < n; i++) {
			DP[i] = -1;
			ll a, b;
			cin >> a >> b;
			arr[i] = {a, b};
		}
		sort(arr, arr + n);
		ll ans = solve(0);
		string str = to_string(ans);
		for(i = str.size(); i < 8; i++) {
			str = "0" + str;
		}
		cout << str << "\n";
	}
	return 0;
}