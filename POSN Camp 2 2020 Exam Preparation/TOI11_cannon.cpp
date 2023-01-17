//				7/4/2563
#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int n,m,k,l,a,b,temp,ans;
bool activate[1000005];
void simulate(){
	for(int i=0;i<m;i++){
		scanf("%d",&temp);
		a=lower_bound(v.begin(),v.end(),temp-l)-v.begin();
		b=upper_bound(v.begin(),v.end(),temp+l)-v.begin();
		//printf("#%d %d %d\n",k,a,b);
		for(int i=a;i<b;i++){
			if(!activate[i]){
				activate[i]=1;
				ans++;
			}
		}
	}
	printf("%d\n",ans);
}
main(){
	scanf("%d %d %d %d",&n,&m,&k,&l);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		v.push_back(temp);
	}
	while(k--){
		simulate();
		for(int i=0;i<n;i++){
			activate[i]=0;
		}
		ans=0;
	}
}
