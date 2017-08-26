/*
Question: SHPATH - The Shortest Path
Link: http://www.spoj.com/problems/SHPATH/
Algorithm: Dijkstra and STL.
Created: 2017-08-26 16:29 IST 
*/

#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define f first
#define s second

#define maxN (ll) 10005
#define INF (ll) 1000000000000000005

using namespace std;

vector <pair <ll, ll> > graph[maxN];

map <string, ll> node;

bool visited[maxN];

ll dist[maxN];

void initialise(ll n) {
	ll i, j, k;
	node.clear();
	for(i = 1; i <= n; i++) {
		visited[i] = 1;
		graph[i].clear(); 
	}
}

void initialise_dijkstra(ll n) {
	ll i, j, k;
	for(i = 1; i <= n; i++) {
		dist[i] = INF;
		visited[i] = 0;
	}
}

void dijkstra(ll p) {
	dist[p] = 0;
	priority_queue <pair<ll, ll> > q;
	q.push({0, p});
	while(q.size()) {
		p = q.top().s;
		q.pop();
		if(visited[p]) continue;
		visited[p] = 1;
		for(auto it : graph[p]) {
			ll wt = it.s, curr = it.f, distance = dist[p] + wt;
			if(dist[curr] > distance) {
				dist[curr] = distance;
				q.push({-1 * distance, curr});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	ll t;
	cin >> t;
	while(t--) {
		ll n, i, j, k;
		cin >> n;
		initialise(n);
		for(i = 1; i <= n; i++) {
			string city;
			cin >> city;
			node[city] = i;
			ll no;
			cin >> no;
			while(no--) {
				ll a, b;
				cin >> a >> b;
				graph[i].pb({a, b});
			}
		}
		ll q;
		cin >> q;
		while(q--) {
			string a, b;
			cin >> a >> b;
			ll no_a = node[a], no_b = node[b];
			initialise_dijkstra(n);
			dijkstra(no_a);
			cout << dist[no_b] << "\n";
		}
	}
	return 0;
}
