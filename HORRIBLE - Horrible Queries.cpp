#include <bits/stdc++.h>

#define ll long long

using namespace std;

struct segtree{
	ll start,end,pending_update=0,total=0;

	void assign_leaf(ll value)
	{
		total=value;
		pending_update=0;
	}

	void merge(segtree& left,segtree& right)
	{
		total=left.total+right.total;
		if(left.pending_update>0)
		{
			//cout<<"HERE\n";
			total+=(left.end-left.start+1)*left.pending_update;
		}
		if(right.pending_update>0)
		{
			//cout<<"HERE\n";
			total+=(right.end-right.start+1)*right.pending_update;
		}
	}

	ll get_value()
	{
		return total;
	}

	ll get_pending_update()
	{
		return pending_update;
	}

	bool is_there_pending_update()
	{
		return pending_update!=0;
	}

	void add_update(ll value)
	{
		pending_update+=value;
	}

	void apply_pending_update()
	{
		total+=(end-start+1)*pending_update;
		pending_update=0;
	}

};

ll arr[100005];
segtree nodes[300005];

void update(ll st_index,ll start,ll end,ll value)
{
	ll node_start=nodes[st_index].start,node_end=nodes[st_index].end;
	if(node_start==start && node_end==end)
	{
		cout<<"HERE UPDATE "<<st_index<<endl;
		nodes[st_index].add_update(value);
		return ;
	}
	ll mid=(node_end+node_start)>>1,left_child=st_index<<1,right_child=left_child+1;
	if(start>mid)
	{
		update(right_child,start,end,value);
	}
	else if(end<=mid)
	{
		update(left_child,start,end,value);
	}
	else
	{
		update(left_child,start,mid,value);
		update(right_child,mid+1,end,value);
	}
	nodes[st_index].merge(nodes[left_child],nodes[right_child]);
}

void update_tree(ll l,ll r,ll value)
{
	update(1,l,r,value);
}

segtree get_value(ll st_index,ll start,ll end)
{
	ll node_start=nodes[st_index].start,node_end=nodes[st_index].end;
	if(node_start==start && node_end==end)
	{
		cout<<"HERE \n";
		segtree result=nodes[st_index];
		if(result.is_there_pending_update())
		{
			cout<<"INSIDE \n";
			result.apply_pending_update();
		}
		return result;
	}
	ll mid=(node_end+node_start)>>1,left_child=st_index<<1,right_child=left_child+1;
	segtree result;
	if(start>mid)
	{
		result=get_value(right_child,start,end);
	}
	else if(end<=mid)
	{
		result=get_value(left_child,start,end);
	}
	else
	{
		segtree left_child_result=get_value(left_child,start,mid);
		segtree right_child_result=get_value(right_child,mid+1,end);
		result.start=left_child_result.start;result.end=right_child_result.end;
		result.merge(left_child_result,right_child_result);
	}
	if(nodes[st_index].is_there_pending_update())
	{
		result.add_update(nodes[st_index].get_pending_update());
		result.apply_pending_update();
	}
	return result;
}

void query_tree(ll l,ll r)
{
	segtree result=get_value(1,l,r);
	printf("%lld\n",result.get_value());
}

void build_tree(ll st_index,ll start,ll end)
{
	//cout<<"Index is "<<st_index<<" start and end is "<<start<<" "<<end<<endl;
	ll i;
	/*for(i=1;i<=200005;i++)
	{
		nodes[i].total=0;
		nodes[i].pending_update=0;
	}*/
	nodes[st_index].start=start;
	nodes[st_index].end=end;

	if(start==end)
	{
		nodes[st_index].assign_leaf(arr[start]);
		/*cout<<"Leaf "<<nodes[st_index].total<<endl;
		cout<<"Pending "<<nodes[st_index].pending_update<<endl;*/
		return;
	}

	ll mid=(start+end)>>1,left_child=st_index<<1,right_child=left_child+1;
	build_tree(left_child,start,mid);
	build_tree(right_child,mid+1,end);
	nodes[left_child].pending_update=0;nodes[right_child].pending_update=0;
	nodes[st_index].merge(nodes[left_child],nodes[right_child]);
}

int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		ll n,m,i,j,k;
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			arr[i]=0;
			//cout<<"Arr["<<i<<"] is "<<arr[i]<<endl;
		}
		build_tree(1,1,n);
		while(m--)
		{
			ll a;
			scanf("%lld",&a);
			if(a==0)
			{
				ll b,c,d;
				scanf("%lld%lld%lld",&b,&c,&d);
				//cout<<"BEFORE\n";
				/*for(i=1;i<=15;i++)
				{
					cout<<nodes[i].total<<" ";
				}
				cout<<endl;*/
				update_tree(b,c,d);
				/*cout<<"AFTER\n";
				for(i=1;i<=15;i++)
				{
					cout<<nodes[i].total<<" ";
				}
				cout<<endl;*/
			}
			else
			{
				ll b,c;
				scanf("%lld%lld",&b,&c);
				query_tree(b,c);
			}
		}
	}
	return 0;
}