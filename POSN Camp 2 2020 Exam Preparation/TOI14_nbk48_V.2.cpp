//				14/6/2563
#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int n,m,temp,x;
main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		if(i==0) v.push_back(temp);
		else v.push_back(v[i-1]+temp);
	}
	while(m--){
		scanf("%d",&x);
		printf("%d\n",upper_bound(v.begin(),v.end(),x)-v.begin());
	}
}
