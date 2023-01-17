//				8/8/2563
#include<bits/stdc++.h>
using namespace std;
int l,r,m,n,d,gap,temp,c,ans,ansm;
vector<int> v;
main(){
	scanf("%d %d",&n,&d);
	for(int i=0;i<n;++i){
		scanf("%d",&temp);
		v.push_back(temp);
		if(i>0) gap=max(gap,v[i]-v[i-1]);
	}
	l=max(gap,(int)ceil(float(v[n-1]/d)));
	r=v[n-1];
	while(l<=r){
		m=(l+r)/2;
		c=0;
		for(int i=0;i<v[n-1];++c){
			i=v[upper_bound(v.begin(),v.end(),i+m)-v.begin()-1];
			//printf("%d\n",i);
		}
		//printf("%d\n",c);
		if(c<=d){
			if(ans<=c){
				ans=c;
				ansm=m;
			}
			r=m-1;
		}
		else{
			l=m+1;
		}
	}
	printf("%d %d",ansm,ans);
}
