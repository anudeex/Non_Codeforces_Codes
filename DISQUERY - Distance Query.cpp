/*
By: anudeex_cr7 (anudeexshetty97@gmail.com)
Question: DISQUERY - Distance Query
Link: http://www.spoj.com/problems/DISQUERY/
Algorithm: LCA + Implementation.
Created: 2018-01-24 02:09 IST 
*/

/*
Ref: https://stackoverflow.com/questions/36083410/how-to-solve-spoj-disquery
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define f first
#define s second

const ll maxN = 1e5 + 5;
const ll maxlog = 20;

vector <pair<ll, ll>> graph[maxN];

ll par[maxN][maxlog], h[maxN], mini[maxN][maxlog], maxi[maxN][maxlog];

void dfs(ll curr, ll prev, ll edge) {
	ll i, j, k;
	par[curr][0] = prev;
	if(prev != -1) {
		h[curr] = h[prev] + 1;
		mini[curr][0] = maxi[curr][0] = edge;
	}
	for(i = 1; i < maxlog; i++) {
		if(par[curr][i - 1] != -1) {
			par[curr][i] = par[par[curr][i - 1]][i - 1];
			maxi[curr][i] = max(maxi[curr][i - 1], maxi[par[curr][i - 1]][i - 1]);
			mini[curr][i] = min(mini[curr][i - 1], mini[par[curr][i - 1]][i - 1]);
		}
		else {
			break;
		}
	}
	for(auto it : graph[curr]) {
		if(it.f != prev) {
			dfs(it.f, curr, it.s);
		}
	}
}

pair <ll, ll> lca(ll u, ll v) {
	ll i, j, k;
	ll ansMini = 1e10, ansMaxi = -1;
	if(h[u] > h[v]) {
		swap(u, v);
	}
	for(i = maxlog - 1; i >= 0; i--) {
		if(par[v][i] != -1 and h[par[v][i]] >= h[u]) {
			ansMini = min(ansMini, mini[v][i]);
			ansMaxi = max(ansMaxi, maxi[v][i]);
			v = par[v][i];
		} 
	}
	if(v == u) {
		return {ansMini, ansMaxi};
	}
	for(i = maxlog - 1; i >= 0; i--) {
		if(par[v][i] != par[u][i]) {
			ansMini = min(ansMini, mini[v][i]);
			ansMaxi = max(ansMaxi, maxi[v][i]);
			ansMini = min(ansMini, mini[u][i]);
			ansMaxi = max(ansMaxi, maxi[u][i]);
			v = par[v][i];
			u = par[u][i];
		} 
	}
	ansMini = min(ansMini, mini[v][0]);
	ansMaxi = max(ansMaxi, maxi[v][0]);
	ansMini = min(ansMini, mini[u][0]);
	ansMaxi = max(ansMaxi, maxi[u][0]);
	return {ansMini, ansMaxi};
} 

int main() {
	ll n, i, j, k;
	scanf("%lld", &n);
	for(i = 1; i < n; i++) {
		ll u, v, w;
		scanf("%lld %lld %lld", &u, &v, &w);
		graph[u].pb({v, w});
		graph[v].pb({u, w});
	}
	for(i = 1; i <= n; i++) {
		for(j = 0; j < maxlog; j++) {
			par[i][j] = -1;
			maxi[i][j] = -1;
			mini[i][j] = 1e10;
		}
	}
	dfs(1, -1, 0);
	ll q;
	scanf("%lld", &q);
	while(q--) {
		ll u, v;
		scanf("%lld %lld", &u, &v);
		pair <ll, ll> ans = lca(u, v);
		printf("%lld %lld\n", ans.f, ans.s);
	}
	return 0;
}
