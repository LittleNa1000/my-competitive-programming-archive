//				28/3/2563
#include<bits/stdc++.h>
using namespace std;
int n,start,height,finish,a=INT_MAX,b,ch;
int gap[100005];
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d %d",&start,&height,&finish);
		if(start<a) a=start;
		if(finish>b) b=finish;
		for(int j=start;j<finish;j++){
			if(gap[j]<height) gap[j]=height;
		}
	}
	for(int i=a;i<=b;i++){
		if(i==a) {
			printf("%d %d ",i,gap[i]);
			ch=gap[i];	
		}
		else{
			if(gap[i]!=ch){
				printf("%d %d ",i,gap[i]);
				ch=gap[i];
			}
		}
	}
}
