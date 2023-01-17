//				1/4/2563
#include<bits/stdc++.h>
using namespace std;
long long box,m,n,ans=1;
int t[1000005],labor[1000005];
main(){
	scanf("%lld %lld",&m,&n);
	for(int i=0;i<m;i++){
		scanf("%d",&labor[i]);
	}
	while(box<n){
		ans++;
		for(int i=0;i<m;i++){
			t[i]++;
			if(t[i]==labor[i]){
				//printf("Found. t[%d]=%d ans=%d\n",i,t[i],ans);
				t[i]=0;
				box++;
			}
		}
	}
	printf("%lld",ans-1);
}
