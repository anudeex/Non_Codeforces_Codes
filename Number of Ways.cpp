#include <bits/stdc++.h>

using namespace std;

typedef int ll;

const ll mod = 1e9 + 7;
const ll maxN = 305;

ll dp[maxN][maxN][maxN][3], dp1[maxN][maxN], dp2[maxN][maxN];

ll add(ll a, ll b) {
	ll ans = ((a % mod) + (b % mod)) % mod;
	return ans;
}

ll substract(ll a, ll b) {
	ll ans = ((a % mod) - (b % mod) + mod) % mod;
	return ans;
}

string A, B, C;

ll n1, n2, n;

ll solve(ll l1, ll l2, ll l, ll type) {
	if(l >= n) {
		return 1;
	}
	if(dp[l1][l2][l][type] != -1) {
		return dp[l1][l2][l][type];
	}
	ll ans = 0;
	if(type != 2 and l1 < n1) {
		ans = add(ans, solve(l1 + 1, l2, l, 1));
		if(A[l1] == C[l]) {
			ans = add(ans, solve(l1 + 1, l2, l + 1, 0));
		}
	}
	if(type != 1 and l2 < n2) {
		ans = add(ans, solve(l1, l2 + 1, l, 2));
		if(B[l2] == C[l]) {
			ans = add(ans, solve(l1, l2 + 1, l + 1, 0));
		}
	}
	return dp[l1][l2][l][type] = ans;
}

ll solveA(ll l1, ll l) {
	if(l >= n) {
		return 1;
	} 
	if(l1 >= n1) {
		return 0;
	}
	if(dp1[l1][l] != -1) {
		return dp1[l1][l];
	}
	ll ans = 0;
	ans = solveA(l1 + 1, l);
	if(A[l1] == C[l]) {
		ans = add(ans, solveA(l1 + 1, l + 1));
	}
	return dp1[l1][l] = ans;
}

ll solveB(ll l2, ll l) {
	if(l >= n) {
		return 1;
	} 
	if(l2 >= n2) {
		return 0;
	}
	if(dp2[l2][l] != -1) {
		return dp2[l2][l];
	}
	ll ans = 0;
	ans = solveB(l2 + 1, l);
	if(B[l2] == C[l]) {
		ans = add(ans, solveB(l2 + 1, l + 1));
	}
	return dp2[l2][l] = ans;
}

int main() {
	ios_base :: sync_with_stdio(0);
	memset(dp, -1, sizeof dp);
	memset(dp1, -1, sizeof dp1);
	memset(dp2, -1, sizeof dp2);
	cin >> A >> B >> C;
	n1 = A.size();
	n2 = B.size();
	n = C.size();
	ll ans, ans1, ans2, ans3;
	ans1 = solve(0, 0, 0, 0);
	ans2 = solveA(0, 0);
	ans3 = solveB(0, 0);
	ans = substract(substract(ans1, ans2), ans3);
	cout << ans << "\n";
	return 0;
}