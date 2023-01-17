//				19/6/2563
#include<bits/stdc++.h>
using namespace std;
int n,k,mn,ttc,ptr,newptr;
int cost[500005],ans[500005];
main(){
	scanf("%d %d",&n,&k);//if k==1 total cost
	for(int i=0;i<n;i++){
		scanf("%d",&cost[i]);
		ttc+=cost[i];
	}
	if(k==1) printf("%d",ttc);
	else{
		ans[0]=cost[0];
		while(ans[n-1]==0){
			mn=INT_MAX;
			for(int i=ptr+1,r=0;r<k&&i<n;++i,++r){
				if(ans[i]==0){
					ans[i]=ans[ptr]+cost[i];
				}
				if(mn>=ans[i]){
					mn=ans[i];
					newptr=i;
				}
			}
			ptr=newptr;
		}
		printf("%d",ans[n-1]);
	}
}
