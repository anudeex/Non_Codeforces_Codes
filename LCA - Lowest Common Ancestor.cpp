/*
Question: LCA - Lowest Common Ancestor 
Link: https://www.codechef.com/problems/TALCA
Algorithm: Lowest Common Ancestor 
Created: 2017-08-10 14:22 IST 
*/

#include <bits/stdc++.h>

typedef long long ll;

#define max_n (int)1005
#define max_log (int)11

#define pb push_back

using namespace std;

vector<int> graph[max_n];

int par[max_n][max_log],h[max_n];

void dfs(int curr,int prev){
	par[curr][0]=prev;
	if(prev!=-1){
		h[curr]=h[prev]+1;
	}
	int i,j,k;
	for(i=1;i<max_log;i++){
		if(par[curr][i-1]!=-1){
			par[curr][i]=par[par[curr][i-1]][i-1];
		}
	}
	for(auto it:graph[curr]){
		if(it!=prev){
			dfs(it,curr);
		}
	}
}

int lca(int u,int v){
	int i,j,k;
	if(h[v]>h[u]){
		swap(u,v);
	}
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

int main(){
	int t,i,j,k;
	scanf("%d",&t);
	for(k=1;k<=t;k++){
		int n;
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			graph[i].clear();
		}
		for(i=1;i<=n;i++){
			int sz;
			scanf("%d",&sz);
			while(sz--){
				scanf("%d",&j);
				graph[i].pb(j);
				graph[j].pb(i);
			}
		}
		memset(par,-1,sizeof par);
		dfs(1,-1);
		int q;
		scanf("%d",&q);
		printf("Case %d:\n",k);
		while(q--){
			int a,b;
			scanf("%d%d",&a,&b);
			printf("%d\n",lca(a,b));
		}
	}
	return 0;
}
