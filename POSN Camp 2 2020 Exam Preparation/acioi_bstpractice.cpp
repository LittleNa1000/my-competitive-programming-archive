//			23/3/2563
#include<bits/stdc++.h>
using namespace std;
int bst[1000000],L[1000000],R[1000000]; //	bst=info
void insert_bst(int x,int y){
	int idx=0;
	while(1){
		if(bst[idx]==0){
			bst[y]=x;
			printf("*\n");
			return ;
		}
		if(bst[idx]>x){
			printf("L");
			if(L[idx]==0) L[idx]=y;
			idx=L[idx];
			
		}
		else if(bst[idx]<x){
			printf("R");
			if(R[idx]==0) R[idx]=y;
			idx=R[idx];
		}
	}
}
main(){
	int n,temp;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		
			insert_bst(temp,i);
	
	}
}
