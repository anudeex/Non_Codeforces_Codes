/*
By: anudeex_cr7 (anudeexshetty97@gmail.com)
Question: S-T Mincut
Link: https://www.codechef.com/MAY18B/problems/STMINCUT
Algorithm: DSU + Graph + Implementation.
Created: 2018-05-21 02:08 IST
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define f first
#define s second
#define pb push_back

const ll maxN = 1005;

const ll inf = 1e15;

ll parent[maxN], size[maxN], wt[maxN];

void initialise(ll n) {
	ll i, j, k;
	for(i = 1; i <= n; i++) {
		size[i] = 1;
		parent[i] = i;
		wt[i] = 0;
	}
}

ll root(ll i) {
	while(parent[i] != i) {
		i = parent[i];
	}
	return i;
}

ll depth(ll i) {
	ll ans = 0;
	while(parent[i] != i) {
		ans++;
		i = parent[i];
	}
	return ans;
}

void unionn(ll a, ll b, ll w) {
	ll root_a = root(a), root_b = root(b);
	if(root_a == root_b) return;
	ll size_a = size[a], size_b = size[b];
	if(size_a >= size_b) {
		parent[root_b] = root_a;
		size[root_a] += size[root_b];
		wt[root_b] = w;
	}
	else {
		parent[root_a] = root_b;
		size[root_b] += size[root_a];
		wt[root_a] = w;
	}
}

ll solve(ll u, ll v) {
	ll depth_u = depth(u), depth_v = depth(v);
	ll ans = inf;
	if(depth_u > depth_v) {
		ll no = depth_u - depth_v;
		while(no--) {
			ans = min(ans, wt[u]);
			u = parent[u];
		}
	}
	else if(depth_u < depth_v) {
		ll no = depth_v - depth_u;
		while(no--) {
			ans = min(ans, wt[v]);
			v = parent[v];
		}
	}
	while(u != v) {
		ans = min(ans, wt[v]);
		v = parent[v];
		ans = min(ans, wt[u]);
		u = parent[u];
	}
	return ans;
}

int main() {
	ll t;
	scanf("%lld", &t);
	while(t--) {
		ll n, i, j, k;
		scanf("%lld", &n);
		initialise(n);
		ll arr[n + 1][n + 1];
		for(i = 1; i <= n; i++) {
			for(j = 1; j <= n; j++) {
				scanf("%lld", &arr[i][j]);
			}
		}
		ll ans = 0;
		priority_queue < pair < ll, pair < ll, ll > > > Q;
		for(i = 1; i <= n; i++) {
			for(j = 1; j <= n; j++) {
				if(i != j)
					Q.push({arr[i][j], {i, j}});
			}
		}
		while(!Q.empty()) {
			ll curr_w = Q.top().f, curr_u = Q.top().s.f, curr_v = Q.top().s.s;
			Q.pop();
			if(root(curr_u) == root(curr_v)) {
				ll mini = solve(curr_u, curr_v);
				ans += (mini - curr_w);
			}
			else {
				unionn(curr_u, curr_v, curr_w);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
