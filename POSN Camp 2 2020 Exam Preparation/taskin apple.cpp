//			20/3/2020
#include<bits/stdc++.h>
using namespace std;
long long testcase(){
	int n,temp;
	long long subset_sum,maxW,closest=0;
	vector<int> v;
	scanf("%d %lld",&n,&maxW);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		v.push_back(temp);
	}
	for(long long i=1;i<pow(2,n);i++){
		subset_sum=0;
		for(int j=0;j<n;j++){ 
			if(i&(1<<j)){
				subset_sum+=v[j];
			}
		}
		if(subset_sum==maxW) return maxW;
		if(subset_sum>closest&&subset_sum<maxW) closest=subset_sum;
	}
	return closest;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		printf("%lld\n",testcase());
	}
}
