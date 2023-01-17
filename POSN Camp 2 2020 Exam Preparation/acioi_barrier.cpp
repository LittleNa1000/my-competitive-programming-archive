//			18/3/2020
#include<bits/stdc++.h>
using namespace std;
//vector<int> v;
int sum,home[6000010],mx=0,nHome,w,n;
void compare(int sum,int i){
	//printf("\nsum%d	nHome%d\n",sum,i);
	if(sum>mx){
		nHome=i;
		mx=sum;
	}
}
int initial(int k){
	sum=0;
	for(int i=0;i<k;i++){
		sum+=home[i];
	}
	//printf("Initial for %d is %d",k,sum);
	return sum;
}
main(){
	scanf("%d %d",&n,&w);
	for(int i=0;i<n;i++){
		scanf("%d",&home[i]);
		compare(home[i],1);
	}
	for(int i=w;i>1;i--){
		sum=initial(i);
		compare(sum,i);
		for(int j=0;j<n-i;j++){
			sum+=home[i+j]-home[j];
			compare(sum,i);
		}
	}
	if(mx>0){
		printf("%d\n%d",mx,nHome);
	}
	else printf("0\n0");
}
