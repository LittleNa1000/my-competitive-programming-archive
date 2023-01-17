//				19/9/2563
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli n,tem,minh=LONG_LONG_MAX,ans=LONG_LONG_MAX,m,x,lb,sumhole;
lli sumh[500005];
vector< pair<lli,lli> > box;
main(){
	scanf("%lld",&n);
	for(int i=0;i<n;++i){// Height
		scanf("%lld",&tem);
		box.push_back({0,tem});
		minh=min(minh,tem);
	}
	for(int i=0;i<n;++i){// Hole
		scanf("%lld",&tem);
		sumhole+=tem;
		box[i].first=tem;
	}
	sort(box.begin(),box.end()); // {Hole,Height}
	for(int i=0;i<n;++i){
		//v.push_back(box[i].first);
		sumh[i+1]=sumh[i]+box[i].second;
		//printf("(%d,%d) sumh %d sumhole %d\n",box[i].first,box[i].second,sumh[i+1],sumhole[i+1]);
	}
	for(int i=box[0].first;i<=box[n-1].first;++i){
		while(lb<n&&box[lb].first<i) ++lb;
		//l=sumh[lb]+sumhole[lb]-(i*(lb));
		//r=sumhole[n]-sumhole[lb]-(i*(n-lb));
		m=sumh[lb]+sumhole-(i*n);
		//printf("%d %lld\n",lb,l+r);
		if(m<ans){
			ans=m;
			x=i;
		}
	}
	printf("%lld %lld",x,ans);
}