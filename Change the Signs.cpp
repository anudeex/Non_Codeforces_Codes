/*
By: anudeex_cr7 (anudeexshetty97@gmail.com)
Question: Change the Signs
Link: https://www.codechef.com/problems/CHSIGN
Algorithm: DP + Implementation.
Created: 2018-05-19 15:29 IST 
*/


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxN = 1e5 + 5;

const ll inf = 1e15;

ll dp[maxN][3][3];

ll arr[maxN], val[maxN];

ll solve(ll n, ll prev, ll prevv) {
	if(n < 0) {
		ll a = arr[n + 2] * (prevv - 1), b = arr[n + 1] * (prev - 1);
		if(a + b <= 0) return inf;
		return 0;
	}
	if(dp[n][prev][prevv] != -1) return dp[n][prev][prevv];
	ll a = arr[n + 2] * (prevv - 1), b = arr[n + 1] * (prev - 1), c = arr[n];
	ll ans1, ans2;
	if((a + b <= 0) || (b + c <= 0) || (a + b + c <= 0))
		ans1 =  inf;
	else 
		ans1 = c + solve(n - 1, 2, prev);
	c *= -1;
	if((a + b <= 0) || (b + c <= 0) || (a + b + c <= 0)) 
		ans2 = inf;
	else 
		ans2 = c + solve(n - 1, 0, prev);
	return dp[n][prev][prevv] = min(ans1, ans2);
}

void solve1(ll n, ll prev, ll prevv) {
	if(n < 0) return;
	ll a = arr[n + 2] * (prevv - 1), b = arr[n + 1] * (prev - 1), c = arr[n];
	ll ans1, ans2;
	if((a + b <= 0) || (b + c <= 0) || (a + b + c <= 0))
		ans1 =  inf;
	else 
		ans1 = c + solve(n - 1, 2, prev);
	c *= -1;
	if((a + b <= 0) || (b + c <= 0) || (a + b + c <= 0)) 
		ans2 = inf;
	else 
		ans2 = c + solve(n - 1, 0, prev);
	if(ans1 <= ans2) {
		val[n] = 1;
		solve1(n - 1, 2, prev);
	}
	else {
		val[n] = -1;
		solve1(n - 1, 0, prev);
	}
}

int main() {
	ll t;
	scanf("%lld", &t);
	while(t--) {
		ll n, i, j, k;
		scanf("%lld", &n);
		for(i = 0; i < n; i++) {
			scanf("%lld", &arr[i]);
			val[i] = 1;
			dp[i][0][0] = dp[i][0][2] = -1;
			dp[i][2][0] = dp[i][2][2] = -1;
		}
		ll ans1 = arr[n - 1] + arr[n - 2] + solve(n - 3, 2, 2), ans2 = arr[n - 1] + (-1 * arr[n - 2]) + solve(n - 3, 0, 2), ans3 = (-1 * arr[n - 1]) + arr[n - 2] + solve(n - 3, 2, 0);
		ll mini = min(ans1, min(ans2, ans3));
		if(ans1 == mini) {
			val[n - 1] = 1;
			val[n - 2] = 1;
			solve1(n - 3, 2, 2);
		}
		else if(ans2 == mini) {
			val[n - 1] = 1;
			val[n - 2] = -1;
			solve1(n - 3, 0, 2);
		}
		else {
			val[n - 1] = -1;
			val[n - 2] = 1;
			solve1(n - 3, 2, 0);
		}
		for(i = 0; i < n; i++) {
			printf("%lld ", (val[i] * arr[i]));
		}
		printf("\n");
	}
	return 0;
}
