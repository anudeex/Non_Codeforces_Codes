/*
Question: BOTTOM - The Bottom of a Graph
Link: http://www.spoj.com/problems/BOTTOM/
Algorithm: SCC and Implementation.
Created: 2017-08-23 23:08 IST 
*/

/*
Similar to CAPCITY SPOJ problem.
*/

#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define f first
#define s second

#define maxN (ll)5005

using namespace std;

vector <ll> graph1[maxN], graph2[maxN], v;

bool visited[maxN];

ll scc_no[maxN], outdegree[maxN];

stack <ll> s;

void dfs1(ll curr) {
	ll i, j, k;
	visited[curr] = 1;
	for(auto it : graph1[curr]) {
		if(visited[it]) continue;
		dfs1(it);
	}
	s.push(curr);
}

void dfs2(ll curr, ll no) {
	ll i, j, k;
	visited[curr] = 1;
	scc_no[curr] = no;
	for(auto it : graph2[curr]) {
		if(visited[it]) continue;
		dfs2(it, no);
	}
}

bool bs(ll x) {
	ll l = 0, r = v.size(), mid;
	while(r >= l) {
		mid = l + (r - l) / 2;
		if(v[mid] == x) {
			return 1;
		}
		if(v[mid] > x) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return 0;
}

int main() {
	while(1) {
		ll n, m, i, j, k;
		scanf("%lld", &n);
		v.clear();
		if(n == 0){
			return 0;
		}
		scanf("%lld ", &m);
		for(i = 0; i <= n; i++) {
			graph1[i].clear();
			graph2[i].clear();
			outdegree[i] = 0;
			visited[i] = 0;
		}
		for(i = 0; i < m; i++) {
			ll a, b;
			scanf("%lld %lld", &a, &b);
			graph1[a].pb(b);
			graph2[b].pb(a);
		}
		for(i = 1; i <= n; i++) {
			if(visited[i]) continue;
			dfs1(i);
		}
		for(i = 0; i <= n; i++) {
			visited[i] = 0;
		}
		ll no = 1;
		while(s.size()) {
			ll p = s.top();
			s.pop();
			if(visited[p]) continue;
			dfs2(p, no);
			no++;
		}
		for(i = 1; i <= n; i++) {
			for(auto it : graph1[i]) {
				if(scc_no[i] != scc_no[it]) {
					outdegree[scc_no[i]]++;
				}
			}
		}
		ll count = 0;
		for(i = 1; i < no; i++) {
			if(outdegree[i] == 0) {
				v.pb(i);
			}
		}
		for(i = 1; i <= n; i++) {
			if(bs(scc_no[i])) {
				printf("%lld ", i);
			}
		}
		printf("\n");
	}
	return 0;
}
