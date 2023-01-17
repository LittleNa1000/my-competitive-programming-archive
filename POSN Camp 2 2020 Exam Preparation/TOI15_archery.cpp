//				5/6/2563
#include<bits/stdc++.h>
using namespace std;
int ans_pos,n,hmin=INT_MAX;
long long int ans=LONG_LONG_MAX,x;
int h[500005],p[500005];
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&h[i]);
		hmin=min(h[i],hmin);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&p[i]);
	}
	for(int i=1;i<=hmin;i++){
		x=0;
		for(int j=0;j<n;j++){
			x+=((h[j]+p[j]-i)%h[j]);
		}
		if(x<ans){
			ans=x;
			ans_pos=i;
		}
	}
	printf("%d %lld",ans_pos,ans);
}
