//				30/8/2563
#include<bits/stdc++.h>
using namespace std;
int n,money,stock;
int price[1000005];
main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&price[i]);
	}
	for(int i=0;i<n;++i){
		if(i==n-1&&stock){
			money+=max(stock,price[i]);
		}
		else if(stock==0){
			if(price[i]<price[i+1]){
				money-=price[i];
				stock=price[i];
				//printf("Buy at %d ($=%d)\n",i,price[i]);
			}
		}
		else{
			if(price[i]>price[i+1]){
				money+=price[i];
				stock=0;
				//printf("Sell at %d ($=%d)\n",i,price[i]);
			}
		}
	}
	printf("%d",money);
}
