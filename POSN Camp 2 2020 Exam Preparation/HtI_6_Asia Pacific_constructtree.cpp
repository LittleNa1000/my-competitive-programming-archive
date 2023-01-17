//				8/8/2563
#include<bits/stdc++.h>
using namespace std;
int tc;
long long int n,x;
int main(){
	scanf("%d",&tc);
	while(tc--){
		cin>>n>>x;
		--n;
		//check condition
		if((x<n||x>(n*(n+1))/2)){
			printf("-1 -1\n");
		}
		else{
			x-=n;
			for(long long int i=1;i<=n;++i){
				if(x<=0) printf("%lld %lld\n",i+1,1);
				else if(x<i) printf("%lld %lld\n",i+1,x+1);
				else printf("%lld %lld\n",i+1,i); //max((long long int)1,min(i,x))
				x-=i-1;
			}
		}
	}
}
