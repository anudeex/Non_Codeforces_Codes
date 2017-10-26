/*
Question: Cards Game
Link: https://code.google.com/codejam/contest/3254486/dashboard#s=p1
Algorithm: MST + Implementation.
Created: 2017-10-26 23:31 IST 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxN = 105;

#define pb push_back
#define f first
#define s second

vector < pair < ll, ll > > graph[maxN]; 

bool visited[maxN];

ll prim() {
	ll ans = 0;
	priority_queue < pair < ll, ll > > pq;
	pq.push({0, 1});
	while (pq.size()) {
		ll curr = pq.top().s, wt = -1 * pq.top().f;
		pq.pop();
		if (visited[curr]) continue;
		visited[curr] = 1;
		ans += wt;
		for (auto it : graph[curr]) {
			ll new_curr = it.f, w = -1 * it.s;
			if (visited[new_curr]) continue;
			pq.push({w, new_curr});
		}
	}
	return ans;
}

int main() {
	freopen ("B-large-practice.in", "r", stdin);
	freopen ("out.txt", "w", stdout);
	ll t, l;
	scanf("%lld", &t);
	for (l = 1; l <= t; l++) {
		ll n, i, j, k;
		scanf("%lld", &n);
		ll R[n], B[n];
		for (i = 0; i < n; i++) {
			visited[i] = 0;
			graph[i].clear();
			scanf("%lld", &R[i]);
		}
		for (i = 0; i < n; i++) {
			scanf("%lld", &B[i]);
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (i == j) continue;
				graph[i].pb({j, R[i] ^ B[j]});
				graph[i].pb({j, B[i] ^ R[j]});
			}
		}
		ll ans = prim();
		printf("Case #%lld: %lld\n", l, ans);
	}
	return 0;
 }
