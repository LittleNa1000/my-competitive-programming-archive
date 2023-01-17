//				24/6/2563
#include<bits/stdc++.h>
using namespace std;
long long int n,k,minlabor=INT_MAX;
long long int labor[1000005];
long long int ans,l,r,mid,sum;
main(){
	scanf("%lld %lld",&n,&k);
	for(int i=0;i<n;++i){
		scanf("%lld",&labor[i]);
		minlabor=min(minlabor,labor[i]);
	}
	ans=minlabor*k;
	r=ans; // maybe recursive
	while(l<=r){
		mid=(l+r)/2;
		sum=0;
		for(int i=0;i<n;++i){
			sum+=(mid/labor[i]);
		}
		if(sum>=k){
			ans=min(ans,mid);
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	printf("%lld",ans);
}
