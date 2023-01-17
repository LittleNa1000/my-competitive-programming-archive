//				5/5/2563 LAST EDITED: 21/6/2563 BEST TIMING => SUBMISSION #1698
#include<bits/stdc++.h>
using namespace std;
int previous=-1,t,n,k,sz,x,y,z,pr;
vector<int> v;
main(){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;++i){
		scanf("%d",&x);
		//printf("%d %d %d\n",x,y,z);
		if(y>z&&y>x) v.push_back(y);
		if(i+1==n&&x>y) v.push_back(x);
		z=y;
		y=x;
	}
	if(v.empty()) printf("-1");
	else{
		sort(v.begin(),v.end());
		sz=v.size();
		if(sz<k){
			for(int i=0;i<sz;++i){
				if(v[i]!=previous){
					printf("%d\n",v[i]);
					previous=v[i];
				}
			}
		}
		else{
			for(int i=0;i<v.size();++i){
				if(v[i]==previous) --sz;
				previous=v[i];
			}
			previous=-1;
			if(sz<k){
				for(int i=0;pr<sz;++i){
					if(v[i]!=previous){
						++pr;
						printf("%d\n",v[i]);
						previous=v[i];
					}
				}
			}
			else{
				for(int i=v.size()-1;pr<k;--i){
					if(v[i]!=previous){
						++pr;
						printf("%d\n",v[i]);
						previous=v[i];
					}
				}
			}
		}
		
	}
}
