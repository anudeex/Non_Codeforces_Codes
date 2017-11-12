/*
Question: Matrix Cutting
Link: https://code.google.com/codejam/contest/dashboard?c=3254486#s=p2
Algorithm: Large Test File (4D DP)
Created: 2017-11-12 23:35 IST 
*/

#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
const int maxN = 41;

int arr[maxN][maxN], dp[maxN][maxN][maxN][maxN];

int solve(int x1, int y1, int x2, int y2) {
	if(x1 == x2 and y1 == y2) {
		return 0;
	}
	if(dp[x1][y1][x2][y2] != -1) {
		return dp[x1][y1][x2][y2]; 
	}
	int mini = inf, temp = 0, i, j, k;
	for(i = x1; i <= x2; i++) {
		for(j = y1; j <= y2; j++) {
			mini = min(mini, arr[i][j]);
		}
	}
	for(i = x1; i < x2; i++) {
		temp = max(temp, solve(x1, y1, i, y2) + solve(i + 1, y1, x2, y2));
	}
	for(i = y1; i < y2; i++) {
		temp = max(temp, solve(x1, y1, x2, i) + solve(x1, i + 1, x2, y2));
	}
	return dp[x1][y1][x2][y2] = (temp + mini);
}

int main() {
	freopen("C-large-practice.in", "r", stdin);
	freopen("outC.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for(int p = 1; p <= t; p++) {
		memset(dp, -1, sizeof dp);
		int n, m, i, j, k;
		scanf("%d %d", &n, &m);
		for(i = 0; i < n; i++) {
			for(j = 0; j < m; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		int ans = solve(0, 0, n - 1, m - 1);
		printf("Case #%d: %d\n", p, ans);
	}
}
