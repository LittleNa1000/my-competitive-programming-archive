//				3/4/2563
#include<bits/stdc++.h>
using namespace std;
int coinchange[500005];
int n,q,coin,x;
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&coin);
		for(int j=1;j<=500000;j++){
			if(i==0) coinchange[j]=10000;
			if(j>=coin){
				coinchange[j]=min(coinchange[j],coinchange[j-coin]+1);
			}
		}
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d",&x);
		printf("%d\n",coinchange[x]);
	}
}
