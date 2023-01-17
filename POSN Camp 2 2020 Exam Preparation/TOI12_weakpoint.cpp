//				7/4/2563 FAILED
#include<bits/stdc++.h>
using namespace std;
vector<int> edge[500000],vip;
int n,source,temp,temp1,x,a,mx,wmx;
int weight[500000];
bool is_vip[500000],r;
stack<int> st;
void dfs(int root,int pre){
	for(int i=0;i<edge[root].size();i++){
		if(edge[root][i]!=source&&(!r||!is_vip[edge[root][i]])){
			a=0;
			if(edge[root][i]!=pre){
				dfs(edge[root][i],root);
				if(a){
					is_vip[root]=1;
					vip.push_back(root);
					return ;
				}
				else{
					printf("Node #%d Previous=%d edge[root][i]=%d wBefore->%d wNow->%d wmx=%d\n",root,pre,edge[root][i],weight[root],weight[root]+weight[edge[root][i]]+1,wmx);
					weight[root]+=weight[edge[root][i]]+1;
					if(wmx<weight[root]){
						mx=root;
						wmx=weight[root];
					}
				}
			}
			else if(edge[root][i]!=pre&&is_vip[edge[root][i]]){
				a=1;
				vip.push_back(root);
				is_vip[root]=1;
				return ;
			}
		}
	}
}
main(){
	scanf("%d %d",&n,&source);
	vip.push_back(source);
	is_vip[source]=1;
	for(int i=0;i<n;i++){
		scanf("%d %d",&temp,&temp1);
		edge[temp].push_back(temp1);
		edge[temp1].push_back(temp);
		if(temp==source){
			vip.push_back(temp1);
			is_vip[temp1]=1;
		}
		if(temp1==source){
			vip.push_back(temp);
			is_vip[temp]=1;
		}
	}
	x=vip.size();
	printf("Round 1\n");
	for(int i=0;i<x;i++){
		dfs(vip[i],-1);
	}
	x=vip.size();
	r=1;
	printf("Round 2\n");
	for(int i=0;i<x;i++){
		a=0;
		if(!weight[vip[i]]) dfs(vip[i],-1);
	}
	printf("%d\n%d",mx,wmx);
}
