//				17/6/2563
#include<bits/stdc++.h>
using namespace std;
int n,x,posA[300005],temp,ans,ub;
vector<int> v;
main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		posA[x]=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		temp=posA[x];
		//printf("%d ",temp);
		if(i==1){
			v.push_back(temp);
			ans++;
		}
		else{
			ub=lower_bound(v.begin(),v.end(),temp)-v.begin();
			if(ub==v.size()){
				v.push_back(temp);
				ans++;
			}
			else if(v[ub]!=temp){
				v[ub]=temp;
			}
		}
	}
	printf("%d",ans);
	//for(int i=0;i<v.size();i++) printf("%d ",v[i]);
}
