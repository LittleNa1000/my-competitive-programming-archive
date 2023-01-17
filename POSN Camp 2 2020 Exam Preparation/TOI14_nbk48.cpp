//				18/5/2563
#include<bits/stdc++.h>
using namespace std;
int n,q,x,temp,arr[100005];
main(){
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		if(i) arr[i]=arr[i-1]+temp;
		else arr[i]=temp; 
	}
	while(q--){
		scanf("%d",&x);
		for(int i=n-1;i>=0;i--){
			if(arr[i]<=x){
				printf("%d\n",i+1);
				break;	
			}
			else if(!i) printf("0\n");
		}
	}
}
