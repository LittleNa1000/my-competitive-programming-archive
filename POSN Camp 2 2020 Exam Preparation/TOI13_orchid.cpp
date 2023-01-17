//				14/8/2563
#include<bits/stdc++.h>
using namespace std;
int n,x,ub;
vector<int> v;
main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&x);
		if(i==0){
			v.push_back(x);
		}
		else{
			ub=upper_bound(v.begin(),v.end(),x)-v.begin();
			if(ub==v.size()){
				v.push_back(x);
			}
			else{
				v[ub]=x;
			}
		}
	}
	//for(int i=0;i<v.size();++i) printf("%d ",v[i]);
	printf("%d",n-v.size());
}
