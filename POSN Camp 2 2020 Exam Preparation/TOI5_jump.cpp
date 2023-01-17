//				31/3/2563 Last Edited: 16/4/2563
#include<bits/stdc++.h>
using namespace std;
unsigned short int cmp,ans,n,k,temp,lj;
vector<unsigned short int> v;
main(){
	scanf("%hu %hu",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%hu",&temp);
		v.push_back(temp);
		while(v[0]+k<=temp||(i+1==n&&v.size()>1)){
			cmp=upper_bound(v.begin(),v.end(),v[0]+k)-v.begin();
			//printf("cmp=%u v[0]=%u\n",cmp,v[0]);
			cmp=cmp-1;
			if(ans<cmp) ans=cmp;
			v.erase(v.begin());
		}
	}
	/*for(int i=0;i<v.size();i++){
		cmp=upper_bound(v.begin(),v.end(),v[i]+k)-v.begin();
		//printf("cmp=%d v[cmp]=%d\n",cmp,v[cmp]);
		cmp=cmp-i-1;
		//printf("Distance = %d\n",cmp);
		if(ans<cmp) ans=cmp;
	}*/
	printf("%hu",ans);
}
