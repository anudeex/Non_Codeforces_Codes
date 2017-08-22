/*
Question: CAPCITY - Capital City
Link: http://www.spoj.com/problems/CAPCITY/
Algorithm: SCC and Implementation.
Created: 2017-08-22 23:42 IST 
*/

/*
We should find all the strongly connected components and get an acyclic graph considering SCC Components as a single node.
So, the existence of capital cities implies that only one such node exists whose in-degree is 0. 
If there is no such node, or if there are more than 1 node, the answer is 0. 
Else, we find the original nodes that make up the strongly connected component and list them as the answer.
*/

#include <bits/stdc++.h>

typedef int ll;

#define pb push_back
#define f first
#define s second

#define maxN (ll)200005

using namespace std;

vector <ll> graph1[maxN], graph2[maxN];

bool visited[maxN];

stack <ll> s;

ll scc_no[maxN], outdegree[maxN];

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
	scc_no[curr] = no;
	ll i, j, k;
	visited[curr] = 1;
	for(auto it : graph2[curr]) {
		if(visited[it]) continue;
		dfs2(it, no);
	}
}

int main() {
	ll n, m, i, j, k;
	scanf("%d %d", &n, &m);
	for(i = 0; i < m; i++) {
		ll a, b;
		scanf("%d %d", &a, &b);
		graph2[b].pb(a);
		graph1[a].pb(b);
	}
	for(i = 1; i <= n; i++) {
		if(visited[i]) continue;
		dfs1(i);
	}
	//cout << "DFS1 done\n";
	memset(visited, 0, sizeof visited);
	ll count = 0;
	ll no = 1;
	while(s.size()) {
		ll p = s.top();
		s.pop();
		if(visited[p]) continue;
		dfs2(p, no);
		no++;
	}
	for(i = 1; i <=n; i++) {
		for(auto it : graph1[i]) {
			if(scc_no[i] != scc_no[it]) {
				outdegree[scc_no[i]]++;
			}
		}
	}
	ll ans;
	for(i = 1; i < no; i++) {
		if(outdegree[i] == 0) {
			ans = i;
			count++;
			if(count > 1) {
				printf("0\n");
				return 0;
			}
		}
	}
	vector <ll> v;
	for(i = 1; i <=n; i++) {
		if(scc_no[i] == ans) {
			v.pb(i);
		}
	}
	printf("%lld\n", v.size());
	for(auto it : v) {
		printf("%lld ", it);
	}
	printf("\n");
	return 0;
}
