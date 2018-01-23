/*
Question: LCA - Lowest Common Ancestor
Link: http://www.spoj.com/problems/LCA/
Algorithm: LCA.
Created: 2018-01-24 01:26 IST 
By: anudeex_cr7
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back

const ll maxN = 1005;
const ll maxlog = 15;

vector <ll> graph[maxN];

ll par[maxN][maxlog], h[maxN];

void dfs(ll curr, ll prev) {
	ll i, j, k;
	par[curr][0] = prev;
	if(prev != -1) {
		h[curr] = h[prev] + 1;
	}
	for(i = 1; i < maxlog; i++) {
		if(par[curr][i - 1] != -1) {
			par[curr][i] = par[par[curr][i -1]][i - 1];
		}
		else {
			break;
		}
	}
	for(auto it : graph[curr]) {
		if(it != prev) {
			dfs(it, curr);
		}
	}
}

ll lca(ll u, ll v) {
	ll i, j, k;
	if(h[u] > h[v]) {
		swap(u, v);
	}
	for(i = maxlog - 1; i >= 0; i-- ) {
		if(par[v][i] != -1 and h[par[v][i]] >= h[u]) {
			v = par[v][i];
		}
	}
	if(v == u) {
		return u;
	}
	for(i = maxlog - 1; i >= 0; i--) {
		if(par[v][i] != par[u][i]) {
			u = par[u][i];
			v = par[v][i];
		}
	}
	return par[u][0];
}

int main() {
	ll T, t = 1;
	scanf("%lld", &T);
	while(T--) {
		ll N, M, i, j, k;
		scanf("%lld", &N);
		for(i = 1; i <= N; i++) {
			graph[i].clear();
			for(j = 0; j < maxlog; j++) {
				par[i][j] = -1;
			}
			h[i] = 0;
		}
		for(i = 1; i <= N; i++) {
			scanf("%lld", &M);
			for(j = 1; j <= M; j++) {
				ll a;
				scanf("%lld", &a);
				graph[a].pb(i);
				graph[i].pb(a);
			}
		}
		dfs(1, -1);
		ll Q;
		scanf("%lld", &Q);
		printf("Case %lld:\n", t);
		while(Q--) {
			ll u, v;
			scanf("%lld %lld", &u, &v);
			printf("%lld\n", lca(u, v));
		}
		t++;
	}
	return 0;
}
