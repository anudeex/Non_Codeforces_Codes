//NAJPF - Pattern Find
//http://www.spoj.com/problems/NAJPF/

#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	ll t;
	cin>>t;
	while(t--){
		string text,pattern;
		cin>>text>>pattern;
		ll n=text.size(),m=pattern.size(),i,j,k;
		ll lps[m]={};
		i=1;j=0;
		while(i<m){
			if(pattern[i]==pattern[j]){
				j++;
				lps[i]=j;
				i++;
			}
			else{
				if(j!=0){
					j=lps[j-1];
				}
				else{
					lps[i]=0;
					i++;
				}
			}
		}
		vector<ll> ans;
		i=0; j=0;
		while(i<n){
			if(pattern[j]==text[i]){
				i++;
				j++;
				if(j==m){
					ans.pb(i-m+1);
					j=lps[j-1];
				}
			}
			else{
				if(j!=0){
					j=lps[j-1];
				}
				else{
					i++;
				}
			}
		}
		if(ans.size()==0){
			cout<<"Not Found\n\n";
		}
		else{
			cout<<ans.size()<<endl;
			for(i=0;i<ans.size();i++){
				cout<<ans[i]<<" ";
			}
			cout<<"\n\n";
		}
	}
	return 0;
}