//				2/4/2563
#include<bits/stdc++.h>
using namespace std;
vector<bool> upper(500005,0),lower(500005,0); //size=500005
int n,x,q,target;
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		for(int j=0;j<=500000;j++){
			if(j==0) lower[j]=1;
			else if(i==0&&x==j) lower[j]=1;
			else if(i==0&&x!=j) lower[j]=0;
			else if(j<x) lower[j]=upper[j];
			else lower[j]= upper[j]||upper[j-x] ;
		}
		upper=lower;
		//lower.clear();
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d",&target);
		if(upper[target]) printf("YES\n");
		else printf("NO\n");
	}
}
