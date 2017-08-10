/*
Question: DISQUERY - Distance Query
Link: http://www.spoj.com/problems/DISQUERY/
Algorithm: LCA and Implementation
Created: 2017-08-10 22:16 IST 
*/
#include <bits/stdc++.h>

#define max_n (int)100005
#define max_log (int)20

#define pb push_back
#define f first
#define s second

using namespace std;

vector<pair<int,int>> graph[max_n];

int par[max_n][max_log],par_min[max_n][max_log],par_max[max_n][max_log],h[max_n];

void dfs(int curr,int prev,int edge){
	par[curr][0]=prev;
	if(prev!=-1){
		h[curr]=h[prev]+1;
		par_min[curr][0]=par_max[curr][0]=edge;
	}
	int i,j,k;
	for(i=1;i<max_log;i++){
		if(par[curr][i-1]!=-1){
			par[curr][i]=par[par[curr][i-1]][i-1];
			par_min[curr][i]=min(par_min[par[curr][i-1]][i-1],par_min[curr][i-1]);
			par_max[curr][i]=max(par_max[par[curr][i-1]][i-1],par_max[curr][i-1]);
		}
	}
	for(auto it: graph[curr]){
		if(it.f!=prev)
			dfs(it.f,curr,it.s);
	}
}

pair<int,int> lca(int u,int v){
	if(h[u]<h[v]){
		swap(v,u);
	}
	pair<int,int> ans={1000000,-1};
	int i,j,k;
	for(i=max_log-1;i>=0;i--){
		if(par[u][i]!=-1 and h[par[u][i]]>=h[v]){
			ans.f=min(ans.f,par_min[u][i]);
			ans.s=max(ans.s,par_max[u][i]);
			u=par[u][i];
		}
	}
	if(u==v){
		return ans;
	}
	for(i=max_log-1;i>=0;i--){
		if(par[u][i]!=par[v][i]){
			ans.f=min(ans.f,par_min[u][i]);
			ans.s=max(ans.s,par_max[u][i]);
			ans.f=min(ans.f,par_min[v][i]);
			ans.s=max(ans.s,par_max[v][i]);
			u=par[u][i];
			v=par[v][i];
		}
	}
	ans.f=min(ans.f,par_min[u][0]);
	ans.s=max(ans.s,par_max[u][0]);
	ans.f=min(ans.f,par_min[v][0]);
	ans.s=max(ans.s,par_max[v][0]);
	return ans;
}

int main(){
	int n,i,j,k;
	scanf("%d",&n);
	for(i=1;i<n;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		graph[a].pb({b,c});
		graph[b].pb({a,c});
	}
	for(i=1;i<=n;i++){
		for(j=0;j<max_log;j++){
			par[i][j]=-1;
			par_min[i][j]=1000000;
			par_max[i][j]=-1;
		}
	}
	dfs(1,-1,-1);
	int q;
	scanf("%d",&q);
	while(q--){
		int a,b;
		scanf("%d%d",&a,&b);
		pair<int,int> ans=lca(a,b);
		printf("%d %d\n",ans.f,ans.s);
	}
	return 0;
}