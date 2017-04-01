#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll arr[100005];

struct segtree{
	ll max_count,prefix_max_count,suffix_max_count,start,end;

	void assign_leaf(ll value)
	{
		max_count=prefix_max_count=suffix_max_count=1;
	}

	void merge(segtree& left ,segtree& right)
	{
		if(arr[left.start]==arr[left.end] && arr[left.end]==arr[right.start])
		{
			prefix_max_count=(left.end-left.start+1)+right.prefix_max_count;
		}
		else
		{
			prefix_max_count=left.prefix_max_count;
		}
		if(arr[right.start]==arr[right.end] && arr[left.end]==arr[right.start])
		{
			suffix_max_count=left.suffix_max_count+(right.end-right.start+1);
			/*if(start==1 && end==2)
			{
				cout<<"Index is 8\n";
				cout<<left.suffix_max_count<<" "<<(right.end-right.start+1)<<endl;
			}*/
		}
		else
		{
			suffix_max_count=right.suffix_max_count;
		}
		max_count=max(prefix_max_count,suffix_max_count);
		max_count=max(left.max_count,max(right.max_count,max_count));
		if(arr[left.end]==arr[right.start])
		{
			max_count=max(max_count,left.suffix_max_count+right.prefix_max_count);
		}
	}

	ll get_value()
	{
		return max_count;
	}

};

segtree nodes[300005];

segtree get_value(ll st_index,ll left,ll right)
{
	ll node_start=nodes[st_index].start,node_end=nodes[st_index].end;

	if(node_start==left && node_end==right)
	{
		return nodes[st_index];
	}

	ll mid=(node_start+node_end)>>1,left_child=st_index<<1,right_child=left_child+1;

	if(left>mid)
	{
		return get_value(right_child,left,right);
	}

	if(right<=mid)
	{
		return get_value(left_child,left,right);
	}

	segtree left_child_result,right_child_result,result;

	left_child_result=get_value(left_child,left,mid);
	right_child_result=get_value(right_child,mid+1,right);

	result.start=left_child_result.start;result.end=right_child_result.end;
	result.merge(left_child_result,right_child_result);
	
	return result;
}

void query_tree(ll l,ll r)
{
	segtree result=get_value(1,l,r);
	printf("%lld\n",result.get_value());
}

void build_tree(ll st_index,ll left,ll right)
{
	nodes[st_index].start=left;
	nodes[st_index].end=right;

	if(left==right)
	{
		nodes[st_index].assign_leaf(arr[left]);
		return;
	}

	ll mid=(left+right)>>1,left_child=st_index<<1,right_child=left_child+1;

	build_tree(left_child,left,mid);
	build_tree(right_child,mid+1,right);

	/*if(st_index==8)
		cout<<"MERGING FOR  8\n";*/
	nodes[st_index].merge(nodes[left_child],nodes[right_child]);

}

int main()
{
	ll n;
	while(scanf("%lld",&n))
	{
		if(n==0)
			break;
		/*cout<<"INSIDE\n";
		cout<<"N is "<<n<<endl;*/
		ll i,j,k;
		ll q;
		scanf("%lld",&q);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&arr[i]);
		}
		build_tree(1,1,n);
		/*for(i=1;i<32;i++)
		{
			cout<<"Index is "<<i<<" "<<nodes[i].max_count<<" "<<nodes[i].prefix_max_count<<" "<<nodes[i].suffix_max_count<<endl;
		}
		cout<<endl;*/
		while(q--)
		{
			ll l,r;
			scanf("%lld%lld",&l,&r);
			query_tree(l,r);
		}
		//cout<<"OUTSIDE\n";
	}
	//cout<<"OUTSIDE\n";
	return 0;
}