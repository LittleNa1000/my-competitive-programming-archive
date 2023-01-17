//			20/3/2020
#include<bits/stdc++.h>
using namespace std; //			x[3]
int n,maxW,temp1,temp2,sum_W;
long long sum_V,maxV;
vector<int> v,w;
main(){
	
	scanf("%d %d",&n,&maxW);
	for(int i=0;i<n;i++){
		scanf("%d %d",&temp1,&temp2);
		w.push_back(temp1);
		v.push_back(temp2);
	}
	for(int i=1;i<pow(2,n);i++){
		sum_W=0;
		sum_V=0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				if(sum_W+w[j]>maxW) break;
				else{
					sum_W+=w[j];
					sum_V+=v[j];
				}
			}
		}
		if(maxV<sum_V) maxV=sum_V;
	}
	printf("%lld",maxV);
}
