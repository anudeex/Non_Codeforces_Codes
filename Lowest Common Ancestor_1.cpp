/*
By: anudeex_cr7 (anudeexshetty97@gmail.com)
Question: Lowest Common Ancestor
Link: https://www.codechef.com/problems/TALCA
Algorithm: LCA + Implementation.
Created: 2018-01-25 00:18 IST 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back

const ll maxN = 2e5 + 5;
const ll maxlog = 20;

/*
References:
https://discuss.codechef.com/questions/48548/talca-editorial
https://stackoverflow.com/questions/25371865/find-multiple-lcas-in-unrooted-tree?rq=1
*/

vector <ll> graph[maxN];

ll par[maxN][maxlog], h[maxN];

void initialise(ll n) {
	ll i, j, k;
	for(i = 1; i <= n; i++) {
		for(j = 0; j < maxlog; j++) {
			par[i][j] = -1;
		}
		h[i] = 0;
	}
}

void dfs(ll curr, ll prev) {
	par[curr][0] = prev;
	ll i, j, k;
	if(prev != -1) {
		h[curr] = h[prev] + 1;
	} 
	for(i = 1; i < maxlog; i++) {
		if(par[curr][i - 1] != -1) {
			par[curr][i] = par[par[curr][i - 1]][i - 1];
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

ll _lca(ll u, ll v) {
	ll i, j, k;
	if(h[u] > h[v]) {
		swap(u, v);
	}
	for(i = maxlog - 1; i >= 0; i--) {
		if(par[v][i] != -1 and h[par[v][i]] >= h[u]) {
			v = par[v][i];
		}
	}
	if(u == v) {
		return u;
	}
	for(i = maxlog - 1; i >= 0; i--) {
		if(par[v][i] != par[u][i]) {
			v = par[v][i];
			u = par[u][i];
		}
	}
	return par[u][0];
}

ll dist(ll u, ll v) {
	ll lca = _lca(u, v);
	return (h[u] + h[v] - (2 * h[lca]));
}

ll solve(ll r, ll u, ll v) {
	ll i, j, k;
	ll ans, sum = 1e10, temp, no;
	no = r;
	temp = dist(no, u) + dist(no, v) + dist(no, r);
	if(sum > temp) {
		ans = no;
		sum = temp;
	}
	no = u;
	temp = dist(no, u) + dist(no, v) + dist(no, r);
	if(sum > temp) {
		ans = no;
		sum = temp;
	}
	no = v;
	temp = dist(no, u) + dist(no, v) + dist(no, r);
	if(sum > temp) {
		ans = no;
		sum = temp;
	}
	no = _lca(u, v);
	temp = dist(no, u) + dist(no, v) + dist(no, r);
	if(sum > temp) {
		ans = no;
		sum = temp;
	}
	no = _lca(r, u);
	temp = dist(no, u) + dist(no, v) + dist(no, r);
	if(sum > temp) {
		ans = no;
		sum = temp;
	}
	no = _lca(r, v);
	temp = dist(no, u) + dist(no, v) + dist(no, r);
	if(sum > temp) {
		ans = no;
		sum = temp;
	}
	return ans;
}

int main() {
	ll n, i, j, k;
	scanf("%lld", &n);
	initialise(n);
	for(i = 1; i < n; i++) {
		ll a, b;
		scanf("%lld %lld", &a, &b);
		graph[a].pb(b);
		graph[b].pb(a);
	}
	dfs(1, -1);
	ll q;
	scanf("%lld", &q);
	while(q--) {
		ll r, u, v;
		scanf("%lld %lld %lld", &r, &u, &v);
		ll ans = solve(r, u, v);
		printf("%lld\n", ans);
	}
	return 0;
}

