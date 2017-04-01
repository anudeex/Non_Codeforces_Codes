#include <bits/stdc++.h>

#define ll long long

using namespace std;

struct segtree{

	ll sum=0,sum_squares=0,pending_update=0,x=0,start,end;

	void assign_leaf(ll value)
	{
		sum=value;
		sum_squares=sum*sum;
	}

	void merge(segtree& left,segtree& right)
	{
		ll left_pending=left.pending_update,right_pending=right.pending_update;
		if(left_pending==0)
		{
			sum=left.sum;
			sum_squares=left.sum_squares;
		}
		else if(left_pending==1)
		{
			sum=left.sum+(left.end-left.start+1)*(left.x);
			sum_squares=left.sum_squares+(left.end-left.start+1)*(left.x*left.x)+(left.end-left.start+1)*(left.x*left.sum);
		}
		else 
		{
			sum+=(left.end-left.start+1)*left.x;
			sum_squares+=(left.end-left.start+1)*left.x*left.x;
		}
		if(right_pending==0)
		{
			sum+=right.sum;
			sum_squares+=right.sum_squares;
		}
		else if(right_pending==1)
		{
			//cout<<"HERE\n\n";
			sum+=right.sum+(right.end-right.start+1)*(right.x);
			sum_squares+=right.sum_squares+(right.end-right.start+1)*(right.x*right.x)+(right.end-right.start+1)*(right.x*right.sum);
		}
		else 
		{
			//cout<<"HERE\n\n";
			cout<<(right.end-right.start+1)*right.x<<" "<<(right.end-right.start+1)*right.x*right.x<<endl;
			sum+=(right.end-right.start+1)*right.x;
			sum_squares+=(right.end-right.start+1)*right.x*right.x;
		}
	}

	ll get_value()
	{
		return sum_squares;
	}

	bool is_there_pending_update()
	{
		return pending_update!=0;
	}

	ll add_update(ll value,ll type)
	{
		//cout<<"Value and Type is "<<value<<" "<<type<<endl;
		if(pending_update==0)
		{
			pending_update=type;
			x=value;
		}
		else if(pending_update==1)
		{
			if(type==1)
			{
				x+=value;
			}
			else 
			{
				pending_update=2;
				x=value;
			}
		}
		else
		{
			if(type==1)
			{
				x+=value;
			}
			else
			{
				x=value;
			}
		}
	}

	void apply_pending_update()
	{
		if(pending_update==1)
		{
			sum_squares+=((2*(end-start+1)*sum*x)+((end-start+1)*x*x));
			sum+=(end-start+1)*x;
		}
		else if(pending_update==2)
		{
			sum_squares=(end-start+1)*x*x;
			sum=(end-start+1)*x;
		}
		pending_update=0;
	}

	ll get_pending_update()
	{
		return pending_update;
	}

	ll get_value_x()
	{
		return x;
	}

};

segtree nodes[1000005];

ll arr[5000005];

void update(ll st_index,ll l,ll r,ll value,ll type)
{
	//cout<<"Value and Type is "<<value<<" "<<type<<endl;
	ll node_end=nodes[st_index].end,node_start=nodes[st_index].start;
	if(node_start==l && node_end==r)
	{
		//cout<<"Got Adding Update\n";
		nodes[st_index].add_update(value,type);
		return ;
	}

	ll mid=(node_start+node_end)>>1,left_child_index=st_index<<1,right_child_index=left_child_index+1;

	if(l>mid)
	{
		update(right_child_index,l,r,value,type);
	}
	else if(r<=mid)
	{
		update(left_child_index,l,r,value,type);
	}
	else
	{
		update(left_child_index,l,mid,value,type);
		update(right_child_index,mid+1,r,value,type);
	}

	nodes[st_index].merge(nodes[left_child_index],nodes[right_child_index]);

}

void update_tree(ll l,ll r,ll value,ll type)
{
	//cout<<"Value and Type is "<<value<<" "<<type<<endl;
	update(1,l,r,value,type);
}

segtree query(ll st_index,ll l,ll r)
{
	ll node_end=nodes[st_index].end,node_start=nodes[st_index].start;
	if(node_start==l && node_end==r)
	{
		segtree result=nodes[st_index];

		if(result.is_there_pending_update())
		{
			result.apply_pending_update();
		}

		return result;
	}

	segtree result;

	ll mid=(node_start+node_end)>>1,left_child_index=st_index<<1,right_child_index=left_child_index+1;

	if(l>mid)
	{
		result=query(right_child_index,l,r);
	}
	else if(r<=mid)
	{
		result=query(left_child_index,l,r);
	}
	else
	{
		segtree left_child=query(left_child_index,l,mid),right_child=query(right_child_index,mid+1,r);

		result.start=left_child.start;result.end=right_child.end;
		result.merge(left_child,right_child);
	}

	if(nodes[st_index].is_there_pending_update())
	{
		result.add_update(nodes[st_index].get_value_x(),nodes[st_index].get_pending_update());
		result.apply_pending_update();
	}

	return result;
}

void query_tree(ll l,ll r)
{
	segtree result=query(1,l,r);
	printf("%lld\n",result.get_value());
}

void build_tree(ll st_index,ll l,ll r)
{
	nodes[st_index].start=l;
	nodes[st_index].end=r;
	if(l==r)
	{
		nodes[st_index].assign_leaf(arr[l]);
		return ;
	}

	ll mid=(l+r)>>1,left_child_index=st_index<<1,right_child_index=left_child_index+1;

	build_tree(left_child_index,l,mid);
	build_tree(right_child_index,mid+1,r);

	nodes[st_index].merge(nodes[left_child_index],nodes[right_child_index]);

}


int main()
{
	ll t;
	scanf("%lld",&t);
	for(int l=1;l<=t;l++)
	{
		ll n,q,i,j,k;
		scanf("%lld%lld",&n,&q);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&arr[i]);
		}
		build_tree(1,1,n);
		/*cout<<"AFTER BUILD\n";
		for(i=1;i<8;i++)
		{
			cout<<"Index "<<i<<endl<<"Sum "<<nodes[i].sum<<endl<<"Squares "<<nodes[i].sum_squares<<endl<<"X "<<nodes[i].x<<endl;
		}*/
		printf("Case %d:\n",l);
		while(q--)
		{
			ll a,b,c;
			scanf("%lld%lld%lld",&a,&b,&c);
			if(a==0)
			{
				ll d;
				scanf("%lld",&d);
				update_tree(b,c,d,2);
				/*cout<<"\nDetails\n";
				for(i=1;i<8;i++)
				{
					cout<<"Index "<<i<<" Sum "<<nodes[i].sum<<" Squares "<<nodes[i].sum_squares<<" X "<<nodes[i].x<<" Pending Update "<<nodes[i].pending_update<<endl;
				}*/
			}
			else if(a==1)
			{
				ll d;
				scanf("%lld",&d);
				update_tree(b,c,d,1);
				/*for(i=1;i<8;i++)
				{
					cout<<"Index "<<i<<endl<<"Sum "<<nodes[i].sum<<endl<<"Squares "<<nodes[i].sum_squares<<endl<<"X "<<nodes[i].x<<endl;
				}*/
			}
			else
			{
				query_tree(b,c);
			}
		}
	}
	return 0;
} 