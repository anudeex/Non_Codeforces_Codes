//TRIP - Trip
//http://www.spoj.com/problems/TRIP/

#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll DP[101][101];

set<string> sequences,done[101][101];

string a,b;

ll LCS(ll n,ll m)
{
	if(n==0 || m==0){
		return 0;
	}
	
	if(DP[n][m]!=-1){
		return DP[n][m];
	}
	
	if(a[n-1]==b[m-1]){
		return DP[n][m]=1+LCS(n-1,m-1);
	}

	return DP[n][m]=max(LCS(n-1,m),LCS(n,m-1));
}

void print_all(ll n,ll m,string word)
{
	if(!(done[n][m].find(word)==done[n][m].end())){
		return ;
	}

	if(n==0 || m==0){
		sequences.insert(word);
		return ;
	}

	if(a[n-1]==b[m-1]){
		word=a[n-1]+word;
		print_all(n-1,m-1,word);
	}

	else if(DP[n-1][m]>DP[n][m-1]){
		print_all(n-1,m,word);
	}

	else if(DP[n-1][m]<DP[n][m-1]){
		print_all(n,m-1,word);
	}

	else{
		print_all(n,m-1,word);
		print_all(n-1,m,word);
	}
	done[n][m].insert(word);
}

int main()
{
	ll t;
	scanf("%lld",&t);
	scanf("%lld",&t);
	while(t--)
	{
		memset(DP,-1,sizeof DP);
		sequences.clear();
		for(int i=0;i<101;i++)
		{
			for(int j=0;j<101;j++){
				done[i][j].clear();
			}
		}
		cin>>a>>b;
		ll n=a.size(),m=b.size();
		ll lcs_length=LCS(n,m);
		print_all(n,m,"");
		for(set<string>::iterator it=sequences.begin();it!=sequences.end();it++){
			cout<<*it<<endl;
		}
	}
	return 0;
}
