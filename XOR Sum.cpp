//XOR Sum
//https://icpcarchive.ecs.baylor.edu/index.php?Itemid=8&category=345&option=com_onlinejudge&page=show_problem&problem=2683
#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll pow_2[32];

struct trie{
	trie *edges[2];

	trie()
	{
		edges[0]=edges[1]=NULL;
	}
};

void add_word(trie *vertex,ll no,ll bit)
{
	if(bit!=-1)
	{
		bool k=no&(1<<bit);
		if(vertex->edges[k]==NULL)
		{
			vertex->edges[k]=new trie();
		}
		return add_word(vertex->edges[k],no,bit-1);
	}
	return;
}

ll max_xor(trie *vertex,ll no,ll bit)
{
	if(bit==-1)
	{
		return 0;
	}
	bool k=no&(1<<bit);
	if(vertex->edges[!k]==NULL)
	{
		return max_xor(vertex->edges[k],no,bit-1);
	}
	return pow_2[bit]+max_xor(vertex->edges[!k],no,bit-1);
}

void power_2()
{
	ll i;
	pow_2[0]=1;
	for(i=1;i<32;i++)
	{
		pow_2[i]=2*pow_2[i-1];
	}
}

int main()
{
	power_2();
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		trie *root=new trie();
		ll n,i,j,k;
		scanf("%lld",&n);
		ll curr=0,ans=-1;
		add_word(root,curr,31);
		for(i=0;i<n;i++)
		{
			ll a;
			scanf("%lld",&a);
			curr=curr^a;
			add_word(root,curr,31);
			ans=max(ans,max_xor(root,curr,31));
		}
		printf("%lld\n",ans);
	}
	return 0;
}