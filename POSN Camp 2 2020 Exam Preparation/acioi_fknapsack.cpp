//				26/3/2563			Last Edited: 16/4/2563
#include<bits/stdc++.h>
using namespace std;
multiset< pair<long double,long double> > s;
//set< pair<float,float> >::iterator it;
pair<long double,long double> p;
int n;
long double W,v[100005],ans,w;
main(){
	scanf("%Lf %d",&W,&n);
	for(int i=0;i<n;i++){
		scanf("%Lf",&v[i]);
		//printf("Input v[%d] = %f into array\n",i,v[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%Lf",&w);
		//printf("Insert (%f,%f) into set\n",v[i]/w,w);
		s.insert(make_pair(v[i]/w,w));
	}
	p=*--s.end();
	while(p.second<=W&&!s.empty()){
		//printf("%f %f",p.second,p.first);
		ans+=(p.second)*(p.first);
		W-=p.second;
		s.erase(--s.end());
		if(!s.empty()) p=*--s.end();
	}
	if(!s.empty()){
		p=*--s.end();
		ans+=(p.first)*W;
	}
	printf("%.4Lf",ans);
}
