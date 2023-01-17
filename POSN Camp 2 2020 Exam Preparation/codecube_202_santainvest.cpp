//				14/8/2563 maybe money just only for profit
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int> > pipii;
priority_queue<pipii> pq;
int n,ans,month,stock,money;
int price[1000005];
int dp[1005]; //maybe [1000005] or save the month that this data recorded
main(){
	scanf("%d",&n);
	for(int i=1;i<=1000;++i){
		dp[i]=INT_MIN; // money [stock]
	}
	for(int i=0;i<n;++i){
		scanf("%d",&price[i]);
	}
	pq.push({0,{0,0}}); // money, stock, month - max pq
	while(!pq.empty()){
		money=pq.top().first;   stock=pq.top().second.first;   month=pq.top().second.second;
		pq.pop();
		printf("{%d,{%d,%d}} \n",money,stock,month);
		if(month==n){
			if(stock!=0) money+=price[month-1];
			//printf("Finish: %d\n",money);
			ans=max(ans,money);
		}
		else if(stock==0){
			//printf("Buy & nothing \n");
			//if(money-price[month]>=dp[price[month]]){ //maybe >
				dp[price[month]]=money-price[month];
				pq.push({money-price[month],{price[month],month+1}});	
			//}
			//if(0>=dp[0]){
				pq.push({0,{0,month+1}});
				dp[0]=0;
			//}
		}
		else if(stock!=0&&stock<price[month]){ //maybe <=
			//printf("SEll & nothing \n");
			//if(money+price[month]>=dp[0]){
				dp[0]=money+price[month];
				pq.push({money+price[month],{0,month+1}});
			//}
			//if(money>=dp[stock]){
				dp[stock]=money;
				pq.push({money,{stock,month+1}});
			//}
		}
	}
	printf("%d",ans);
}
