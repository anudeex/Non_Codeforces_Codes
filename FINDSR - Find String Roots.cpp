/*
Question: FINDSR - Find String Roots
Link: http://www.spoj.com/problems/FINDSR/
Algorithm: lps, graph and implementation.
Created: 2017-08-22 12:36 IST 
*/

#include <bits/stdc++.h>

typedef long long ll;

#define maxN (int)100005

#define pb push_back
#define f first
#define s second

using namespace std;

int lps[maxN], cnt[maxN];

vector <int> graph[maxN];

void _lps(string& s) {
	int n = s.size(), i, j, k;
	lps[0] = 0;
	i = 1; j = 0;
	while(i < n) {
		if(s[i] == s[j]) {
			j++;
			lps[i] = j;
			i++;
		}
		else {
			if(j != 0) {
				j = lps[j - 1];
			}
			else {
				lps[i] = j;
				i++;
			}
		}
	}
	/*for(i = 0; i < n; i++) {
		cout << lps[i] << " ";
	}
	cout << "\n";*/
}

void createGraph(int n) {
	int i, j, k;
	for(i = 0; i <= n; i++) {
		graph[i].clear();
	}
	for(i = 0; i < n; i++) {
		graph[i + 1].pb(lps[i]);
		graph[lps[i]].pb(i + 1);
	}
}

void dfs(int curr, int prev) {
	int i, j, k;
	for(auto it : graph[curr]) {
		if(it != prev) {
			cnt[curr]++;
			dfs(it, curr);
			cnt[curr] += cnt[it];
		}
	}
	//cout << "Curr is " << curr << "\n";
	//cout << "Count is " << cnt[curr] << "\n";	
}

void solve(int n) {
	int ans = n, curr = n;
	while(curr) {
		int count = cnt[curr] + 1;
		if(curr * count == n) {
			ans = count; 
		}
		curr = lps[curr - 1];
	}
	printf("%lld\n",ans);
}

int main() {
	ios_base::sync_with_stdio(0);
	while(1) {
		string s;
		cin >> s;
		if(s == "*") {
			return 0;
		}
		int n, i, j, k;
		n = s.size();
		memset(cnt, 0, sizeof cnt);
		_lps(s);
		createGraph(n);
		dfs(0, -1);
		solve(n);
	}
	return 0;
}
