/*
Question: Matrix Cutting
Link: https://code.google.com/codejam/contest/dashboard?c=3254486#s=p2
Algorithm: Small Test File (1D DP)
Created: 2017-11-12 23:06 IST 
*/

#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int main() {
	freopen("C-small-practice.in", "r", stdin);
	freopen("outC.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for(int p = 1; p <= t; p++) {
		int n, m, i, j, k, l;
		scanf("%d %d", &n, &m);
		int arr[n][m], dp[m][m] = {};
		for(i = 0; i < n; i++) {
			for(j = 0; j < m; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		for(k = 1; k < m; k++) {
			for(i = 0; i < m- k; i++) {
				j = i + k;
				int mini = inf;
				for(l = i; l <= j; l++) {
					mini = min(mini, arr[0][l]);
				}
				//cout << "I and J are " << i << " " << j << " Mini is " << mini << "\n";
				int temp = 0;
				for(l = i; l < j; l++) {
					temp = max(temp, dp[i][l] + dp[l + 1][j]);
				}
				dp[i][j] = temp + mini;
			}
		}
		printf("Case #%d: %d\n", p, dp[0][m - 1]);
	}
	return 0;
}

