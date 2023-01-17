//				11/4/2563
#include<bits/stdc++.h>
using namespace std;
int n,m,temp,idx;
vector<int> v;
main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		v.push_back(temp);
	}
	for(int i=0;i<m;i++){
		scanf("%d",&temp);
		idx=upper_bound(v.begin(),v.end(),temp)-v.begin();
		if(!idx) printf("-1\n");
		else printf("%d\n",v[idx-1]);
	}
}
