//				29/8/2563 maybe add stock to money when calculate ans OR lis
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int> > piii;
int n,ans,price[1000005],money,stock,idx;
priority_queue<piii> pq;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&price[i]);
	}
	pq.push({0,{0,0}});//currency, {stockvalue,index} max pq
	while(!pq.empty()){
		money=pq.top().first;    stock=pq.top().second.first;    idx=pq.top().second.second;
		pq.pop();
		//printf("Index=%d Money=%d Stock=%d\n",idx,money,stock);
		if(idx==n){
			ans=max(ans,money);
		}
		else{
			if(stock==0&&idx!=n-1){
				pq.push({money-price[idx],{price[idx],idx+1}});
			}
			else if(stock>0&&price[idx]>stock){
				pq.push({money+price[idx],{0,idx+1}});
			}
			pq.push({money,{stock,idx+1}});
		}
	}
	printf("%d",ans);
}
