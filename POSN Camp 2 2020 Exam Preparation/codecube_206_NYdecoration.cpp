//				13/8/2563
#include<bits/stdc++.h>
using namespace std;
long long int l=1,n,r,m,ans=LONG_LONG_MAX;
main(){
	scanf("%lld",&n);
	r=(long long int)ceil((double)n/23);
	//printf("%lld\n",r);
	while(l<=r){
		m=l+((r-l)/2); // maybe (l+r)/2
		//printf("(%lld,%lld) %lld\n",l,r,m);
		if(((m*23)+((m/12)*98)>=n)){
			ans=min(ans,m);
			r=m-1;
		}
		else{
			l=m+1;
		}
	}
	printf("%lld",ans*7);
}
