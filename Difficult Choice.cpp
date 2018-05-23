/*
By: anudeex_cr7 (anudeexshetty97@gmail.com)
Question: Difficult Choice
Link: https://www.codechef.com/COOK94B/problems/CHEFTRVL
Algorithm: Graph + Implementaion + Number Theory.
Created: 2018-05-24 00:39 IST 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxN = 1e5 + 5;

#define pb push_back

ll arr[maxN];

vector <ll> graph[maxN];

ll quarrel[maxN], no_quarrel[maxN];

bool satisfy[maxN];

ll getDiff(ll u, ll v) {
	return (__builtin_popcountll(u ^ v));
}

bool condition(ll u, ll v, ll dist) {
	ll diff = getDiff(u, v);
	diff &= 1;
	dist &= 1;
	return (diff ^ dist);
}

void dfs(ll u, ll prev, ll dist) {
	satisfy[u] = condition(arr[1], arr[u], dist);
	for(auto it: graph[u]) {
		if(it == prev) continue;
		dfs(it, u, dist + 1);
		ll curr = getDiff(arr[u], arr[it]);
		if(curr & 1) {
			quarrel[u]++;
			quarrel[u] += quarrel[it];
			no_quarrel[u] += no_quarrel[it];
		}
		else {
			no_quarrel[u]++;
			no_quarrel[u] += quarrel[it];
			quarrel[u] += no_quarrel[it];
		}
	}
}

void initialise(ll n) {
	ll i, j, k;
	for(i = 1; i <= n; i++) {
		graph[i].clear();
		quarrel[i] = no_quarrel[i] = satisfy[i] = 0;
	}
}

int main() {
	ll t;
	scanf("%lld", &t);
	while(t--) {
		ll n, i, j, k;
		scanf("%lld", &n);
		initialise(n);
		for(i = 1; i < n; i++) {
			ll u, v;
			scanf("%lld %lld", &u, &v);
			graph[u].pb(v);
			graph[v].pb(u);
		}
		for(i = 1; i <= n; i++) {
			scanf("%lld", &arr[i]);
		}
		quarrel[1] = 1;
		dfs(1, -1, 0);
		ll ans = 0;
		for(i = 1; i <= n; i++) {
			//cout << "I is " << i << " q " << quarrel[i] << " no_q " << no_quarrel[i] << "\n";
			if(satisfy[i]) {
				ans += quarrel[1];
			}
			else {
				ans += no_quarrel[1];
			}
		}
		ans /= 2;
		printf("%lld\n", ans);
	}
	return 0;
}

