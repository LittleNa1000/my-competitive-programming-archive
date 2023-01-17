#include<bits/stdc++.h>
using namespace std;
pair<char,int> tree[1200005],ans;
int n,q,a,b;
string str;
pair<char,int> traverse(int l,int r,int idx){
	if(a<=l&&b>=r){
		return tree[idx];
	}
	if(l>b||r<a){
		return {'a',0};
	}
	int m=(l+r)/2;
	pair<char,int> x=traverse(l,m,(idx*2)+1),y=traverse(m+1,r,(idx*2)+2);
	if(x.first>y.first){
		return x;
	}
	else if(x.first==y.first){
		return {x.first,x.second+y.second};
	}
	else return y;
}
void constructtree(int l,int r,int idx){
	if(l==r){
		tree[idx]=make_pair(str[l],1);
		return ;
	}
	int m=(l+r)/2;
	constructtree(l,m,(idx*2)+1);
	constructtree(m+1,r,(idx*2)+2);
	if(tree[(idx*2)+1].first<tree[(idx*2)+2].first){
		tree[idx]=tree[(idx*2)+2];
	}
	else if(tree[(idx*2)+1].first==tree[(idx*2)+2].first){
		tree[idx]=make_pair(tree[(idx*2)+2].first,tree[(idx*2)+2].second+tree[(idx*2)+1].second);
	}
	else{
		tree[idx]=tree[(idx*2)+1];
	}
}
int main(){
	scanf("%d",&n);
	cin>>str;
	for(int i=0;i<n;++i){
		if(str[i]>='A'&&str[i]<='Z') str[i]+=32;
	}
	//cout<<str<<'\n';
	constructtree(0,n-1,0);
	//for(int i=0;i<4*n;++i){printf("%d %c %d\n",i,tree[i].first,tree[i].second);}
	scanf("%d",&q);
	for(int i=0;i<q;++i){
		scanf("%d %d",&a,&b);
		ans=traverse(0,n-1,0);
		printf("%d\n",ans.second);
	}
}
