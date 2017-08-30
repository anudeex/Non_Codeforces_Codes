/*
Question: TRAFFICN - Traffic Network
Link: http://www.spoj.com/problems/TRAFFICN/
Algorithm: Dijkstra and Implementation.
Created: 2017-08-30 23:05 IST 
*/

#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define f first
#define s second

#define maxN (ll) 10005
#define INF (ll) 1000000000000000000

using namespace std;

vector < pair <ll, ll> > graph1[maxN], graph2[maxN];

bool visited[maxN];

ll dist1[maxN], dist2[maxN];

void dijkstra1(ll x, ll n) {
	ll i, j, k;
	for(i = 0; i <= n; i++) {
		dist1[i] = INF;
	}	
	priority_queue < pair <ll, ll> > q;
	dist1[x] = 0;
	q.push({0, x});
	while(q.size()) {
		ll p = q.top().s;
		q.pop();
		visited[p] = 1;
		for(auto it : graph1[p]) {
			if(visited[it.f]) continue;
			ll curr = it.f, wt = it.s, distance = dist1[p] + wt;
			if(dist1[curr] > distance) {
				dist1[curr] = distance;
				q.push({-1 * distance, curr});
			} 
		}
	}
}

void dijkstra2(ll x, ll n) {
	ll i, j, k;
	for(i = 0; i <= n; i++) {
		dist2[i] = INF;
	}	
	priority_queue < pair <ll, ll> > q;
	dist2[x] = 0;
	q.push({0, x});
	while(q.size()) {
		ll p = q.top().s;
		q.pop();
		visited[p] = 1;
		for(auto it : graph2[p]) {
			if(visited[it.f]) continue;
			ll curr = it.f, wt = it.s, distance = dist2[p] + wt;
			if(dist2[curr] > distance) {
				dist2[curr] = distance;
				q.push({-1 * distance, curr});
			} 
		}
	}
}

int main() {
	ll t;
	scanf("%lld", &t);
	while(t--) {
		ll n, m, k, u, v;
		scanf("%lld %lld %lld %lld %lld", &n, &m, &k, &u, &v);
		ll i, j;
		for(i = 0; i <= n; i++) {
			graph2[i].clear();
			graph1[i].clear();
		}
		for(i = 0; i < m; i++) {
			ll a, b, c;
			scanf("%lld %lld %lld", &a, &b, &c);
			graph1[a].pb({b, c});
			graph2[b].pb({a, c});
		}
		for(i = 0; i <= n; i++) {
			visited[i] = 0;
		}
		dijkstra1(u, n);
		for(i = 0; i <= n; i++) {
			visited[i] = 0;
		}
		dijkstra2(v, n);
		ll ans = dist1[v];
		for(i = 0; i < k; i++) {
			ll a, b, c;
			scanf("%lld %lld %lld", &a, &b, &c);
			ans = min(ans, dist1[a] + c + dist2[b]);
			ans = min(ans, dist1[b] + c + dist2[a]);
		}
		if(ans == INF) {
			ans = -1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
