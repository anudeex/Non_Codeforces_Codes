/*
Question: QTREE2 - Query on a tree II
Link: http://www.spoj.com/problems/QTREE2/
Algorithm: LCA and Implementation
Created: 2017-08-12 01:58 IST 
*/
#include <bits/stdc++.h>

typedef long long ll;

#define max_n (ll)10005
#define max_log (ll)15

#define pb push_back
#define f first
#define s second

using namespace std;

vector<pair<ll,ll>> graph[max_n];

ll par[max_n][max_log],h[max_n],dist[max_n];

void initialize(ll n){
	ll i,j,k;
	for(i=1;i<=n;i++){
		graph[i].clear();
		h[i]=dist[i]=0;
		for(j=0;j<max_log;j++){
			par[i][j]=-1;
		}
	}
}

void dfs(ll curr,ll prev,ll edge){
	par[curr][0]=prev;
	if(prev!=-1){
		h[curr]=h[prev]+1;
		dist[curr]=dist[prev]+edge;
	}
	ll i,j,k;
	for(i=1;i<max_log;i++){
		if(par[curr][i-1]!=-1){
			par[curr][i]=par[par[curr][i-1]][i-1];
		}
	}
	for(auto it: graph[curr]){
		if(it.f!=prev){
			dfs(it.f,curr,it.s);
		}
	}
}

ll lca(ll u,ll v){
	if(h[v]>h[u]){
		swap(u,v);
	}
	ll i,j,k;
	for(i=max_log-1;i>=0;i--){
		if(par[u][i]!=-1 and h[par[u][i]]>=h[v]){
			u=par[u][i];
		}
	}
	if(u==v){
		return u;
	}
	for(i=max_log-1;i>=0;i--){
		if(par[u][i]!=par[v][i]){
			u=par[u][i];
			v=par[v][i];
		}
	}
	return par[u][0];
}

ll get_distance(ll a,ll b){
	ll c=lca(a,b);
	return (dist[a]+dist[b]-2*dist[c]);
}

ll get_kth_node(ll u,ll v,ll k){
	ll a=lca(u,v),d=h[u]+h[v]-2*h[a]+1,i,j;
	if(a==u){
		swap(u,v);
		k=d-k+1;
	}
	else if(a==v);
	else{
		if(k>h[u]-h[a]+1){
			k=d-k+1;
			swap(u,v);
		}
		else;
	}
	k--;
	for(i=max_log-1;i>=0;i--){
		if(par[u][i]!=-1 and ((1<<i)<=k)){
			k-=(1<<i);
			u=par[u][i];
		}
	}
	return u;
}

int main(){
	ios_base::sync_with_stdio(0);
	ll t;
	cin>>t;
	while(t--){
		ll n,i,j,k;
		cin>>n;
		initialize(n);
		for(i=1;i<n;i++){
			ll a,b,c;
			cin>>a>>b>>c;
			graph[a].pb({b,c});
			graph[b].pb({a,c});
		}
		dfs(1,-1,-1);
		while(1){
			string s;
			cin>>s;
			if(s=="DONE"){
				break;
			}
			ll a,b;
			cin>>a>>b;
			if(s=="DIST"){
				cout<<get_distance(a,b)<<"\n";
			}
			else{
				ll c;
				cin>>c;
				cout<<get_kth_node(a,b,c)<<"\n";
			}
		}
	}
	return 0;
}
