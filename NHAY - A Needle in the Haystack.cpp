//NHAY - A Needle in the Haystack
//http://www.spoj.com/problems/NHAY/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	ll no,i,j,k;
	while(cin>>no){
		string haystack,needle;
		cin>>needle>>haystack;
		ll n=haystack.size(),m=needle.size(),lps[m]={};
		i=1; j=0;
		while(i<m){
			if(needle[i]==needle[j]){
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
		i=0;j=0;
		ll count=0;
		while(i<n){
			if(haystack[i]==needle[j]){
				i++; j++;
				if(j==m){
					count++;
					cout<<ll(i-m)<<"\n";
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
		if(count==0){
			cout<<"\n";
		}
	}
	return 0;
}